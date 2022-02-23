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
        int n; cin >> n;
        string s; cin >> s;
        vector<int> v;
        for (int i = 0; i < n; i++) {
            if (s[i] == '2') v.push_back(i);
        }
        int k = v.size();
        if (k == 1 || k == 2) {
            cout << "NO" << endl;
            continue;
        }

        vector<string> ans(n, string(n, '='));
        for (int i = 0; i < n; i++) ans[i][i] = 'X';

        for (int i = 0; i < k; i++) {
            int x = v[i], y = v[(i+1) % k];

            ans[x][y] = '+';
            ans[y][x] = '-';
        }

        cout << "YES" << '\n';
        for (const auto& s : ans) 
            cout << s << '\n';
    }    
    
    return 0;
}

