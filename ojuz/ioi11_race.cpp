// i learned that this will be much easier to write if you do stuff relative to root
// instead of maintaining offset sets.
// see .c++ for AC code

#include <bits/stdc++.h>
#include "race.h"
using namespace std;
const int inf = 1e9;

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


const int max_n = 2e5;
int n, k;
// array<int, 2> h[max_n];
// int weights[max_n];
int ans = inf;
set<array<int, 2>> dists[max_n]; // sum of weights, len
array<int, 2> off[max_n]; // sum of weights, len
V<array<int, 2>> g[max_n];

void dfs(int u, int p) {
    dists[u].insert({0, 0});
    for (auto [w, v] : g[u]) if (v != p) {
        dfs(v, u);
        if (dists[v].size() > dists[u].size()) {
            swap(dists[u], dists[v]);
            swap(off[u], off[v]);
        }
        for (auto [W, L] : dists[v]) {
            W += off[v][0]+w;
            L += off[v][1]+1;
            auto found = dists[u].lb({k-W-off[u][0], 0-off[u][1]});
            if (found != end(dists[u]) && (*found)[0]+off[u][0] == k-W)
                ans = min(ans, (*found)[1]+off[u][1]+L);
            dists[u].insert({W-off[u][0], L-off[u][1]});
        }
    }
}

// void solve() {
    // cin >> n >> k;
    // for (int i = 0; i < n-1; i++) cin >> h[i][0] >> h[i][1];
    // for (int i = 0; i < n-1; i++) cin >> weights[i];
    // for (int i = 0; i < n-1; i++) {
        // g[h[i][0]].pb({weights[i], h[i][1]});
        // g[h[i][1]].pb({weights[i], h[i][0]});
    // }
    // dfs(0, -1);
    // cout << ans << '\n';
// }

int best_path(int N, int K, int h[][2], int weights[]) {
    // ::n = n;
    // ::k = k;
    n = N;
    k = K;
    for (int i = 0; i < n-1; i++) {
        g[h[i][0]].pb({weights[i], h[i][1]});
        g[h[i][1]].pb({weights[i], h[i][0]});
    }
    dfs(0, -1);
    if (ans == inf) ans = -1;
    return ans;
}

// signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    // solve();
    // return 0;
// }
