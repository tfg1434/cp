#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;

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

vi find_divs(int n) {
    vi res, tmp;
    for (int i = 1; i*i <= n; i++) if (n%i==0) {
        res.pb(i);
        if (i*i != n) tmp.pb(n/i);
    }
    for (int i = tmp.size()-1; i >= 0; i--) res.pb(tmp[i]);
    return res;
}

int n, m, gc;
V<vi> a;
const int max_n = 100;
bool vis[max_n][max_n];

void solve() {
    cin >> n >> m;
    a = V<vi>(n, vi(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> a[i][j];


    int ans = 0;
    int gc = gcd(a[0][0], a[n-1][m-1]);
    for (int d = 1; d*d <= gc; d++) if (gc%d==0) {
        for (int cand : {d, gc/d}) {
            // memset(vis, 0, sizeof vis);
            for (int i = 0; i < n; i++) fill(all(vis[i]), false);
            vis[0][0] = true;
            for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) if (a[i][j] % cand == 0){
                if (i > 0 && vis[i-1][j]) vis[i][j] = true;
                if (j > 0 && vis[i][j-1]) vis[i][j] = true;
            }
            if (vis[n-1][m-1]) {
                ans = max(ans, cand);
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
