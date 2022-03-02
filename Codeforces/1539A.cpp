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
        ll n, x, t; cin >> n >> x >> t;
        ll m = min(t/x, n);
        // ll ans = max(0ll, n - t/x)*t/x + (min(n - 1ll, t/x - 1ll) * min(n, t/x)) / 2ll;
        ll ans = m * (2ll * n - 1ll - m) / 2ll;

        cout << ans << '\n';
    }    
    
    return 0;
}

