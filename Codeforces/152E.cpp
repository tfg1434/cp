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

template<class F> struct y_combinator_result {
    F f;
    template<class T> explicit y_combinator_result(T &&f): f(std::forward<T>(f)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return f(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) yy(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define pct __builtin_popcountll
constexpr int p2(int x) { return (int)1 << x; }

void solve() {
    int n, m, k; cin >> n >> m >> k;

    auto dxy = [&](int i, int j) {
        V<array<int, 2>> res;
        for (int di : {-1, 0, 1}) for (int dj : {-1, 0, 1}) if (abs(di)+abs(dj) == 1) {
            int ni = i+di, nj = j+dj;
            if (0 <= ni && ni < n && 0 <= nj && nj < m) {
                res.pb({ni, nj});
            }
        }
        return res;
    };

    vector a(n, vi(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    V<array<int, 2>> imp_coord(k);
    V<vi> coord_to_imp(n, vi(m, -1));
    for (int i = 0; i < k; i++){
        int x, y; cin >> x >> y; x--; y--;
        imp_coord[i] = {x, y};
        coord_to_imp[x][y] = i;
    }

    vector dist(n, V<V<vi>>(m, V<vi>(n, vi(m, inf))));
    vector path(n, V<V<V<array<int, 2>>>>(m, V<V<array<int, 2>>>(n, V<array<int, 2>>(m, {-1, -1}))));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        dist[i][j][i][j] = a[i][j];
        for (auto [ni, nj] : dxy(i, j)) {
            dist[i][j][ni][nj] = dist[ni][nj][i][j] = a[i][j]+a[ni][nj];
            path[i][j][ni][nj] = {i, j};
            path[ni][nj][i][j] = {ni, nj};
        }
    }

    for (int ki = 0; ki < n; ki++) for (int kj = 0; kj < m; kj++) {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            for (int I = 0; I < n; I++) for (int J = 0; J < m; J++) {
                if (ckmin(dist[i][j][I][J], dist[i][j][ki][kj]+dist[ki][kj][I][J]-a[ki][kj])) {
                    path[i][j][I][J] = path[ki][kj][I][J];
                }
            }
        }
    }

    // auto debug_path = [&](int i, int j, int I, int J) {
        // ps("length is", dist[i][j][I][J]);
        // vector sol(n, string(m, '.'));
        // while (i != I || j != J) {
            // sol[i][j] = 'X'; 
            // tie(i, j) = path[I][J][i][j];
            // // ps(I, J, i, j, path[I][J][i][j]);
        // }
        // sol[I][J] = 'X';
        // for (auto s : sol) ps(s);
    // };
    // debug_path(0, 1, 2, 2);

    vector dp(p2(k), V<vi>(n, vi(m, inf)));
    for (int u = 0; u < k; u++) {
        auto [i, j] = imp_coord[u];
        dp[p2(u)][i][j] = a[i][j];
    }

    vector back(p2(k), V<V<array<int, 3>>>(n, V<array<int, 3>>(m)));
    for (int msk = 1; msk < p2(k); msk++) {
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            for (int sub = (msk-1)&msk; sub > 0; sub = (sub-1)&msk) {
                if (ckmin(dp[msk][i][j], dp[sub][i][j]+dp[msk^sub][i][j]-a[i][j])) {
                    back[msk][i][j] = {0, sub, msk^sub};
                }
            }
        }

        pqg<array<int, 3>> q;
        for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
            q.push({dp[msk][i][j], i, j});
        }
        while (q.size()) {
            auto [d, i, j] = q.top(); q.pop();
            if (d != dp[msk][i][j]) continue;
            for (int I = 0; I < n; I++) for (int J = 0; J < m; J++) if (ckmin(dp[msk][I][J], d+dist[i][j][I][J]-a[i][j])) {
                q.push({dp[msk][I][J], I, J});
                back[msk][I][J] = {1, i, j};
            }
        }
    }

    int ans_i, ans_j, ans = inf;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (ckmin(ans, dp.back()[i][j])){
        // tie(ans_i, ans_j) = {i, j}; // clang is ok with this but not gcc
        ans_i = i;
        ans_j = j;
    }

    vector sol(n, string(m, '.'));
    yy([&](auto rec, int msk, int i, int j) -> void {
        if (coord_to_imp[i][j] != -1 && msk == p2(coord_to_imp[i][j])) {
            sol[i][j] = 'X';
            return;
        }
        // ps(bitset<2>(msk), i, j, back[msk][i][j]);

        if (back[msk][i][j][0] == 0) {
            // Type 1: we joined two nonempty subsets of imp vertices
            auto [_, msk0, msk1] = back[msk][i][j];
            rec(msk0, i, j);
            rec(msk1, i, j);
        } else {
            // Type 2: we added a single non-important node
            auto [_, I, J] = back[msk][i][j];
            while (i != I || j != J) {
                sol[i][j] = 'X'; 
                auto _i = path[I][J][i][j][0];
                auto _j = path[I][J][i][j][1];
                i = _i, j = _j;
            }
            sol[I][J] = 'X';
            rec(msk, I, J);
        }
    })(p2(k)-1, ans_i, ans_j);

    cout << dp.back()[ans_i][ans_j] << '\n';
    for (auto s : sol) cout << s << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

