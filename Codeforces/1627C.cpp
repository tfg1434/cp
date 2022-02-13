#include <bits/stdc++.h>
using namespace std;

int T;

#define ll long long

int toggle(int x) {
    return x == 2 ? 3 : 2;
}

void solve() {
    int n; cin >> n;
    vector<vector<pair<int, int>>> a(n);
    vector<int> degree(n), ans(n-1);

    for (int i = 0; i < n - 1; i++) {
        int u, v; cin >> u >> v;
        a[--u].push_back({--v, i});
        a[v].push_back({u, i});
        degree[u]++; degree[v]++;
    }

    if (*max_element(degree.begin(), degree.end()) > 2) {
        cout << -1 << endl;
        return;
    }

    function<void(int, int, int)> dfs = [&](int node, int prev, int w) {
        for (auto& [u, i] : a[node]) {
            if (u == prev) continue;

            ans[i] = w;
            dfs(u, node, toggle(w));
        }
    };
    dfs(min_element(degree.begin(), degree.end()) - degree.begin(), -1, 2);
    for (auto i : ans) cout << i << ' ';
    cout << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        solve();
    }    
    
    return 0;
}

