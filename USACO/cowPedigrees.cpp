/*
ID: toronto4
TASK: nocows 
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr int max_n = 200;
constexpr int max_k = 100;
int N, K;
int dp[max_n + 1][max_k + 1];

int main() {
    freopen("nocows.in", "r", stdin);
    freopen("nocows.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    //i nodes, j height;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= K; ++j) {
            //height is 1
            if (i == 1) dp[i][j] = 1;
            else {
                for (int k = 1; k < i; ++k) {
                    //k, i-k-1
                    dp[i][j] += dp[k][j-1] * dp[i-k-1][j-1];
                    dp[i][j] %= 9901;
                }
            }
        }
    }
    int ans = (dp[N][K] - dp[N][K-1] + 9901) % 9901;
    cout << ans << endl;

    return 0;
}
