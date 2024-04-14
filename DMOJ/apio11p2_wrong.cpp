// this is not quite right bc I didn't consider jumping off edges
// it was correct to make nodes on the borders; but after that you
// should think at coordinate compression instead of corners

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

#define tcTUU tcT, class ...U

inline namespace Helpers {
    //////////// is_iterable
    // https://stackoverflow.com/questions/13830158/check-if-a-variable-type-is-iterable
    // this gets used only when we can call begin() and end() on that type
    tcT, class = void> struct is_iterable : false_type {};
    tcT> struct is_iterable<T, void_t<decltype(begin(declval<T>())),
                                                                                                                                            decltype(end(declval<T>()))
                                                                                                                                        >
                                                                                                > : true_type {};
    tcT> constexpr bool is_iterable_v = is_iterable<T>::value;

    //////////// is_readable
    tcT, class = void> struct is_readable : false_type {};
    tcT> struct is_readable<T,
                                    typename std::enable_if_t<
                                                    is_same_v<decltype(cin >> declval<T&>()), istream&>
                                    >
                    > : true_type {};
    tcT> constexpr bool is_readable_v = is_readable<T>::value;

    //////////// is_printable
    // // https://nafe.es/posts/2020-02-29-is-printable/
    tcT, class = void> struct is_printable : false_type {};
    tcT> struct is_printable<T,
                                    typename std::enable_if_t<
                                                    is_same_v<decltype(cout << declval<T>()), ostream&>
                                    >
                    > : true_type {};
    tcT> constexpr bool is_printable_v = is_printable<T>::value;
}

#define def(t, args...)                                                        \
    t args;                                                                    \
    re(args);

inline namespace Input {
    tcT> constexpr bool needs_input_v = !is_readable_v<T> && is_iterable_v<T>;
    tcTUU> void re(T& t, U&... u);
    tcTU> void re(pair<T,U>& p); // pairs

    // re: read
    tcT> typename enable_if<is_readable_v<T>,void>::type re(T& x) { cin >> x; } // default
    tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; } // complex
    tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i); // ex. vectors, arrays
    tcTU> void re(pair<T,U>& p) { re(p.f,p.s); }
    tcT> typename enable_if<needs_input_v<T>,void>::type re(T& i) {
        each(x,i) re(x); }
    tcTUU> void re(T& t, U&... u) { re(t); re(u...); } // read multiple

    // rv: resize and read vectors
    void rv(size_t) {}
    tcTUU> void rv(size_t N, V<T>& t, U&... u);
    template<class...U> void rv(size_t, size_t N2, U&... u);
    tcTUU> void rv(size_t N, V<T>& t, U&... u) {
        t.rsz(N); re(t);
        rv(N,u...); }
    template<class...U> void rv(size_t, size_t N2, U&... u) {
        rv(N2,u...); }

    // dumb shortcuts to read in ints
    void decrement() {} // subtract one from each
    tcTUU> void decrement(T& t, U&... u) { --t; decrement(u...); }
    #define ints(...) int __VA_ARGS__; re(__VA_ARGS__);
    #define int1(...) ints(__VA_ARGS__); decrement(__VA_ARGS__);
}

