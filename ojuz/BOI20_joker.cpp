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
#define ASSERT(exp) do { if (!(exp)) while (true); } while(0)

const int max_n = 2e5;
int K = 1.8e4;
struct query {
    int l, r, ind;
    bool operator <(const query& o) const {
        if (l/K == o.l/K) return r > o.r;
        return l/K < o.l/K;
    }
};
V<query> queries[(max_n-1)/200 + 1];
int n, m, q, ans[max_n];
array<int, 2> edges[max_n];

array<int, 2> par[max_n];
int rnk[max_n];
void make_set(int u) {
    par[u] = {u, 0};
    rnk[u] = 0;
}
array<int, 2> find(int u) {
    if (u == par[u][0]) return par[u];
    auto res = find(par[u][0]);
    res[1] ^= par[u][1];
    return res;
}
bool is_bipartite;
V<pair<array<int, 2>&, array<int, 2>>> undo_par;
V<pair<bool&, bool>> undo_bipartite;
V<pair<int&, int>> undo_rnk;
void unite(int u, int v) {
    auto U = find(u), V = find(v);
    if (rnk[U[0]] < rnk[V[0]]) swap(U, V);
    undo_bipartite.pb({is_bipartite, is_bipartite});
    undo_par.pb({par[V[0]], par[V[0]]});
    undo_rnk.pb({rnk[U[0]], rnk[U[0]]});

    if (U[0] == V[0]) {
        if (U[1] == V[1]) {
            is_bipartite = false;
        }
    } else {
        int t = U[1]^V[1]^1;
        par[V[0]] = {U[0], t};
        if (rnk[U[0]] == rnk[V[0]]) rnk[U[0]]++;
    }
}
int snapshot() { return undo_par.size(); }
void rollback(int until) {
    while (undo_par.size() > until) {
        undo_par.back().f = undo_par.back().s;
        undo_bipartite.back().f = undo_bipartite.back().s;
        undo_rnk.back().f = undo_rnk.back().s;
        undo_par.pop_back();
        undo_bipartite.pop_back();
        undo_rnk.pop_back();
    }
}
void reset() {
    is_bipartite = true;
    for (int i = 0; i < n; i++) make_set(i);
}

void solve() {
    cin >> n >> m >> q;    
    if (q > 2000) K = 200;

    for (int i = 0; i < m; i++) {
        cin >> edges[i][0] >> edges[i][1];
        edges[i][0]--; edges[i][1]--;
    }

    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--;
        queries[l/K].pb({l, r, i});
    }
    for (int i = 0; i <= (m-1)/K; i++) sort(all(queries[i]));
    reset();
    for (int b = 0; b <= (m-1)/K; b++) {
        int l = b*K, r = m;
        for (int i = max((b-1)*K, 0); i < l; i++) unite(edges[i][0], edges[i][1]);
        for (auto [L, R, I] : queries[b]) {
            while (r > R) {
                r--;
                unite(edges[r][0], edges[r][1]);
            }
            int photo = snapshot();
            while (l < L) {
                unite(edges[l][0], edges[l][1]);
                l++;
            }
            ans[I] = !is_bipartite;
            rollback(photo);
            l = b*K;
        }
    }

    for (int i = 0; i < q; i++) cout << (ans[i] ? "YES" : "NO") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

