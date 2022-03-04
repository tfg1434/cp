#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;
constexpr ll max_n = 2*1e5+1;
int dp[max_n][2];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        string s; cin >> s;
        // memset(dp, 0, sizeof dp);
        dp[0][0] = 0; dp[0][1] = 0;

        ll ans = 0;
        for (int i = 1; i <= s.size(); i++) {
            if (s[i-1] == '?') {
                dp[i][0] = dp[i-1][1] + 1;
                dp[i][1] = dp[i-1][0] + 1;
            } else if (s[i-1] == '0') {
                dp[i][0] = dp[i-1][1] + 1;
                dp[i][1] = 0;
            } else if (s[i-1] == '1') {
                dp[i][1] = dp[i-1][0] + 1;
                dp[i][0] = 0;
            }

            ans += max(dp[i][0], dp[i][1]);
        } 

        cout << ans << '\n';
    }    
    
    return 0;
}

