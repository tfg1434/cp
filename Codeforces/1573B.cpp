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
        vector<int> a(2*n), b(n);
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            a[x] = i;
        }
        for (auto& i : b) cin >> i;

        int ans = 2 * n;
        int idx = 0;
        for (int i = 1; i < 2*n; i += 2) {
            while (b[idx] < i) idx++;
            ans = min(ans, a[i] + idx);
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

