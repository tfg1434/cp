#include <bits/stdc++.h>
using namespace std;

#define int long long

int C(int x) {
    return x * (x - 1) / 2;
}

void solve() {
    int n, b, g;
    cin >> n >> b >> g;
    vector<int> c(n);
    for (int i = 0; i < n; ++i) {
        cin >> c[i];
    }
    sort(c.begin(), c.end(), greater<int>());

    auto calc = [&](int k) {
        int res = 0;
        for (int x : c) {
            int cont = C(x);
            cont -= C(x / k + 1) * (x % k);
            cont -= C(x / k) * (k - x % k);
            res += cont * b;
        }
        res -= (k - 1) * g;
        return res;
    };

    int ans = 0;
    int lo = 1, hi = accumulate(c.begin(), c.end(), 0) + 1;
    while (lo < hi) {
        int m = (lo + hi) / 2;
        if (calc(m) > calc(m + 1)) {
            hi = m;
        } else {
            lo = m + 1;
        }
    }
    cout << calc(lo) << endl;

    // Alternative approach using a loop
    // for (int k = 1; k < accumulate(c.begin(), c.end(), 0) + 1; ++k) {
    //     ans = max(ans, calc(k));
    // }
    // cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}

