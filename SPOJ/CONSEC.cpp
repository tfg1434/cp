// DSU - store the next value to the right that is the same letter. Process queries backwards.

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using db = long double; // or double, if TL is tight
using str = string; // yay python! 

// pairs
using pi = pair<int,int>;
using pl = pair<ll,ll>;
using pd = pair<db,db>;
#define mp make_pair
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
// ^ lol this makes everything look weird but I'll try it
tcT> using V = vector<T>; 
tcT, size_t SZ> using AR = array<T,SZ>; 
using vi = V<int>;
using vb = V<bool>;
using vl = V<ll>;
using vd = V<db>;
using vs = V<str>;
using vpi = V<pi>;
using vpl = V<pl>;
using vpd = V<pd>;

// vectors
// oops size(x), rbegin(x), rend(x) need C++17
#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define sor(x) sort(all(x)) 
#define rsz resize
#define ins insert 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

#define lb lower_bound
#define ub upper_bound
tcT> ll lwb(V<T>& a, const T& b) { return ll(lb(all(a),b)-bg(a)); }
tcT> ll upb(V<T>& a, const T& b) { return ll(ub(all(a),b)-bg(a)); }

// loops
#define FOR(i,a,b) for (ll i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define F1R(i,a) FOR(i,1,a+1)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define R1F(i,a) ROF(i,1,a+1)
#define rep(a) F0R(__________,a)
#define each(a,x) for (auto& a: x)

const ll P = 1e9+7; // 998244353;
const ll MX = 2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const ll dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

ll pw(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % P;
        b >>= 1;
        a = a * a % P;
    }

    return res;
}

// bitwise ops
// also see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
constexpr ll pct(ll x) { return __builtin_popcount(x); } // # of bits set
constexpr ll bits(ll x) { // assert(x >= 0); // make C++11 compatible until USACO updates ...
    return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
constexpr ll p2(ll x) { return 1<<x; }
constexpr ll msk2(ll x) { return p2(x)-1; }

ll cdiv(ll a, ll b) { return a/b+((a^b)>0&&a%b); } // divide a by b rounded up
ll fdiv(ll a, ll b) { return a/b-((a^b)<0&&a%b); } // divide a by b rounded down

tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; } // set a = min(a,b)
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; } // set a = max(a,b)
// m is max, M is second max
tcT> T tmax(T x, T& m, T& M) {
    if (x <= m) return ckmax(M, x);
    return ckmax(m, x);
}
tcT> T tmin(T x, T& m, T& M) {
    if (x >= m) return ckmin(M, x);
    return ckmin(m, x);
}

tcTU> T fstTrue(T lo, T hi, U f) {
    ++hi; assert(lo <= hi); // assuming f is increasing
    while (lo < hi) { // find first index such that f is true 
        T mid = lo+(hi-lo)/2;
        f(mid) ? hi = mid : lo = mid+1; 
    } 
    return lo;
}
tcTU> T lstTrue(T lo, T hi, U f) {
    --lo; assert(lo <= hi); // assuming f is decreasing
    while (lo < hi) { // find first index such that f is true 
        T mid = lo+(hi-lo+1)/2;
        f(mid) ? lo = mid : hi = mid-1;
    } 
    return lo;
}
tcT> void UNIQUE(vector<T>& v) { // sort and remove duplicates
    sort(all(v)); v.erase(unique(all(v)),end(v)); }
tcTU> void safeErase(T& t, const U& u) { // don't erase
    auto it = t.find(u); assert(it != end(t));
    t.erase(it); } // element that doesn't exist from (multi)set

// const ll mx_n = 200000;
struct DSU {
    ll n;
    vl e;
    DSU(ll n) : e(n) {
        this->n = n;
        iota(all(e), 0);
    }
    ll find(ll u) {
        return e[u] == u ? u : e[u]=find(e[u]);
    }
    void unite(ll u, ll v) {
        if ((u=find(u)) != (v=find(v))) {
            e[v] = u;
        }
    }
};

struct Query {
    ll t, i, idx;
};

void solve(ll tc) {
    cout << "Case " << tc << ":\n";
    str s; cin >> s;
    ll n = sz(s);
    str S = s;
    ll q; cin >> q;
    V<Query> qs;
    ll idx = -1;
    rep(q) {
        ll t, i; cin >> t >> i;
        if (t == 1) idx++;
        qs.pb({ t, i, idx });
        if (t == 2) s[i] = '#';
    }

    DSU L(n), R(n);
    for (ll i = 1; i < n; i++) {
        if (s[i-1] == '#' || s[i] == '#') continue;
        if (s[i-1] == s[i]) {
            R.e[i-1] = i;
            L.e[i] = i-1;
        } 
    }

    vl ans(idx+1);
    reverse(all(qs));
    for (auto[t, i, id] : qs) {
        if (t == 1) {
            ans[id] = R.find(i) - L.find(i) + 1;
        } else {
            s[i] = S[i];
            if (i > 0 && s[i-1] == s[i]) {
                R.e[i-1] = i;
                L.e[i] = i-1;
            }
            if (i+1 < n && s[i+1] == s[i]) {
                R.e[i] = i+1;
                L.e[i+1] = i;
            } 
        }
    }

    for (ll i = 0; i <= idx; i++) cout << ans[i] << '\n';
}

signed main() {
    cin.tie(0) -> ios::sync_with_stdio(0);

    ll ttt; cin >> ttt;
    for (ll i = 1; i <= ttt; i++) solve(i);

    return 0;
}
