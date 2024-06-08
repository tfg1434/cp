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
    int p, n, c; cin >> p >> n >> c;    
    if (n*c < p) {
        cout << "-1\n";
        return;
    }
    V<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0];
    for (int i = 0; i < n; i++) cin >> a[i][1];
    sort(all(a), [&](const array<int, 2>& x, const array<int, 2>& y) {
        return x[0]+x[1]*c < y[0]+y[1]*c;
    });
    int cost = 0;
    int full = p/c, rem = p-full*c;
    for (int i = 0; i < full; i++) {
        cost += a[i][0] + a[i][1]*c;
    }
    if (rem) {
        int mn = -1;
        for (int i = full; i < n; i++) {
            int x = a[i][0] + a[i][1]*rem;
            if (mn == -1 || mn > x) mn = x;
        }
        cost += mn;
    }

    cout << cost << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
