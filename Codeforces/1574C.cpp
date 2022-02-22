#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(all(a));
    int m; cin >> m;
    vector<pair<int, int>> b(m);
    for (auto& i : b) cin >> i.first >> i.second;
    ll sum = accumulate(all(a), 0LL);

    for (int t = 0; t < m; t++) {
        ll x = b[t].first, y = b[t].second;
        ll ans = LLONG_MAX;
        int idx = lower_bound(all(a), x) - a.begin();
        if (idx > 0) ans = min(ans, (x-a[idx-1]) + max(0ll, y - sum + a[idx-1]));
        if (idx < n) ans = min(ans, max(0ll, y - sum + a[idx]));

        cout << ans << '\n';
    }
    
    return 0;
}

