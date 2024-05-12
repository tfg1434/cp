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

// Note: We already have semi-intervals
//
// Variables
// Set of the rightmost borders in A
//
// Precomp
// The set of events: +1 and -1 for A, only left border in B

const int max_x = 1e9;
struct node {
    node *l, *r;
    pi t;
    node(node* l, node* r) {
        this->l = l, this->r = r;
        t = max(l->t, r->t);
    }
    node() {
        l = r = nullptr;
        t = {0, 0};
    }
    void extend() {
        if (!l) {
            l = new node();
            r = new node();
        }
    }
    void upd() {
        t = max(l->t, r->t);
    }
};
void point_relax(node* v, int l, int r, int i, pi x) {
    if (l == r-1) {
        ckmax(v->t, x);
        return;
    }
    v->extend();
    int m = (l+r)/2;
    if (i < m) point_relax(v->l, l, m, i, x);
    else point_relax(v->r, m, r, i, x);    
    v->upd();
}
pi range_max(node* v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return {0, 0};
    if (L <= l && r <= R) return v->t;
    v->extend();
    int m = (l+r)/2;
    return max(range_max(v->l, l, m, L, R), range_max(v->r, m, r, L, R));
}

void solve() {
    def(int, n, m);
    vi l(n), r(n);
    for (int i = 0; i < n; i++) re(l[i], r[i]);
    vi a(m), b(m), c(m);
    for (int i = 0; i < m; i++) re(a[i], b[i], c[i]);

    long long ans = 0;
    int sol_a = -1, sol_b = -1;
    {
        V<array<int, 3>> events; // pos, type, index
        for (int i = 0; i < n; i++) {
            events.pb({l[i], 1, i});
            events.pb({r[i], -1, i});
        }
        for (int i = 0; i < m; i++) {
            events.pb({a[i], 2, i+n});
        }
        sort(all(events));

        multiset<pi> max_rb;
        for (auto [x, type, ind] : events) {
            if (type == 1) {
                max_rb.insert({ r[ind], ind });
            } else if (type == -1) {
                max_rb.erase({ x, ind });
            } else if (type == 2) {
                ind -= n;
                if (sz(max_rb)) {
                    int inter = min(b[ind], rbegin(max_rb)->f) - x;
                    if (ckmax(ans, (long long) inter * c[ind])) {
                        sol_b = ind;
                        sol_a = rbegin(max_rb)->s;
                    }
                }
            }
        }
    }

    {
        long long ANS = 0;
        int SOL_A = -1, SOL_B = -1;
        V<array<int, 3>> events; // pos, type, index
        for (int i = 0; i < n; i++) {
            events.pb({l[i], 1, i});
            events.pb({r[i], -1, i});
        }
        for (int i = 0; i < m; i++) {
            events.pb({b[i], -2, i+n});
        }
        sort(rall(events));

        multiset<pi> min_lb;
        for (auto [x, type, ind] : events) {
            if (type == -1) {
                min_lb.insert({ l[ind], ind });
            } else if (type == 1) {
                min_lb.erase({ x, ind });
            } else if (type == -2) {
                ind -= n;
                if (sz(min_lb)) {
                    int inter = x - max(a[ind], begin(min_lb)->f);
                    if (ckmax(ANS, (long long) inter * c[ind])) {
                        SOL_B = ind;
                        SOL_A = begin(min_lb)->s;
                    }
                }
            }
        }
        if (ckmax(ans, ANS)) sol_a = SOL_A, sol_b = SOL_B;
    }

    {
        node* tree = new node();

        long long ANS = 0;
        int SOL_A = -1, SOL_B = -1;
        V<array<int, 3>> events; // pos, type, index
        for (int i = 0; i < n; i++) events.pb({r[i], 1, i});
        for (int i = 0; i < m; i++) events.pb({b[i], 2, i+n});
        sort(all(events));

        for (auto [x, type, ind] : events) {
            if (type == 1) {
                point_relax(tree, 0, max_x+1, l[ind], { r[ind]-l[ind], ind });

            } else if (type == 2) {
                ind -= n;
                pi inter = range_max(tree, 0, max_x+1, a[ind], b[ind]);
                if (ckmax(ANS, (long long) inter.f*c[ind])) {
                    SOL_B = ind;
                    SOL_A = inter.s;
                }
            }
        }
        if (ckmax(ans, ANS)) sol_a = SOL_A, sol_b = SOL_B;
    }

    ps(ans);
    if (ans > 0) {
        ps(sol_a+1, sol_b+1);
    }
}

signed main() {
    setIO();
    
    int tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}
