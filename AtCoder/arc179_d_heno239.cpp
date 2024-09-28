#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

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

int ans = inf;
V<vi> g, sons;

// {wo return, w return, size, depth}
using Data = array<int, 4>;
V<V<Data>> datas;
Data merge(Data a, Data b) {
    return Data {
        min({ a[1]+b[1], a[0]+b[1], a[1]+b[0] }),
        a[1]+b[1],
        a[2]+b[2],
        max(a[3], b[3])
    };
};

Data precalc(int u, int p) {
    Data res = {0, 0, 1, 0};
    for (int v : g[u]) if (v != p) {
        Data nex = precalc(v, u);
        nex[0]++;
        nex[1] += 2;
        nex[3]++;
        int no_gate = 2*nex[2]-nex[3];
        ckmin(nex[0], no_gate);
        ckmin(nex[1], no_gate);
        sons[u].pb(v);
        datas[u].pb(nex);
        res = merge(res, nex);
    }
    ps(sons[u]);
    return res;
}

void reroot(int u, int p, Data super) {
    auto nei_data = datas[u];
    if (p != -1) nei_data.pb(super);
    int m = nei_data.size();
    Data cost_as_root = {0, 0, 1, 0};
    for (int i = 0; i < m; i++) {
        cost_as_root = merge(cost_as_root, nei_data[i]);
        ckmin(ans, min(cost_as_root[0], cost_as_root[1]));
    }

    V<Data> left(m+1), right(m+1);
    for (int i = 0; i < m; i++) {
        left[i+1] = merge(left[i], nei_data[i]);
    }
    for (int i = m-1; i >= 0; i--) {
        right[i] = merge(nei_data[i], right[i+1]);
    }

    for (int i = 0; i < sons[u].size(); i++) {
        int v = sons[u][i];
        Data new_super = merge(left[i], right[i+1]);
        ps("node", v,  "new super", new_super);
        new_super[0]++;
        new_super[1] += 2;
        new_super[2]++;
        new_super[3]++;
        int no_gate = 2*new_super[2]-new_super[3];
        ckmin(new_super[0], no_gate);
        ckmin(new_super[1], no_gate);
        reroot(v, u, new_super);
    }
}

void solve() {
    int n; cin >> n;
    g.resize(n);
    sons.resize(n);
    datas.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    precalc(0, -1);
    reroot(0, -1, {0, 0, 0, 0});
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
