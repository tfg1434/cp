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
constexpr int N = 1005;
int n, m, sx, sy, tx, ty;
char board[N][N];
int dist[N][N], vis[N][N];
int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

inline bool valid(int x, int y) {
    return x < n && y < m && x >= 0 && y >= 0;
}

void solve() {
    queue<pii> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;
    vis[sx][sy] = 255;

    while (!q.empty()) {
        pii u = q.front(); q.pop();
        if (u.first == tx && u.second == ty) {
            cout << dist[tx][ty] << '\n';
            return;
        }

        for (int i = 0; i < 8; i++) {
            int nx, ny, jump=1;
            while (true) {
                nx = u.first + dx[i] * jump;
                ny = u.second + dy[i] * jump;
                if (valid(nx, ny) && board[nx][ny] != 'X' && !(vis[nx][ny] & (1 << i))) {
                    if (!vis[nx][ny]) {
                        dist[nx][ny] = dist[u.first][u.second] + 1;
                        q.push({nx, ny});
                    }
                    vis[nx][ny] |= (1 << i);

                } else break;

                jump++;
            }
        }
    }

    cout << -1 << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> board[i];
            for (int j = 0 ; j < m; j++) {
                if (board[i][j] == 'S')
                    sx = i, sy = j;
                if (board[i][j] == 'F')
                    tx = i, ty = j;
                dist[i][j] = INF;
                vis[i][j] = 0;
            }
        }

        solve(); 
    }    
    
    return 0;
}

