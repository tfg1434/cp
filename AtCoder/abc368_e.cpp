#include <bits/stdc++.h>
using namespace std;

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

struct Train {
    int a, b, s, t, ind;
};

V<V<Train>> g;
vi x;

void dfs(int u, int old_arrival, int new_arrival) {
    for (Train train : g[u]) if (old_arrival <= train.s && new_arrival > train.s) {
        int delta = new_arrival-train.s;
        x[train.ind] += delta;
        train.s += delta;
        train.t += delta;
        dfs(train.b, train.t-delta, train.t);
    }
}

void solve() {
    int n, m, x0; cin >> n >> m >> x0;
    x.resize(m);
    g.resize(n);

    int first_train_g_ind, first_train_u;
    for (int i = 0; i < m; i++) {
        int a, b, s, t; cin >> a >> b >> s >> t; a--; b--;
        Train train = Train{a, b, s, t, i};
        if (!i) {
            first_train_g_ind = g[a].size();
            first_train_u = a;
        }
        g[a].pb(train);
    }
    Train& first_train = g[first_train_u][first_train_g_ind];

    first_train.s += x0;
    first_train.t += x0;
    dfs(first_train.b, first_train.t-x0, first_train.t);

    for (int i = 1; i < m; i++) {
        cout << x[i] << " \n"[i==m-1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
