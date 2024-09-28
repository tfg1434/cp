#include <bits/stdc++.h>
using namespace std;
#define int int64_t

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

const int K = 450;

void solve() {
    int n, m; cin >> n >> m;
    V<vi> G(n);
    V<array<int, 2>> T(m);
    for (auto& [t, u] : T) {
        cin >> t >> u; u--;
        G[u].pb(t);
    }

    V<vi> pre(n);
    for (int u = 0; u < n; u++) if (G[u].size() > K) {
        vi res(n), ps(m), tin(n);

        for (int i = 0; i < m; i++) {
            auto [t, v] = T[i];
            if (i > 0) {
                ps[i] = ps[i-1];
                if (tin[u]) {
                    ps[i] += t-T[i-1][0];
                }
            }

            if (!tin[v]) {
                tin[v] = i;

            } else {
                res[v] += ps[i]-ps[tin[v]];
                tin[v] = 0;
            }
        }
        pre[u] = res;
    }

    for (int u = 0; u < n; u++) reverse(all(G[u]));
    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int u, v; cin >> u >> v; u--; v--;
        if (pre[u].empty()) swap(u, v);
        if (!pre[u].empty()) {
            cout << pre[u][v] << '\n';
            return;
        }

        auto A = G[u], B = G[v];
        int inter = 0;
        while (!A.empty() && !B.empty()) {
            if (end(A)[-2] > end(B)[-2]) swap(A, B);
            if (end(A)[-2] > end(B)[-1]) {
                inter += end(A)[-2] - max(end(A)[-1], end(B)[-1]);
            }
            A.pop_back(); A.pop_back();
        }
        cout << inter << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}


