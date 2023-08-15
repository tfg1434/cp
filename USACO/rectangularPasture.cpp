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

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;

bool ycmp(pll a, pll b) { return a.s < b.s; }

// Thinking
// Didn't think of edges, thought about corners, which is wrong
// Tried to overcomplicate a silver problem, convexity, no
// Thought about minimal principle

// Implementation
// Why 1-index? nightmare
// Don't need map to coordinate compress. even easier here b/c 
// all x, y distinct.
// Draw your paper diagram with (0,0) in top left
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; while (cin >> n) {
        vector<pll> a(n);
        f0(i, n) {
            cin >> a[i].f >> a[i].s;
        }
        sort(all(a));
        f0(i, n) a[i].f = i+1;
        sort(all(a), ycmp);
        f0(i, n) a[i].s = i+1;

        vector<vi> pre(n+1, vi(n+1));
        f0(i, n) pre[a[i].f][a[i].s] = 1;
        f1(i, n+1) {
            f1(j, n+1) {
                pre[i][j] += pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            }
        }

        //inclusive sum x2, y2 BR corner
        auto topsum = [&](ll x1, ll x2, ll y) -> ll {
            return pre[x2][y] - pre[x1-1][y];
        };
        auto botsum = [&](ll x1, ll x2, ll y) -> ll {
            // if (x1 == x2) gg(pre[x2][n] , pre[x1-1][n] , pre[x2][y-1] , pre[x1-1][y-1]);
            return pre[x2][n] - pre[x1-1][n] - pre[x2][y-1] + pre[x1-1][y-1];
        };

        sort(all(a));
        ll ans = 0;
        f0(i, n) {
            for (ll j = i; j < n; j++) {
                pll p1 = a[i], p2 = a[j];
                assert(p1.f <= p2.f);
                ll a = topsum(p1.f, p2.f, min(p1.s, p2.s));
                ll b = botsum(p1.f, p2.f, max(p1.s, p2.s));
                // gg(p1, p2);
                // gg(a,b);
                ans += a*b;
            }
            // gg(ans);
        }

        cout << ans+1 << endl;
    }
    
    return 0;
}
