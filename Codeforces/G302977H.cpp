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
    
    ll n; while (cin >> n) {
        vector<ll> s(n);
        for (auto &x : s) cin >> x;
        vector<ll> c(n);
        for (auto &x : c) cin >> x;

        vector<vector<ll>> dp(n+1, vector<ll>(3, INFF));

        for (ll i = 0; i < n; i++) {
            dp[i][0] = c[i];

            for (ll j = 1; j < 3; j++) {
                //look for position j
                for (ll k = 0; k < i; k++) {
                    if (s[k] >= s[i]) continue;

                    dp[i][j] = min(dp[i][j], dp[k][j-1] + c[i]);
                }
            }
        }

        ll ans = INFF;
        for (ll i = 0; i < n; i++) 
            ans = min(ans, dp[i][2]);

        if (ans == INFF) cout << -1 << endl;
        else cout << ans << endl;
    }        
    
    return 0;
}

