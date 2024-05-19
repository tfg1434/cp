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

const int max_k = 5, max_n = 5e4;
int k, n, m, q, jump[16][max_n][max_k][max_k];

void solve() {
    cin >> k >> n >> m >> q; 

    for (int stp = 0; stp < 16; stp++) {
        for (int i = 0; i < n; i++) {
            for (int x = 0; x < k; x++) {
                for (int y = 0; y < k; y++) {
                    jump[stp][i][x][y] = inf;
                }
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w;
        jump[0][u/k][u%k][v%k] = w;
    }

    for (int stp = 1; stp < 16; stp++) {
        for (int i = 0; i < (n-1)/k; i++) if (i + (1 << (stp-1)) <= (n-1)/k){
            for (int z = 0; z < k; z++) {
                for (int x = 0; x < k; x++) {
                    for (int y = 0; y < k; y++) {
                        jump[stp][i][x][y] = min(jump[stp][i][x][y], jump[stp-1][i][x][z]+jump[stp-1][i+(1 << (stp-1))][z][y]);
                    }
                }
            }
        }
    }

    for (int i = 0; i < q; i++) {
        vi dist(k, inf);
        int u, v; cin >> u >> v;
        int gap = v/k - u/k;
        int pos = u/k;
        int x = u%k;
        dist[x] = 0;
        for (int stp = 15; stp >= 0; stp--) if (gap & (1 << stp)) {
            auto DIST = dist;
            dist.assign(k, inf);
            for (int z = 0; z < k; z++) {
                for (int y = 0; y < k; y++) {
                    dist[y] = min(dist[y], DIST[z]+jump[stp][pos][z][y]);
                }
            }
            pos += 1 << stp;
        }

        int ans = dist[v%k];
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
