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
int grid[1005][1005];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m, k; cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) 
            cin >> grid[i][j];

    for (int i = 0; i < k; i++) {
        int x = 0, y; cin >> y;
        y--;
        
        while (x < n) {
            int a = grid[x][y];
            grid[x][y] = 2;
            if (a == 1) y++;
            else if (a == 2) x++;
            else if (a == 3) y--;
        }

        cout << y+1 << ' ';
    }
    
    return 0;
}

