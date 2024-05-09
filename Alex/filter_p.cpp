#include <bits/stdc++.h>
using namespace std;

#define int int64_t

const int INF = 2e18;
int n, q;
const int max_n = 1000;
bool is_red[max_n];
vector<int> a, queries;

int work(int k) {
    auto b = a;
    if (k <= n) {
        for (int i = 0; i < k; i++) b[i] += k-i;
        return *min_element(begin(b), end(b));
    }
    if ((k-n) % 2 == 0) {
        for (int i = 0; i < n; i++) b[i] += k-i;
        int sum = 0; for (auto x : b) sum += x;
        int ans = min((sum-(k-n)/2)/n, *min_element(begin(b), end(b)));
        return ans;
    } else {
        for (int i = 0; i < n-1; i++) b[i] += k-i;
        int sum = 0; for (auto x : b) sum += x;
        int ans = min((sum-(k-n+1)/2)/n, *min_element(begin(b), end(b)));
        return ans;
    }
}

void solve() {
    cin >> n >> q;
    a.resize(n); for (auto& x : a) cin >> x;
    queries.resize(q); for (auto& x : queries) cin >> x;
    sort(begin(a), end(a));

    for (auto k : queries) cout << work(k) << ' ';
    cout << '\n';
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(0);
    solve();
}

