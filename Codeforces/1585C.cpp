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
        int n, k; cin >> n >> k;
        vector<int> a(n);
        for (auto& i : a) cin >> i;
        sort(all(a));
        ll ans = 0;
        //dont need to go back
        ans -= max(abs(a[0]), abs(a[a.size() - 1]));

        int temp = -1;
        for (int i = 0; i < n; i++) {
            if (a[i] < 0) temp = i;
        }

        int b = 0;
        while (b <= temp) {
            ans += 2 * abs(a[b]);
            b += k;
        }
        b = n - 1;
        while (b > temp) {
            ans += 2 * a[b];
            b -= k;
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

