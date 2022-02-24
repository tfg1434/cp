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
        vector<int> bs(n), ks(n);
        for (int i = 0; i < n; i++) {
            int b = INT_MAX;
            int k; cin >> k;
            ks[i] = k;

            for (int j = 0; j < k; j++) {
                int x; cin >> x;
                b = min(b, x + j);
            }
            bs[i] = b;
        }

        int ans = INT_MIN;
        int sub = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, bs[i] - sub);
            sub += ks[i];
        }

        cout << ans+1 << '\n';
    }    
    
    return 0;
}

