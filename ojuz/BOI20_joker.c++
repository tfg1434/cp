// 0pts I am so bad at this

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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

struct DSU {
    vi e, d;
    V<pair<int&, int>> his;
    DSU() {}
    DSU(int n) : e(n, -1), d(n, 0) {}
    array<int, 2> find(int u) {
        int dis = 0;
        while (e[u] >= 0) dis ^= d[u], u = e[u];
        return {u, dis};
    }
    void modify(int& x, int y) {
        his.pb({x, y});
        x = y;
    }
    void rollback(int until) {
        while (his.size() > until) {
            his.back().f = his.back().s;
            his.pop_back();
        }
    }
    bool unite(int u, int v) {
        auto [U, P] = find(u);
        auto [V, Q] = find(v);
        if (e[U] > e[V]) swap(U, V), swap(P, Q);
        if (U == V) return P != Q;
        modify(e[U], e[U]+e[V]);
        modify(e[V], U);
        modify(d[V], P^Q^1);
        return true;
    }
};

int n, m, q;
DSU dsu;
V<array<int, 2>> edges;
vi last;

void dnc(int l, int r, int y) {
    if (l == r) return;

    int m = (l+r)/2;
    int x = dsu.his.size();
    for (int i = l; i < m; i++) dsu.unite(edges[i][0], edges[i][1]);

    int x1 = dsu.his.size();
    int y0 = y;
    while (y0 > m && dsu.unite(edges[y0-1][0], edges[y0-1][1]))
        y0--;
    dsu.rollback(x1);
    last[m] = y0;
    dsu.unite(edges[m][0], edges[m][1]);
    dnc(m+1, r, y);

    dsu.rollback(x);
    for (int i = y0; i < y; i++) dsu.unite(edges[i][0], edges[i][1]);
    dnc(l, m, y0);
    dsu.rollback(x);
}

void solve() {
    cin >> n >> m >> q;    
    dsu = DSU(n);
    edges.resize(m);
    last.resize(m);

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--; edges[i][1]--;
    }
    int x = 0;
    while (x < m && dsu.unite(edges[x][0], edges[x][1])) x++;
    for (int i = x+1; i < m; i++) last[i] = m+1;
    dsu.rollback(0);
    dnc(0, min(m, x+1), m);
    ps(last);

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--;
        cout << (last[l] > r ? "YES" : "NO") << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
