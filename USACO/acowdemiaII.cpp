#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k, n; cin >> k >> n;
    char ans[100][100];
    map<string, int> m;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        m[s] = i;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) ans[i][j] = '?';
        ans[i][i] = 'B';
    }

    for (int i = 0; i < k; i++) {
        vector<string> v(n);
        for (auto& i : v) cin >> i;

        for (int j = 0; j < n; j++) {
            bool sorted = true;

            for (int k = j+1; k < n; k++) {
                if (v[k-1] > v[k]) sorted = false;

                if (!sorted) {
                    //0 = more junior
                    int a = m[v[j]];
                    int b = m[v[k]];
                    ans[a][b] = '0';
                    ans[b][a] = '1';
                }
            }    
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cout << ans[i][j];
        cout << '\n';
    }
        
    return 0;
}

