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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

const int max_n = 2e5;
int a, b, n, q;
int L[max_n+1], R[max_n+1], U[max_n+1], D[max_n+1];

void solve() {
    vi xs, ys;
    cin >> a >> b >> n >> q;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y; x--; y--;
        xs.pb(x); ys.pb(y);
    }

    int l = 0, r = b, u = 0, d = a;
    L[0] = l, R[0] = r, U[0] = u, D[0] = d;
    for (int i = 0; i < q; i++) {
        char c; cin >> c; 
        int x; cin >> x;
        if (c == 'U') u += x;
        if (c == 'D') d -= x;
        if (c == 'L') l += x;
        if (c == 'R') r -= x;
        L[i+1] = l, R[i+1] = r, U[i+1] = u, D[i+1] = d;
    }

    vi ans(2);
    for (int i = 0; i < n; i++) {
        int x = xs[i], y = ys[i];
        int lo = 1, hi = q+1;
        while (lo < hi) {
            int mid = (lo+hi)/2;
            bool in = U[mid] <= x && x < D[mid] && L[mid] <= y && y < R[mid];
            in ? lo = mid+1 : hi = mid;
        }
        if (hi <= q) ans[(hi-1)%2]++;
    }
    cout << ans[0] << ' ' << ans[1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
