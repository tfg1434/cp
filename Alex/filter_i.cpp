#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

int n;
vector<int> a, res;
int cnt[20];
void count() {
    for (int j = 0; j < 20; j++) {
        for (auto x : a) if (x & (1 << j)) cnt[j]++;
    }
}
i64 ans;

void solve() {
    cin >> n;
    a.resize(n); for (auto& x : a) cin >> x; 
    count();
    res.resize(n);
    for (int j = 0; j < 20; j++) {
        for (int i = 0; i < cnt[j]; i++) {
            res[i] += 1 << j;
        }
    }

    for (int i = 0; i < n; i++) ans += (i64)res[i]*res[i];
    cout << ans << '\n';
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(0);
    solve();
}
