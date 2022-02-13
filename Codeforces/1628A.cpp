#include <bits/stdc++.h>
using namespace std;

int T;
constexpr int max_n = 2*1e5;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        vector<vector<int>> b(n+1);
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            b[a[i]].push_back(i);
        }

        int k = 0, r;
        while (k < n) {
            r = k;
            int i;
            for (i = 0; i <= n+1; i++) {
                auto iter = lower_bound(b[i].begin(), b[i].end(), k);
                if (iter == b[i].end()) break;
                r = max(r, *iter);
            }

            ans.push_back(i);
            k = r+1;
        }

        cout << ans.size() << endl;
        for (auto i : ans) cout << i << ' ';
        cout << endl;
    }
    
    return 0;
}

