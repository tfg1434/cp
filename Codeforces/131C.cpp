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
ll C[65][65];
ll n, m, t;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int i = 0; i < 65; i++) {
        C[0][i] = C[i][i] = 1;
        for (int j = 1; j < i; j++) 
            C[j][i] = C[j][i-1] + C[j-1][i-1];
    }

    ll ans = 0;
    cin >> n >> m >> t;
    for (ll b = 4; b <= t-1; b++) {
        ans += C[b][n] * C[t - b][m];
    }

    cout << ans << endl;
    
    return 0;
}

