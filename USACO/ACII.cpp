#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INFF = 1e18;
int main() {
    ll n, m; cin >> n >> m;
    vector<ll> need(101, 0);
    vector<ll> s(n), t(n), c(n);
    for (ll i = 0; i < n; i++) {
        cin >> s[i] >> t[i] >> c[i];
        for (ll j = s[i]; j <= t[i]; j++) {
            need[j]+=c[i];
        }
    }
    vector<ll> a(m), b(m), p(m), d(m);
    for (ll i = 0; i < m; i++) {
        cin >> a[i] >> b[i] >> p[i] >> d[i];
    }

    ll ans = INFF;
    for (ll i = 0; i < (1 << m); i++) {
        vector<ll> me(101, 0);
        ll cost = 0;
        for (ll j = 0; j < m; j++) {
            if (1 & (i >> j)) {
                for (ll k = a[j]; k <= b[j]; k++) {
                    me[k] += p[j];
                }
                cost += d[j];
            }
        }

        bool ok = true;
        for (ll j = 1; j <= 100; j++) {
            if (me[j] < need[j]) {
                ok = false;
                break;
            }
        }

        if (ok) {
            if (cost < ans) {
                ans = min(ans, cost);
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}
