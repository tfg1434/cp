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

void solve() {
    int n, m, k; cin >> n >> m >> k;
    V<vi> u(n, vi(m)), v(n, vi(m)), pre(n+1, vi(m+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> v[i][j];
        }
    }

    int A = 0, B = 0;
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) {
        char c; cin >> c;
        u[i][j] = c-'0';
        (!u[i][j] ? A : B) += v[i][j];
        pre[i+1][j+1] = pre[i+1][j] + pre[i][j+1] - pre[i][j] + u[i][j];
    }

    int gc = 0;
    int D = abs(A-B);
    for (int i = 0; i+k <= n; i++) for (int j = 0; j+k <= m; j++) {
        int sum = pre[i+k][j+k] - pre[i+k][j] - pre[i][j+k] + pre[i][j];
        gc = gcd(gc, abs(k*k-2*sum));
    }
    if ((!gc && !D) || (gc && D % gc == 0)) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
