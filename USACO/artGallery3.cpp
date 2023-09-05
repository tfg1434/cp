#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
using namespace __gnu_pbds;
#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define vi vector<ll>
#define vb vector<bool>
#define f0(i,a) for(ll i=0;i<(a);i++)
#define f1(i,a) for(ll i=1;i<(a);i++)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define f first
#define s second
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }
#ifdef I_AM_NOOB
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);
#else
#define gg(...) 777771449
#endif
ll LOG2(ll x){ return __builtin_clzll(1ll) - __builtin_clzll(x); }
bool isPow2(ll n) {
    return n && ((n & (n-1)) == 0);
}
ll LOG2C(ll x) {
    if (isPow2(x)) return LOG2(x);
    return LOG2(x)+1;
}
template <typename Iter, typename Cont>
bool is_last(Iter iter, const Cont& cont) {
    return (iter != cont.end()) && (next(iter) == cont.end());
}

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;

// Thinking
// A segment of sum >= k is exactly a segment with difference in 
// prefix sums >= k. Therefore, we need to count the number of pairs (l, r)
// st pre[r] - pre[l-1] >= k quickly. Put two pointers, one on r, and one
// on l. Each time l works, we set the value of l in BIT to 1. Now to calc
// the number of pairs that end with r, all we need to do is take the sum
// of (r-n, r).
// What is the motivation to use two pointers? If this l works with lefter
// r then it definitely works with more right r.
//
// Implementation
// Learned about BIT, why it cannot support arbitrary min query (not a group),
// how g(...) is defined, how to implement, that 2d BIT is easy
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    if (fopen("artgallery3.in", "r")) {
        freopen("artgallery3.in", "r", stdin);
        freopen("artgallery3.out", "w", stdout);
    } 

    ll n, k; while (cin >> n >> k) {
        vi a(n+1); f1(i, n+1) cin >> a[i];
        a.insert(a.end(), 1+all(a)-1);
        f1(i, 2*n) a[i] += a[i-1];
        vector<pll> b(2*n);
        f0(i, 2*n) b[i] = {a[i], i};
        sort(all(b));
        gg(b);
        ll cur = 0, ans = 0;
        vi t(2*n);
        auto _sum = [&](ll r) -> ll {
            ll res = 0;
            for (; r >= 0; r = (r&(r+1))-1) res += t[r];
            return res;
        };
        auto sum = [&](ll l, ll r) -> ll {
            return _sum(r) - _sum(l-1);
        };
        auto add = [&](ll idx, ll d) -> void {
            for (; idx < 2*n; idx |= idx+1) t[idx] += d;
        };

        //two pointers, i right, cur left
        f0(i, 2*n) {
            while (cur < 2*n && b[i].f - b[cur].f >= k) {
                add(b[cur].s, 1);
                cur++;
            }
            if (b[i].s >= n) {
                ans += sum(b[i].s-n, b[i].s);
            }
        }

        if (a[n-1] >= k) ans -= n-1;
        cout << ans << endl;
    }
    
    return 0;
}
