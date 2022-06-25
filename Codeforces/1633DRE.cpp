#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr ll N = 1005;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n, k; cin >> n >> k;
        vector<ll> b(n);
        for (auto& x : b) cin >> x;
        vector<ll> c(n);
        for (auto& x : c) cin >> x;

        vector<ll> dp(N, INFF);
        dp[1] = 0;
        for (ll i = 1; i < N; i++) {
            for (ll x = 1; x <= i; x++) {
                ll j = i+i/x;
                if (j < N) dp[j] = min(dp[j], dp[i]+1);
            }
        }

        k = min(k, 12 * n);
        vector<vector<ll>> dp2(n+1, vector<ll>(k+1, 0));
        for (ll i = 1; i <= n; i++) {
            for (ll j = 0; j <= k; j++) {
                if (dp[b[i-1]] <= j) dp2[i][j] = max(dp2[i-1][j], c[i-1] + dp2[i-1][j - dp[b[i-1]]]);
                else dp2[i][j] = dp2[i-1][j];
            }
        }

        cout << dp2[n][k] << endl;
    }    
    
    return 0;
}

