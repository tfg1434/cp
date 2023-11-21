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
#define f0(i,a) FOR(i,0,a)
#define f1(i,a) FOR(i,1,a+1)
#define ROF(i,a,b) for (ll i = (b)-1; i >= (a); --i)
#define R0F(i,a) ROF(i,0,a)
#define rep(a) f0(_,a)
#define each(a,x) for (auto& a: x)

const ll P = 1e9+7; // 998244353;
const ll MX = 2e5+5;
const ll BIG = 1e18; // not too close to LLONG_MAX
const db PI = acos((db)-1);
const ll dx[4]{1,0,-1,0}, dy[4]{0,1,0,-1}; // for every grid problem!!
mt19937 rng((uint32_t)chrono::steady_clock::now().time_since_epoch().count()); 
template<class T> using pqg = priority_queue<T,vector<T>,greater<T>>;

ll binpow(ll a, ll b) {
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
tcTU> void erase(T& t, const U& u) { // don't erase
    auto it = t.find(u); assert(it != end(t));
    t.erase(it); } // element that doesn't exist from (multi)set

#define tcTUU tcT, class ...U
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


const ll N = 5e4+5;
ll dp[N][2], dp2[N][2];

void solve() {
    //overflow is annoying
    // memset(dp, 0x7f, sizeof dp);
    // memset(dp2, 0x7f, sizeof dp2);

    f0(i, N) f0(j, 2) dp[i][j] = BIG;
    f0(i, N) f0(j, 2) dp2[i][j] = BIG;

    ll n; cin >> n;
    vl a(n+1); f1(i, n) cin >> a[i];

    vl deg(n+1);
    V<vl> g(n+1);
    f1(i, n-1) {
        ll u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
        deg[u]++; deg[v]++;
    }
    deg[1]++;

    auto make = [&](ll u, ll x) {
        if (x == 0) return dp[u][0];
        if (x == 1) return dp[u][1];
        if (x == 2) return dp2[u][0];
        return dp2[u][1];
    };

    function<void(ll, ll)> dfs = [&](ll u, ll p) {
        vl b;
        each(v, g[u]) if (v != p) {
            dfs(v, u);
            b.pb(v);
        }

        if (deg[u] == 1) {
            if (a[u]) {
                dp[u][1] = 1;
                dp2[u][0] = 0;

            } else {
                dp[u][0] = 0;
                dp2[u][1] = 1;
            }
        }

        if (deg[u] == 3) {
            // flipped/kept
            // 0 = end w 0, keep u
            // 1 = end w 0, flip u
            // 2 = end w 1, keep u
            // 3 = end w 1, flip u
            f0(i, 2) f0(j, 4) f0(k, 4) {
                ll y = make(b[0], j);
                ll z = make(b[1], k);
                // gg(i, j, k, y, z);

                ll U = (a[u]+i+j+k) % 2;
                ll V1 = (j/2+i) % 2;
                ll V2 = (k/2+i) % 2;

                if (!U && !V1 && !V2) {
                    ckmin(dp[u][i], i+y+z);
                }
                if (U && !V1 && !V2) {
                    ckmin(dp2[u][i], i+y+z);
                }
            }
        }

        if (deg[u] == 2) {
            f0(i, 2) f0(j, 4) {
                ll y = make(b[0], j);

                ll U = (a[u]+i+j) % 2;
                ll V1 = (j/2+i) % 2;

                if (!U && !V1) ckmin(dp[u][i], i+y);
                if (U && !V1) ckmin(dp2[u][i], i+y);
            }
        }  
    };

    dfs(1, 1);

    // f1(i, n) gg(dp[i][0], dp[i][1]);
    // f1(i, n) gg(dp2[i][0], dp2[i][1]);

    ll ans = min(dp[1][0], dp[1][1]);
    cout << (ans >= BIG ? "Impossible" : to_string(ans)) << endl;
}

signed main() {
    setIO("cownival3");
    
    solve(); 

    return 0;
}
