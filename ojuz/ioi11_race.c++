#include <bits/stdc++.h>
#include "race.h"
using namespace std;
#define int int64_t
const int inf = 2e18;

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
array<int, 2> inp_e[max_n];
int inp_w[max_n];
int ans = inf;
map<int, int> sub[max_n];
V<array<int, 2>> g[max_n];
int W[max_n], L[max_n];

void precomp(int u, int p, int cur_w, int cur_l) {
    W[u] = cur_w;
    L[u] = cur_l;
    sub[u][cur_w] = cur_l;
    for (auto [w, v] : g[u]) if (v != p) {
        precomp(v, u, cur_w+w, cur_l+1);
    }
}

void dfs(int u, int p) {
    int target = k + 2*W[u];

    for (auto [w, v] : g[u]) if (v != p) {
        dfs(v, u);
        if (sub[v].size() > sub[u].size()) swap(sub[u], sub[v]);

        for (auto [ww, zz] : sub[v]) {
            auto found = sub[u].find(target-ww);
            if (found != end(sub[u]))
                ans = min(ans, zz+found->s - 2*L[u]);
        }
        for (auto [ww, zz] : sub[v]) {
            auto found = sub[u].find(ww);
            if (found == end(sub[u])) sub[u].insert({ww, zz});
            else sub[u][ww] = min(sub[u][ww], zz);
        }
    }
}

void read() {
    cin >> n >> k;
    for (int i = 0; i < n-1; i++) cin >> inp_e[i][0] >> inp_e[i][1];
    for (int i = 0; i < n-1; i++) cin >> inp_w[i];
}

void solve() {
    for (int i = 0; i < n-1; i++) {
        g[inp_e[i][0]].pb({inp_w[i], inp_e[i][1]});
        g[inp_e[i][1]].pb({inp_w[i], inp_e[i][0]});
    }
    precomp(0, -1, 0, 0);
    dfs(0, -1);
    if (ans == inf) ans = -1;
}

#undef int
int best_path(int N, int K, int INP_E[][2], int INP_W[]) {
    // ::n = n;
    // ::k = k;
    n = N;
    k = K;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < 2; j++)
            inp_e[i][j] = INP_E[i][j];
        inp_w[i] = INP_W[i];
    }
    read();
    solve();
    return ans;
}

// signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    // read();
    // solve();
    // cout << ans << '\n';
    // return 0;
// }
