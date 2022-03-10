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
    
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(n, 0));
    for (int i = 0; i < n; i++) {
        cin >> a[i][i];
    }
    vector<vector<int>> ans(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        ans[i][i] = a[i][i];
        int k = a[i][i];
        int x = i, y = i;
        for (int j = 1; j < k; j++) {
            if (y == 0 || ans[x][y-1] != 0) x++;
            else y--;
            ans[x][y] = k;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    // for (int i = 0; i < n; i++) {
        // //square of permutation == (i, i)
        // int cnt = 0, x = i, y = i+1;
        // while (cnt < a[i][i]-1) {
            // a[x][y] = a[i][i];
            // cnt++;
            // if (x > 0 && a[x-1][y] == -1) {
                // x--;
            // } else {
                // y++;
            // }
        // }
    // }

    // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < i; j++) {
            // if (a[i][j] != -1) {
                // cout << a[i][j] << " ";
            // }
        // }
        // cout << endl;
    // }
    
    return 0;
}

