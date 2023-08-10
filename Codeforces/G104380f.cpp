#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
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
constexpr ll N = 5e4+5;
ll dp[10][10][10][10][N];
bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; cin >> n;
    // vector<ll> dp(n+1);
    // dp[4] = 3010;
    vector<vector<ll>> toP(28);
    for (ll i = 0; i < toP.size(); i++) {
        for (ll j = 0; j <= 9; j++) {
            if (isPrime(i+j)) {
                toP[i].pb(j);
            }
        }
    }
    for (ll i = 0; i < 10; i++) for (ll j = 0; j < 10; j++) 
    for (ll k = 0; k < 10; k++) for (ll l = 0; l < 10; l++) 
        dp[i][j][k][l][4] = 3010;

    vector<ll> ans(n+1);
    for (ll m = 5; m <= n; m++) 
    for (ll i = 0; i < 10; i++) for (ll j = 0; j < 10; j++) 
    for (ll k = 0; k < 10; k++) {
        for (auto d : toP[i+j+k]) {
            for (auto a : toP[i+j+k]) {
                dp[i][j][k][d][m] += dp[a][i][j][k][m-1] %= P;
                ans[m] = (ans[m] + dp[i][j][k][d][m]) % P;
            }
        } 
    }

    cout << ans[n] << endl;
    
    return 0;
}
