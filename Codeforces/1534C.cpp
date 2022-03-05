#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;
constexpr ll MOD = 1e9 + 7;


void solve(int node, vector<int>& v, map<int, int>& m) {
    if (v[node] == 0) {
        v[node] = m[node];
        solve(m[node], v, m);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<vector<int>> g(2, vector<int>(n));
        for (int i = 0; i < 2; i++) 
            for (int j = 0; j < n; j++)
                cin >> g[i][j];

        vector<int> v(n+1, 0);
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            m[g[0][i]] = g[1][i];
        }
        ll ans = 1;
        for (int i = 0; i < n; i++) {
            if (v[g[0][i]] == 0) {
                solve(g[0][i], v, m);
                ans = (ans * 2) % MOD;
            }
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

