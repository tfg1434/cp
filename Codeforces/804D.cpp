// i don't SEE IT

#include <bits/stdc++.h>
using namespace std;
using db = long double;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

const int max_n = 1e5;
int n, m, q, vis[max_n], num, max_dep[max_n];
vi com[max_n], g[max_n], pre[max_n];

void dfs1(int u, int p) {
    for (int v : g[u]) if (v != p) {
        dfs1(v, u);
        ckmax(max_dep[u], max_dep[v]+1);
    }
}
void dfs(int u, int p, int super) {
    vis[u] = num;
    int mx = 0, mx_ind = -1, smx = 0;
    for (int v : g[u]) if (v != p) {
        if (ckmax(mx, max_dep[v]+1)) {
            mx_ind = v;
        } else {
            ckmax(smx, max_dep[v]+1);
        }
    }
    for (int v : g[u]) if (v != p) {
        int new_super = max(super+1, v == mx_ind ? smx+1 : mx+1);
        dfs(v, u, new_super);
    }
    com[num].pb(max(max_dep[u], super));
}

void solve() {
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }

    for (int i = 0; i < n; i++) if (!vis[i]) {
        num++;
        dfs1(i, -1);
        dfs(i, -1, 0);
    }
    for (int i = 1; i <= num; i++) {
        sort(all(com[i]));
        pre[i].resize(com[i].size()+1);
        for (int j = 0; j < com[i].size(); j++) {
            pre[i][j+1] = pre[i][j]+com[i][j];
        }
    }

    map<array<int, 2>, db> check;
    while (q--) {
        int u, v; cin >> u >> v; u--; v--;
        if (com[vis[u]].size() > com[vis[v]].size()) swap(u, v);
        int U = vis[u], V = vis[v];
        if (u == v) {
            cout << -1 << '\n';
            continue;
        }
        if (U == V) {
            cout << -1 << '\n';
            continue;
        }

        if (check.count({U, V})) {
            cout << check[{U, V}] << '\n';
            continue;
        }
        ps(com[U], com[V]);
        int D = max(com[U].back(), com[V].back());
        for (int f : com[U]) {
            int fi = lwb(com[V], D-f-1 );
            check[{U, V}] += D*fi + (f+1)*(com[V].size()-fi) + pre[V].back() - pre[V][fi];
        }
        check[{U, V}] /= com[U].size()*com[V].size();
        cout << check[{U, V}] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6);
    solve();
    return 0;
}
