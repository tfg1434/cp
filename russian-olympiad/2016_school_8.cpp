// WA test 9

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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

int n, m;
const int max_n = 2e5;
vi g[max_n];
set<int> sub[max_n], fin[max_n];
int lvl[max_n];

void precalc(int u) {
    for (int v : g[u]) {
        lvl[v] = lvl[u]+1;
        precalc(v);
    }
}
void finalize_sets(int u) {
    for (int v : g[u]) {
        finalize_sets(v);
        if (sub[v].size() > sub[u].size()) swap(sub[u], sub[v]);
        for (int dep : sub[v]) {
            sub[u].insert(dep);
            if (fin[u].count(dep)) fin[u].erase(dep);
        }
    }
}

int timer;
int listening[max_n]; // timer of this listening, 0 if not
int col[max_n];
void make_array(int u) {
    if (listening[lvl[u]]) {
        col[u] = listening[lvl[u]];
    }

    for (auto dep : fin[u]) listening[dep] = ++timer;
    for (int v : g[u]) make_array(v);
    for (auto dep : fin[u]) listening[dep] = 0;
}

const int max_m = 1e6;
int f[max_m+1];
int ans = inf, sol_l, sol_r;
void find_min_len() {
    int j = 0, colors = 0;
    for (int i = 0; i < n; i++) {
        while (j < n && colors < timer) {
            if (col[j]) {
                colors += f[col[j]] == 0;
                f[col[j]]++;
            }
            j++;
        }
        if (colors == timer && j-i < ans) {
            ans = j-i; sol_l = i; sol_r = j;
        }
        if (col[i]) {
            f[col[i]]--; colors -= !f[col[i]];
        }
    }
}

void solve() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int p; cin >> p; p--;
        g[p].pb(i);
    }
    precalc(0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        int u, k; cin >> u >> k; u--;
        sub[u].insert(lvl[u]+k); fin[u].insert(lvl[u]+k);
    }
    finalize_sets(0);
    make_array(0);
    find_min_len();
    cout << sol_l+1 << ' ' << sol_r << '\n';
}

signed main() {
    if (fopen("qual.in", "r")) {
        freopen("qual.in", "r", stdin);
        freopen("qual.out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
