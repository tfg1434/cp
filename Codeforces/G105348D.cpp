#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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
#define pct __builtin_popcountll 
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

void solve() {
    int n, V, K; cin >> n >> V >> K;
    string s; cin >> s;
    vector d(n, vi(n, inf));
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (s[i] == s[j]) d[i][j] = d[j][i] = K;
            else d[i][j] = d[j][i] = j-i;
        }
    }

    auto dij = [&](int s) {
        vi dist(n, inf);
        vb in_cut(n);
        dist[s] = 0;
        for (int i = 0; i < n-1; i++) {
            int u, mn_d = inf;
            for (int j = 0; j < n; j++) if (!in_cut[j] && ckmin(mn_d, dist[j])) {
                u = j;
            }
            in_cut[u] = true;
            for (int j = 0; j < n; j++) if (!in_cut[j]) {
                ckmin(dist[j], dist[u]+d[u][j]);
            }
        }
        return dist;
    };

    auto dist = dij(V);
    for (int i = 0; i < n; i++) cout << dist[i] << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
