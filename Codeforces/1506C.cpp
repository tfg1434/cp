#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


string LCS(string X, string Y, int m, int n) {
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    int res = 0, idx;

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i-1] == Y[j-1]) {
                dp[i][j] = dp[i-1][j-1]+1;

                if (dp[i][j] > res) {
                    res = dp[i][j];
                    idx = i;
                }
            }
        }
    }

    return X.substr(idx - res, res);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        string a, b; cin >> a >> b;

        int m = a.size(), n = b.size();
        string s = LCS(a, b, m, n);
        int sz = s.size();
        int ans = m-sz + n-sz;

        cout << ans << '\n';
    }    
    
    return 0;
}

