// optimizing too hard q_q

#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

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

template<class, class=void> struct is_iterable : false_type {};
template<class T> struct is_iterable<T, void_t<decltype(begin(declval<T&>())), decltype(end(declval<T&>()))>> : true_type {};
template<class T> constexpr bool is_iterable_v = is_iterable<T>::value;

template<class, class = void> struct is_readable : false_type {};
template<class T> struct is_readable<T, typename std::enable_if_t<is_same_v<decltype(cin >> declval<T&>()), istream&>>> : true_type {};
template<class T> constexpr bool is_readable_v = is_readable<T>::value;

template<class, class = void> struct is_printable : false_type {};
template<class T> struct is_printable<T, typename std::enable_if_t<is_same_v<decltype(cout << declval<T>()), ostream&>>> : true_type {};
template<class T> constexpr bool is_printable_v = is_printable<T>::value;

#define def(t, args...) \
    t args;             \
    re(args);

// Input
template<class T> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
template<class T> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } 
template<class T, class... U> void re(T& t, U&... u);
template<class T> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } 
template<class T, class U> void re(pair<T,U>& p) { re(p.f,p.s); }
template<class T> typename enable_if<needs_input_v<T>,void>::type re(T& i) { for(auto&x:i)re(x); }
template<class T, class... U> void re(T& t, U&... u) { re(t); re(u...); }

// String representation for printing
template<class T> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;
template<class T> typename enable_if<is_printable_v<T>,string>::type ts(T v) {
    stringstream ss; ss << fixed << setprecision(15) << v;
    return ss.str(); 
}
template<class T> string bit_vec(T t) { // bit vector to string
    string res = "{"; for (const auto& x : t) res += ts(x);
    res += "}"; return res; 
}
string ts(V<bool> v) { return bit_vec(v); }
template<size_t SZ> string ts(bitset<SZ> b) { return bit_vec(b); }

template<class T, class U> string ts(pair<T, U> p);
template<class T> typename enable_if<needs_output_v<T>,string>::type ts(T v);

template<class T, class U> string ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
template<class T> typename enable_if<is_iterable_v<T>,string>::type ts_sep(T v, string sep) {
    bool fst = 1; string res = "";
    for (const auto& x: v) {
        if (!fst) res += sep;
        fst = 0; res += ts(x);
    }
    return res;
}
template<class T> typename enable_if<needs_output_v<T>,string>::type ts(T v) { return "{"+ts_sep(v,", ")+"}"; }

// Printing functions
template<class T> void pr_sep(ostream& os, string, const T& t) { os << ts(t); }
template<class T, class... U> void pr_sep(ostream& os, string sep, const T& t, const U&... u) {
    pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }

template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
void ps() { cout << "\n"; }
template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 

template<class ...T> void dbg_out(const T&... t) {
    pr_sep(cerr," | ",t...); cerr << endl; }
    void loc_info(int line, string names) {
        cerr << "Line(" << line << ") -> [" << names << "]: "; }
#ifdef I_AM_NOOB
#define dbg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

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

const int max_n = 2e5;
const int K = 500;

void solve() {
    def(int, n, m);
    vpi work_maint(n); re(work_maint);

    V<vi> events(n);
    for (int i = 0; i < m; i++) {
        def(int, _, ind); ind--;
        events[ind].pb(i);
    }
    for (int i = 0; i < n; i++) if (sz(events[i]) % 2) events[i].pb(m);

    vi heavy(m);
    for (int i = 0; i < n; i++) {
        auto[x, y] = work_maint[i];
        if (x+y > K) {
            for (int j = 0; j < sz(events[i]); j += 2) {
                for (int k = events[i][j]+x; k < events[i][j+1]; k += x+y) {
                    heavy[k]++;
                    int r = min(k+y, events[i][j+1]);
                    if (r < m) heavy[r]--;
                }
            }
        } 
    } 
    for (int i = 1; i < m; i++) heavy[i] += heavy[i-1];
    auto ans = heavy;

    V<vi> light(K+1);
    for (int i = 2; i <= K; i++) light[i].resize(i);
    vpi today(m);
    for (int i = 0; i < n; i++) {
        auto [x, y] = work_maint[i];
        if (x + y <= K) {
            for (int j = 0; j < sz(events[i]); j += 2) {
                today[events[i][j]] = {-1, i};
                if (events[i][j+1] < m) {
                    today[events[i][j+1]] = {1, events[i][j]};
                }
            }
        }
    }

    for (int d = 0; d < m; d++) {
        auto [op, info] = today[d];
        if (op == -1) {
            // ps("day", d, "adding train", info);
            auto [x, y] = work_maint[info];
            for (int i = x; i < x+y; i++) {
                light[x+y][(i+d)%(x+y)]++;
            }
        } else if (op == 1) {
            // ps("day", d, "removing train", today[info].s);
            auto [x, y] = work_maint[today[info].s];
            for (int i = x; i < x+y; i++) {
                light[x+y][(i+info)%(x+y)]--;
            }
        }

        for (int i = 2; i <= K; i++) {
            ans[d] += light[i][d%i];
        }
    }

    for (int i = 0; i < m; i++) ps(ans[i]);
}

signed main() {
    setIO();
    
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}
