#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

int n, m;
const int max_n = 5e4;
set<int> sub[max_n];
int ans[max_n];
V<array<int, 2>> g[max_n];
V<array<int, 2>> chips_here[max_n];
set<array<int, 2>> chips[max_n];

void dfs(int u, int p, int pe_ind) {
    sub[u].insert(u);
    chips[u] = set<array<int, 2>>(all(chips_here[u]));
    
    for (auto [v, ind] : g[u]) if (v != p) {
        dfs(v, u, ind);
        if (sub[v].size() > sub[u].size()) swap(sub[u], sub[v]);
        for (auto w : sub[v]) sub[u].insert(w); sub[v].clear();
        if (chips[v].size() > chips[u].size()) swap(chips[u], chips[v]);
        for (auto chip : chips[v]) {
            auto found = chips[u].find(chip);
            if (found != end(chips[u])) chips[u].erase(chip);
            else chips[u].insert(chip);
        }

    }

    if (pe_ind != -1) {
        if (!chips[u].size()) ans[pe_ind] = -1;
        else ans[pe_ind] = (*begin(chips[u]))[0];
    }
}

void solve() {
    if (fopen("disrupt.in", "r")) {
        freopen("disrupt.in", "r", stdin);
        freopen("disrupt.out", "w", stdout);
    }

    cin >> n >> m; 
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb({v, i}); g[v].pb({u, i});
    }
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        chips_here[u].pb({w, i}); chips_here[v].pb({w, i});
    }
    dfs(0, -1, -1);

    for (int i = 0; i < n-1; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
