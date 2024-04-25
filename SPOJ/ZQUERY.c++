// https://www.luogu.com.cn/article/kh0v4adt
//
// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18; // 1e9
const int P = 1e9+7; // 998244353;
const double PI = acos(-1.0);

using pi = pair<int,int>;

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;
using vpi = V<pi>;

#define sz(x) ((int)(x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define rep(a) F0R(_,a)

mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;
constexpr int pct(int x) { return __builtin_popcount(x); }
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr int p2(int x) { return 1<<x; }
constexpr int msk2(int x) { return p2(x)-1; }

template<class T> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } // set a = min(a,b)
template<class T> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } // set a = max(a,b)

template<class T, class U> T fstFalse(T lo, T hi, U f) {
    while (lo < hi) {
        T m = (lo+hi)/2;
        f(m) ? lo = m+1 : hi = m;
    }
    return hi;
}

// Fast IO
void setIn(string s)  { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (sz(s) && fopen((s+".in").c_str(), "r")) setIn(s+".in"), setOut(s+".out"); // for old USACO
}

template<class F> struct y_combinator_result {
    F f;
    template<class T> explicit y_combinator_result(T &&f): f(std::forward<T>(f)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return f(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) yy(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

const int max_n = 5e4;
const int K = 300;

struct query {
    int l, r, ind;
    bool operator <(const query& o) const {
        if (l/K == o.l/K) return r < o.r;
        return l/K < o.l/K;
    }
};

void solve() {
    int n, q; cin >> n >> q;
    vi b(n); for (auto&x:b) cin >> x;
    vi p(n+1); partial_sum(all(b), bg(p)+1);
    for (int i = 0; i <= n; i++) p[i] += n;

    V<query> queries;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--; r++;
        queries.pb({l, r, i});
    }
    sort(all(queries));

    multiset<int> lengths;
    V<deque<int>> where(2*n+1);

    vi ans(q);
    int l = 0, r = 0;
    for (auto[L, R, ind] : queries) {
        // adding elements
        while (l > L) {
            l--;
            where[p[l]].push_front(l);
            lengths.insert(where[p[l]].bk - where[p[l]].ft);
        }
        while (r < R) {
            where[p[r]].push_back(r);
            lengths.insert(where[p[r]].bk - where[p[r]].ft);
            r++;
        }
        // deleting elements
        while (l < L) {
            lengths.erase(where[p[l]].bk - where[p[l]].ft);
            where[p[l]].pop_front();
            l++;
        }
        while (r > R) {
            r--;
            lengths.erase(where[p[r]].bk - where[p[l]].ft);
            where[p[r]].pop_back();
        }

        if (!sz(lengths)) ans[ind] = 0;
        else ans[ind] = *rbegin(lengths);
    }
    for (int i = 0; i < q; i++) cout << ans[i] << endl;
}

signed main() {
    setIO();
    
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}
