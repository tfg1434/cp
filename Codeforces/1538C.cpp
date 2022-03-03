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
        int n, l, r; cin >> n >> l >> r;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        sort(all(a));

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += upper_bound(all(a), r - a[i]) - a.begin();
            ans -= lower_bound(all(a), l - a[i]) - a.begin();

            //double counted the same pair values
            if (l <= 2 * a[i] && 2 * a[i] <= r) ans--;
        }

        cout << ans / 2 << '\n';
    }    
    
    return 0;
}