inline namespace ToString {
    tcT> constexpr bool needs_output_v = !is_printable_v<T> && is_iterable_v<T>;

    // ts: string representation to print
    tcT> typename enable_if<is_printable_v<T>,str>::type ts(T v) {
        stringstream ss; ss << fixed << setprecision(15) << v;
        return ss.str(); } // default
    tcT> str bit_vec(T t) { // bit vector to string
        str res = "{"; F0R(i,sz(t)) res += ts(t[i]);
        res += "}"; return res; }
    str ts(V<bool> v) { return bit_vec(v); }
    template<size_t SZ> str ts(bitset<SZ> b) { return bit_vec(b); } // bit vector
    tcTU> str ts(pair<T,U> p); // pairs
    tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v); // vectors, arrays
    tcTU> str ts(pair<T,U> p) { return "("+ts(p.f)+", "+ts(p.s)+")"; }
    tcT> typename enable_if<is_iterable_v<T>,str>::type ts_sep(T v, str sep) {
        // convert container to string w/ separator sep
        bool fst = 1; str res = "";
        for (const auto& x: v) {
            if (!fst) res += sep;
            fst = 0; res += ts(x);
        }
        return res;
    }
    tcT> typename enable_if<needs_output_v<T>,str>::type ts(T v) {
        return "{"+ts_sep(v,", ")+"}"; }

    // for nested DS
    template<int, class T> typename enable_if<!needs_output_v<T>,vs>::type 
            ts_lev(const T& v) { return {ts(v)}; }
    template<int lev, class T> typename enable_if<needs_output_v<T>,vs>::type 
            ts_lev(const T& v) {
        if (lev == 0 || !sz(v)) return {ts(v)};
        vs res;
        for (const auto& t: v) {
            if (sz(res)) res.bk += ",";
            vs tmp = ts_lev<lev-1>(t);
            res.ins(end(res),all(tmp));
        }
        F0R(i,sz(res)) {
            str bef = " "; if (i == 0) bef = "{";
            res[i] = bef+res[i];
        }
        res.bk += "}";
        return res;
    }
}

inline namespace Output {
    template<class T> void pr_sep(ostream& os, str, const T& t) { os << ts(t); }
    template<class T, class... U> void pr_sep(ostream& os, str sep, const T& t, const U&... u) {
        pr_sep(os,sep,t); os << sep; pr_sep(os,sep,u...); }
    // print w/ no spaces
    template<class ...T> void pr(const T&... t) { pr_sep(cout,"",t...); } 
    // print w/ spaces, end with newline
    void ps() { cout << "\n"; }
    template<class ...T> void ps(const T&... t) { pr_sep(cout," ",t...); ps(); } 
    // debug to cerr
    template<class ...T> void dbg_out(const T&... t) {
        pr_sep(cerr," | ",t...); cerr << endl; }
    void loc_info(int line, str names) {
        cerr << "Line(" << line << ") -> [" << names << "]: "; }
    template<int lev, class T> void dbgl_out(const T& t) {
        cerr << "\n\n" << ts_sep(ts_lev<lev>(t),"\n") << "\n" << endl; }
    #ifdef I_AM_NOOB
        #define gg(...) loc_info(__LINE__,#__VA_ARGS__), dbg_out(__VA_ARGS__)
        #define ggl(lev,x) loc_info(__LINE__,#x), dbgl_out<lev>(x)
    #else // don't actually submit with this
        #define gg(...) 777771449
        #define ggl(lev,x)
    #endif

    // https://stackoverflow.com/questions/47980498/accurate-c-c-clock-on-a-multi-core-processor-with-auto-overclock?noredirect=1&lq=1
    const auto beg = std::chrono::high_resolution_clock::now();
    void dbg_time() {
        auto duration = chrono::duration<double>(
            std::chrono::high_resolution_clock::now() - beg);
        gg(duration.count());
    }
}

inline namespace FileIO {
    void setIn(str s)  { freopen(s.c_str(),"r",stdin); }
    void setOut(str s) { freopen(s.c_str(),"w",stdout); }
    void setIO(str s = "") {
        cin.tie(0)->sync_with_stdio(0); // unsync C / C++ I/O streams
        // cin.exceptions(cin.failbit);
        // throws exception when do smth illegal
        // ex. try to read letter into int
        if (sz(s) && fopen((s+".in").c_str(), "r")) setIn(s+".in"), setOut(s+".out"); // for old USACO
    }
}

// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) yy(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

struct chash {
    // any random-ish large odd number will do
    const uint64_t C = uint64_t(2e18 * PI) + 71;
    // random 32-bit number
    const uint32_t RANDOM =
                    chrono::steady_clock::now().time_since_epoch().count();
    size_t operator()(uint64_t x) const {
        // see https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html
        return __builtin_bswap64((x ^ RANDOM) * C);
    }
};
template <class K, class V> using cmap = unordered_map<K, V, chash>;
// example usage: cmap<int, int>

