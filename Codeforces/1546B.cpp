#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        vector<string> a(n), ab(n+n-1);
        for (auto& x : a) cin >> x;
        for (int i = 0; i < n; i++) ab[i] = a[i];
        for (int i = n; i < n + n - 1; i++) cin >> ab[i];

        //column, char
        vector<map<char, int>> cnt(m);
        for (int col = 0; col < m; col++) {
            for (int row = 0; row < n+n-1; row++) {
                cnt[col][ab[row][col]]++;
            }
        }

        for (int i = 0; i < n; i++) {
            bool ok = true;
            for (int j = 0; j < m; j++) {
                if (cnt[j][a[i][j]] % 2 == 0) {
                    ok = false;
                    break;
                }
            }

            if (ok) {
                cout << a[i] << endl;
                break;
            }
        }
    }    
    
    return 0;
}

