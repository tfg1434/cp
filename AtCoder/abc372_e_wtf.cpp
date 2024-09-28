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
#define len(x) (int)((x).size())
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

vi par;
V<set<int>> nodes;

int find(int u) {
    if (par[u] == u) return u;
    return par[u] = find(par[u]);
}

void unite(int u, int v) {
    if ((u=find(u)) != (v=find(v))) {
        if (len(nodes[u]) < len(nodes[v])) swap(u, v);
        for (int w : nodes[v]) nodes[u].ins(w);
        par[v] = u;
    }
}

void solve() {
    int n, q; cin >> n >> q;    
    par.rsz(n+1);
    nodes.rsz(n+1);
    for (int i = 1; i <= n; i++) {
        par[i] = i;
        nodes[i].ins(i);
    }
    while (q--) {
        int typ; cin >> typ;
        if (typ == 1) {
            int u, v; cin >> u >> v; 
            unite(u, v);
        } else {
            int u, k; cin >> u >> k;
            u = find(u);
            if (len(nodes[u]) < k) {
                cout << "-1\n";
                continue;
            }
            auto it = end(nodes[u]);
            for (int i = 0; i < k; i++) it--;
            cout << *it << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
