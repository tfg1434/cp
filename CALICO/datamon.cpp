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

void feed(ll x) {
    cout << "feed" << ' ' << x;
    cout << endl;
    string _; cin >> _;
    assert(_ == "OK");
}

ll poop() {
    cout << "poop" << endl;
    ll x; cin >> x;

    return x;
}

void solve() {
    feed(1);
    feed(3);
    feed(2);

    ll x = poop();
    if (x == 1) cout << ("guess queueon");
    if (x == 2) cout << ("guess stackeon");
    if (x==3) cout << ("guess heapeon");
    cout << endl;
    
    string _; cin >> _;
}

signed main() {
    ll tc; cin >> tc; while (tc--) {
        solve();
    } 

    return 0;
}

