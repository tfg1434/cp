#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> b(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> b[i][j];
            }
        }
        for (int i = 0; i < n; i++) {
            sort(all(b[i]));
        }
        vector<vector<int>> ans(n, vector<int>());
        for (int i = 0; i < m; i++) {
            int mn;
            for (int j = 0; j < n; j++) mn = min(mn, b[j][0]);
            for (int j = 0; j < b.size(); j++) {
                if (i == mn) {
                    ans[i].push_back(b[i][0]);
                    b[i].erase(b[i].begin());
                } else {
                    ans[i].push_back(b[i].back());
                    b[i].pop_back();
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cout << b[i][j] << " ";
            }
            cout << "\n";
        }
    }    
    
    return 0;
}

