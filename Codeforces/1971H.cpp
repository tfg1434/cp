// clean 2sat impl

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

struct two_sat {
    int n, num_scc;
    V<vi> g;
    vi scc;
    two_sat(int n) : g(2*n), scc(2*n) {
        this->n = n;
        num_scc = 0;
    }
    void kosaraju() {
        vi s;
        vb vis(2*n);
        auto dfs = [&](auto&& dfs, int u) -> void {
            vis[u] = true;
            for (int v : g[u]) if (!vis[v]) dfs(dfs, v);
            s.pb(u);
        };
        for (int i = 0; i < 2*n; i++) if (!vis[i]) dfs(dfs, i);

        V<vi> rev(2*n); 
        for (int i = 0; i < 2*n; i++) for (int j : g[i])
            rev[j].pb(i);
        auto dfs2 = [&](auto&& dfs2, int u) -> void {
            for (int v : rev[u]) if (!scc[v]) {
                scc[v] = scc[u];
                dfs2(dfs2, v);
            }
        };
        while (s.size()) {
            if (!scc[s.back()]) {
                scc[s.back()] = ++num_scc;
                dfs2(dfs2, s.back()); 
            }
            s.pop_back();
        }
    }
    bool satisfiable() {
        for (int i = 0; i < n; i++) {
            if (scc[i] == scc[i+n]) return false;
        }
        return true;
    }

    void add_edge(int p, int q) {
        g[p].pb(q);
    }
    void add_clause_or(int i, bool ni, int j, bool nj) {
        add_edge(i + (ni ? n : 0), j + (nj ? 0 : n));
        add_edge(j + (nj ? n : 0), i + (ni ? 0 : n));
    }
    void add_clause_xor(int i, bool ni, int j, bool nj) {
        add_clause_or(i, ni, j, nj);
        add_clause_or(i, !ni, j, !nj);
    }
};

int n;
V<vi> inp;

void solve() {
    cin >> n;
    inp = V<vi>(3, vi(n));
    vi labels;
    for (int i = 0; i < 3; i++) for (int j = 0; j < n; j++) {
        cin >> inp[i][j];
        labels.pb(abs(inp[i][j]));
    }
    sort(all(labels));
    labels.erase(unique(all(labels)), end(labels));

    two_sat sat(n+1);
    for (int j = 0; j < n; j++) {
        sat.add_clause_or(abs(inp[0][j]), inp[0][j]<0, abs(inp[1][j]), inp[1][j]<0);
        sat.add_clause_or(abs(inp[1][j]), inp[1][j]<0, abs(inp[2][j]), inp[2][j]<0);
        sat.add_clause_or(abs(inp[0][j]), inp[0][j]<0, abs(inp[2][j]), inp[2][j]<0);
    }
    sat.kosaraju();
    cout << (sat.satisfiable() ? "YES" : "NO") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
