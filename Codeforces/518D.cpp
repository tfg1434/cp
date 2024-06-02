#include <bits/stdc++.h>
using namespace std;
#define db long double

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

const int max_n = 2000;
db C[max_n+1][max_n+1], p, a[max_n+1];
int n, t;

void solve() {
    cin >> n >> p >> t;
    if (p == 1) {
        cout << fixed << setprecision(6) << min(n, t) << '\n';
        return;
    }

    C[0][0] = 1;
    for (int i = 1; i <= t; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i-1][j-1]+C[i-1][j];
        }
    }

    db P = pow(1-p, t);
    for (int i = 0; i <= t; i++) {
        a[min(i, n)] += P*C[t][i];
        P *= p/(1-p);
    }
    db ans = 0;
    for (int i = 0; i <= n; i++) ans += a[i]*i;
    cout << fixed << setprecision(6) << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
