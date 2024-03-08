#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve() {
    int T, G;
    cin >> T >> G;
    int n;
    cin >> n;

    vector<complex<int>> p;
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        int x, y;
        cin >> x >> y;
        p.push_back(complex<int>(x, y));
        ans.push_back(i + 1);
        if (i < 2)
            continue;

        for (int j = i; j > 1; --j) {
            auto a = p[j - 2] - p[j - 1];
            auto b = p[j] - p[j - 1];
            if (a.real() * b.real() + a.imag() * b.imag() <= 0) {
                swap(p[j], p[j - 1]);
                swap(ans[j], ans[j - 1]);
            }
        }
    }
    
    for (int x : ans)
        cout << x << " ";
    cout << endl;
}

signed main() {
    solve();
    return 0;
}

