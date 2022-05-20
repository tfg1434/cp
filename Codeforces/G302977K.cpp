#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, k; cin >> n >> k;

    vector<vector<ll>> dp(k+1, vector<ll>(n+1, 0));
    dp[0][1] = 1;

    for (ll i = 0; i < k; i++) {
        for (ll j = 1; j <= n; j++) {
            for (ll v = j; v <= n; v += j) {
                dp[i+1][v] = (dp[i+1][v] + dp[i][j]) % MOD;
            }
        }
    }

    ll ans = 0;
    for (ll i = 1; i <= n; i++) {
        ans = (ans + dp[k][i]) % MOD;
    }

    cout << ans << endl;
    
    return 0;
}

