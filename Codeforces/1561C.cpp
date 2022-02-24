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
        vector<int> ks(n, 0);
        vector<int> bs(n, 0);
        for (int i = 0; i < n; i++) {
            cin >> ks[i];

            for (int j = 0; j < ks[i]; j++) {
                int x; cin >> x;
                bs[i] = max(bs[i], x - j);
            }
        }

        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++) v.push_back({bs[i], ks[i]});
        sort(all(v));

        int ans = 0;
        int sub = 0;
        for (auto [b, k] : v) {
            ans = max(ans, b - sub);

            sub += k;
        }

        cout << ans + 1 << '\n';
    }    
    
    return 0;
}

