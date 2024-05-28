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

const int P = 1e9+7, TWO = 5e4+4;
int n, a, b;
V<vi> g;
vi sub, path;

void add(int& x, const int y) {
    x += y;
    if (x >= P) x -= P;
}

int pw(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b%2) res = res*a%P;
        b /= 2;
        a = a*a%P;
    }
    return res;
}
int inv(int a) {
    return pw(a, P-2);
}

bool dfs(int u, int p) {
    bool on_path = u == b;
    sub[u] = 1;
    for (int v : g[u]) if (v != p) {
        if (dfs(v, u)) {
            path.pb(v);
            on_path = true;
        }
        sub[u] += sub[v];
    }
    return on_path;
}

void solve() {
    cin >> n;
    g.resize(n);
    sub.resize(n);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }

    V<V<vi>> dp(n);
    for (int dist = 1; dist < n; dist++) {
        dp[dist].assign(dist, vi(dist));
        auto& f = dp[dist];

        for (int i = 1; i < dist; i++) {
            f[i][0] = 1;
            for (int j = 1; j < dist; j++) {
                f[i][j] = (f[i-1][j]+f[i][j-1])*inv(2)%P;
            }
        }
    }

    int ans = 0;
    for (a = 0; a < n-1; a++) {
        for (b = a+1; b < n; b++) {
            path.clear();
            dfs(a, -1);
            reverse(all(path));

            int dist = path.size();
            vi hang(path.size()-1);
            for (int i = 0; i < path.size()-1; i++) {
                hang[i] = sub[path[i]] - sub[path[i+1]];
            }

            add(ans, sub[b]*inv(n)%P);
            for (int i = 0; i < path.size()-1; i++) {
                add(ans, hang[i]*inv(n)%P*dp[dist][i+1][path.size()-1-i]%P);
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
