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

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, m, k; while (cin >> n >> m >> k) {
        //stage, team
        vector<vi> a(m+1, vi(n+1));
        f1(j, n+1) {
            f1(i, m+1) {
                cin >> a[i][j];
            }
        }

        //stage, team, swaps
        vector<vector<vi>> dp(m+1, vector<vi>(n+1, vi(k+1)));
        // The maximum from last stage with k changes
        vi mx(k+1);
        f1(j, n+1) {
            dp[1][j][0] = a[1][j];
            mx[0] = dp[1][j][0];
        }
        for (ll i = 2; i <= m; i++) {
            f1(j, n+1) {
                f0(ki, k+1) {
                    if (ki > 0) dp[i][j][ki] = max(mx[ki-1], dp[i-1][j][ki]) + a[i][j];
                    else dp[i][j][ki] = dp[i-1][j][ki] + a[i][j];
                }
            }
            f0(ki, k+1) {
                f1(j, n+1) {
                    mx[ki] = max(mx[ki], dp[i][j][ki]);
                }
            }
        }

        f1(i, m+1) {
            ll mx = 0;
            f1(j, n+1) f0(ki, k+1) {
                mx = max(mx, dp[i][j][ki]);
            }
            gg(mx);
        }
        ll ans = 0;
        f1(j, n+1) f0(ki, k+1) {
            ans = max(ans, dp[m][j][ki]);
        }

        cout << ans << endl;
    } 
    
    return 0;
}