bool in_strict(ll x, ll y, ll x1, ll x2, ll y1, ll y2) {
    return x1 < x && x < x2 && y1 < y && y < y2;
}
ll calc_dist(pl a, pl b) {
    return abs(a.f-b.f) + abs(a.s-b.s);
}
// is b to the upper right of a? (strict)
bool is_upper_right(pl a, tuple<ll, ll, ll, ll> b) {
    return a.f < get<0>(b) && a.s < get<2>(b);
}

void solve() {
    def(ll, sx, sy, tx, ty);
    def(ll, n);
    V<tuple<ll, ll, ll, ll>> rect;
    rect.eb(sx, sx, sy, sy);
    rect.eb(tx, tx, ty, ty);
    n += 2;
    rep(n) {
        def(ll, x1, y1, x2, y2);
        if (x1 > x2) swap(x1, x2);
        if (y1 > y2) swap(y1, y2);
        rect.eb(x1, x2, y1, y2);

        // Bees cannot enter any beehive
        if (in_strict(sx, sy, x1, x2, y1, y2) || in_strict(tx, ty, x1, x2, y1, y2)) {
            ps("No Path");
            return;
        }
    }

    auto convert = [&](ll i, ll ci) -> pl {
        if (ci == 0) return {get<0>(rect[i]), get<2>(rect[i])};
        if (ci == 1) return {get<0>(rect[i]), get<3>(rect[i])};
        if (ci == 2) return {get<1>(rect[i]), get<2>(rect[i])};
        return {get<1>(rect[i]), get<3>(rect[i])};
    };

    V<V<vpl>> g(n, V<vpl>(4));
    for (ll i = 0; i < n; i++) for (ll ci = 0; ci < 4; ci++) {
        auto[x,y] = convert(i, ci);

        ll dl = BIG, dr = BIG, du = BIG, dd = BIG;
        ll fl = -1, fr = -1, fu = -1, fd = -1;
        for (ll j = 0; j < n; j++) if (i != j) {
            if (get<0>(rect[j]) <= x && x <= get<1>(rect[j])) {
                if (get<2>(rect[j]) >= y && ckmin(du, get<2>(rect[j])-y)) fu = j;
                if (get<3>(rect[j]) <= y && ckmin(dd, y-get<3>(rect[j]))) fd = j;
            }
            if (get<2>(rect[j]) <= y && y <= get<3>(rect[j])) {
                if (get<0>(rect[j]) >= x && ckmin(dr, get<0>(rect[j])-x)) fr = j;
                if (get<1>(rect[j]) <= x && ckmin(dl, x-get<1>(rect[j]))) fl = j;
            }
        }

        for (auto r : {fl, fr, fu, fd}) if (r != -1) {
            for (ll CI = 0; CI < 4; CI++) {
                g[i][ci].pb({r, CI});
            }
        }
    }
    ps(g[0][0]);

    V<vl> dist(n, vl(4, BIG));
    pqg<pair<ll, pl>> q;
    dist[0][0] = 0; q.push({0, {0, 0}});
    while (sz(q)) {
        auto [d, rci] = q.top(); q.pop();
        auto [r, ci] = rci;
        if (dist[r][ci] != d) continue;

        for (auto [R, CI] : g[r][ci]) {
            if (ckmin(dist[R][CI], d+calc_dist(convert(r, ci), convert(R, CI)))) {
                ps(r, ci, R, CI, dist[R][CI]);
                q.push({dist[R][CI], {R, CI}});
            }
        }
    }

    ll ans = BIG;
    for (ll i = 0; i < n; i++) {
        auto [x1, x2, y1, y2] = rect[i];
        for (ll ci = 0; ci < 4; ci++) {
            if ((x1 <= tx && tx <= x2) || (y1 <= ty && ty <= y2)) {
                ckmin(ans, dist[i][ci]+calc_dist({tx, ty}, convert(i, ci)));
            }
        }
    }

    if (ans == BIG) ps("No Path");
    else ps(ans);
}

signed main() {
    setIO();
    
    ll tc = 1;
    cin >> tc;
    while (tc--) solve();

    return 0;
}