#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
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

int main() {
    // freopen("teamwork.in", "r", stdin);
    // freopen("teamwork.out", "w", stdout);
    
    ll n, k; while (cin >> n >> k) {
        vector<ll> s(n+1);
        for (ll i = 1; i <= n; i++) cin >> s[i];
        vector<vector<ll>> dp(n+1, vector<ll>(2, 0));
        
        for (ll i = 1; i <= n; i++) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1])+s[i];
            //size of team 1..k
            for (ll j = 1; j <= k; j++) {
                ll mx = 0;
                if (i-j+1 < 1) break;
                for (ll kk = i-j+1; kk <= i; kk++) {
                    mx = max(mx, s[kk]);
                }
                dp[i][1] = max(dp[i-j][0], dp[i-j][1])+mx*j;
            }
        }
        
        cout << max(dp[n][0], dp[n][1]) << endl;
    }
    
    return 0;
}

