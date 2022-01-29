/*
ID: toronto4
TASK: money 
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr int MAX_N = 10'000;
constexpr int MAX_V = 25;
int N, V;
ll dp[MAX_N+1];
int coins[MAX_V];

int main() {
    freopen("money.in", "r", stdin);
    freopen("money.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> N;
    for (int i = 0; i < V; ++i) cin >> coins[i];
    dp[0] = 1;

    for (int i = 0; i < V; ++i) 
        for (int j = 0; j <= N; ++j) 
            if (j + coins[i] <= N) dp[j + coins[i]] += dp[j];
        
    cout << dp[N] << '\n';

    return 0;
}
