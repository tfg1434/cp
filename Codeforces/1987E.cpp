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

const int N = 5000;
vi sons[N];
int cost, cnt[N][N], a[N], n, dist_leaf[N];

void dfs(int u) {
    bool is_leaf = true;
    int sum = 0;
    dist_leaf[u] = 0;
    for (int v : sons[u]) {
        is_leaf = false;
        dfs(v);
        if (!dist_leaf[u]) dist_leaf[u] = dist_leaf[v]+1;
        else ckmin(dist_leaf[u], dist_leaf[v]+1);
    }
    for (int v : sons[u]) {
        sum += a[v];
        for (int d = 1; d < dist_leaf[u]; d++) {
            cnt[u][d] += cnt[v][d-1];
        }
    }

    if (!is_leaf) {
        cnt[u][0] = max(0LL, sum-a[u]);

        int i = 1;
        while (a[u] > sum) {
            if (i == dist_leaf[u]) {
                cost += i*(a[u]-sum);
                sum = a[u];

            } else if (a[u]-sum <= cnt[u][i]) {
                cost += i*(a[u]-sum);
                cnt[u][i] -= a[u]-sum;
                sum = a[u];

            } else {
                cost += cnt[u][i]*i;
                sum += cnt[u][i];
                cnt[u][i] = 0;
                i++;
            }
        }
    } 
}

void solve() {
    cin >> n;
    cost = 0;
    for (int i = 0; i < n; i++) {
        sons[i].clear();
        for (int j = 0; j < n; j++) {
            cnt[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 1; i < n; i++)  {
        int p; cin >> p; p--;
        sons[p].pb(i);
    }
    dfs(0);

    cout << cost << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

