#include <bits/stdc++.h>
using namespace std;

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

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

void solve() {
    int n, m; cin >> n >> m;
    if (m == 1 && n == 1) {
        cout << "Yes" << '\n';
        cout << 1 << '\n';
        return;
    }
    if (m == 1 || m % 2 && n % 2 == 0) {
        cout << "No" << '\n';
        return;
    }

    V<vi> ans(n, vi(m));
    if (m % 2) {
        for (int i = 0; i < n; i++) {
            ans[i][m-1] = i+1;
            ans[i][m-2] = i+1+n/2;
            if (ans[i][m-2] > n) ans[i][m-2] -= n;
            ans[i][m-3] = (n+1)/2*3 - ans[i][m-1] - ans[i][m-2];
        }
    }
    for (int j = 0; j < m - (m%2)*3; j++) {
        for (int i = 0; i < n; i++) {
            ans[i][j] = j%2 ? i+1 : n-i;
        }
    }

    cout << "Yes" << '\n';
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << ans[i][j]+j*n << " \n"[j==m-1];
        }
    }


    // vi a(7); iota(all(a), 1);
    // vi b(7); iota(all(b), 1);
    // do {
    // do {
        // bool ok = true;
        // for (int i = 0; i < 7; i++) {
            // ok &= i+1 + a[i] + b[i] == 12;
        // }
        // if (ok) {
            // for (int i = 0; i < 7; i++) {
                // cout << i+1 << ' ' << a[i] << ' ' << b[i] << '\n';
            // }
            // cout << '\n';
        // }
    // } while (next_permutation(all(b)));
    // } while (next_permutation(all(a)));


    // int n = 3, m = 3;
    // vi a(n*m);
    // iota(all(a), 1);

    // do {
        // int expected = m*(n*m+1)/2;
        // bool ok = true;
        // for (int i = 0; i < n*m; i += m) ok &= a[i]+a[i+1]+a[i+2] == expected && is_sorted(a.begin()+i, a.begin()+i+3);
        // if (ok) {
            // for (int i = 0; i < n*m; i += m) {
                // cout << a[i]<<a[i+1]<<a[i+2] << '\n';
            // }
            // cout << '\n';
        // }
    // } while (next_permutation(all(a)));
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
