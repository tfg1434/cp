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
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
template<class T> using pqg = priority_queue<T, V<T>, greater<T>>;

using pt = array<int, 2>;
const int max_n = 7, max_m = 5e3, max_q = 3e4;
int n, m, q, a[max_n][max_m], ans[max_q];
array<pt, 2> queries[max_q];
int dist[max_n][max_n][max_m];


void dij(int m, int l, int r) {
    auto in_range = [&](int x, int y) { return 0 <= x && x < n && l <= y && y < r; };

    for (int i = 0; i < n; i++) for (int x = 0; x < n; x++) for (int y = l; y < r; y++)
        dist[i][x][y] = inf;

    for (int i = 0; i < n; i++) {
        pqg<pair<int, pt>> q;
        dist[i][i][m] = a[i][m]; q.push({a[i][m], {i, m}});
        while (q.size()) {
            auto [d, u] = q.top(); q.pop();
            auto [x, y] = u;
            if (dist[i][x][y] != d) continue;
            for (int dx : {-1, 0, 1}) for (int dy : {-1, 0, 1}) if (abs(dx)+abs(dy) == 1) {
                int nx = x+dx, ny = y+dy;
                if (!in_range(nx, ny)) continue;
                if (ckmin(dist[i][nx][ny], dist[i][x][y]+a[nx][ny])) {
                    q.push({dist[i][nx][ny], {nx, ny}});
                }
            }
        }
    }
}

void dnc(int l, int r, vi query_inds) {
    int m = (l+r)/2;
    dij(m, l, r);

    vi todo[2];
    for (auto ind : query_inds) {
        auto p = queries[ind][0], q = queries[ind][1];
        auto [r0, c0] = p;
        auto [r1, c1] = q;
        for (int i = 0; i < n; i++) {
            ckmin(ans[ind], dist[i][r0][c0]+dist[i][r1][c1]-a[i][m]);
        }

        if (c1 < m) todo[0].pb(ind);
        if (c0 >= m) todo[1].pb(ind);
    }
    if (l < r-1) {
        dnc(l, m, todo[0]);
        dnc(m, r, todo[1]);
    }
}

void solve() {
    fill(all(ans), inf);

    cin >> n >> m;    
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    cin >> q;
    for (int i = 0; i < q; i++) {
        int r0, c0, r1, c1; cin >> r0 >> c0 >> r1 >> c1;
        if (c0 > c1) swap(r0, r1), swap(c0, c1);
        queries[i] = {pt{r0, c0}, pt{r1, c1}};
    }

    vi query_inds(q); iota(all(query_inds), 0);
    dnc(0, m, query_inds);
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
