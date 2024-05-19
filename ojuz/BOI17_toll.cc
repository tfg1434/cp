// segment tree approach
// WA, i didn't want to debug

#include <bits/stdc++.h>
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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }

const int max_k = 5, max_n = 5e4, max_q = 1e4;
int k, n, m, q;
V<array<int, 2>> g[max_n][max_k];
V<V<vi>> t; // node, class a, class b = dist
V<vi> zero;
bool is_zero(const V<vi>& vec) {
    for (int i = 0; i < k; i++) for (int j = 0; j < k; j++)
        if (vec[i][j] != 0) return false;
    return true;
}

void build(int v, int l, int r) {
    if (l == r-1) {
        for (int my_class = 0; my_class < k; my_class++)
            t[v][my_class][my_class] = 0;
        return;
    }
    int m = (l+r)/2;
    build(2*v+1, l, m);
    build(2*v+2, m, r);
    for (int l_class = 0; l_class < k; l_class++) {
        for (int lm_class = 0; lm_class < k; lm_class++) {
            for (auto [w, rm_class] : g[m-1][lm_class]) {
                for (int r_class = 0; r_class < k; r_class++) {
                    t[v][l_class][r_class] = min(t[v][l_class][r_class], 
                            t[2*v+1][l_class][lm_class]+w+t[2*v+2][rm_class][r_class]);
                }
            }
        }
    }
}
V<vi> query(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return zero;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    V<vi> res(k, vi(k, inf));
    auto lv = query(2*v+1, l, m, L, R);
    auto rv = query(2*v+2, m, r, L, R);
    if (is_zero(lv)) return rv;
    if (is_zero(rv)) return lv;
    for (int l_class = 0; l_class < k; l_class++) {
        for (int lm_class = 0; lm_class < k; lm_class++) {
            for (auto [w, rm_class] : g[m-1][lm_class]) {
                for (int r_class = 0; r_class < k; r_class++) {
                    res[l_class][r_class] = min(res[l_class][r_class], 
                            lv[l_class][lm_class]+w+rv[rm_class][r_class]);
                }
            }
        }
    }
    return res;
}
void init_tree() {
    int size = 1;
    while (size < 2*((n-1)/k+1)) size *= 2;
    t = V<V<vi>>(size, V<vi>(k, vi(k, inf)));
    build(0, 0, (n-1)/k+1);
}

void solve() {
    cin >> k >> n >> m >> q; 
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        g[u/k][u%k].pb({w, v%k});
    }
    zero = V<vi>(k, vi(k));
    init_tree();

    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v;
        auto res = query(0, 0, (n-1)/k+1, u/k, v/k+1);
        int ans = res[u%k][v%k];
        if (ans == inf) ans = -1;
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
