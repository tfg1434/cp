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
char a[20][20];
int b[20][20];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        int n, m, k; cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) cin >> (a[i] + 1);

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] != '*') continue;
                int size = 0;
                for (int s = 1; ; s++) {
                    if (j-s < 1 || j+s > m) break;
                    if (a[i-s][j-s] == '*' && a[i-s][j+s] == '*') size = s;
                    else break;
                }
                if (size < k) continue;

                for (int s = 0; s <= size; s++)
                    b[i-s][j-s] = b[i-s][j+s] = 1;
            }
        }

        bool ok = true;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (a[i][j] == '*' && b[i][j] == 0) {
                    ok = false;
                    break;
                }
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }    
    
    return 0;
}

