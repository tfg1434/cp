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
        int m; cin >> m;
        vector<int> a(m), b(m);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        int ans = INT_MAX;
        int s1 = 0, s2 = 0;
        for (int i = 0; i < m; i++) s1 += a[i];
        for (int i = 0; i < m; i++) {
            s1 -= a[i];
            ans = min(ans, max(s1, s2));
            s2 += b[i];
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

