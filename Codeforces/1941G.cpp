#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int, int>>> g(n);
    vector<int> colours;
    for (int i = 0; i < m; ++i) {
        int u, v, c;
        cin >> u >> v >> c;
        colours.push_back(c);
        --u; --v;
        g[u].push_back({c, v});
        g[v].push_back({c, u});
    }

    int s, t;
    cin >> s >> t;
    --s; --t;
    if (s == t) {
        cout << 0 << endl;
        return;
    }

    map<pair<int, int>, int> dist;
    dist[{s, -1}] = 0;
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
    q.push({0, {s, -1}});
    while (!q.empty()) {
        auto [d, more] = q.top();
        q.pop();
        if (dist.count(more) && d != dist[more])
            continue;

        int u = more.first;
        int prv = more.second;

        for (auto [c, v] : g[u]) {
            if (!dist.count({v, c}) || d + (prv != c) < dist[{v, c}]) {
                dist[{v, c}] = d + (prv != c);
                q.push({dist[{v, c}], {v, c}});
            }
        }
    }

    int ans = INT_MAX;
    for (int c : colours) if (dist.count({t, c}))
        ans = min(ans, dist[{t, c}]);

    cout << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}

