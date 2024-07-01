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

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int ans = 0;

    int sum = 0;
    vi plus_inds;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] > 0) {
            sum += a[i];
            plus_inds.pb(i);
        }
        if (i == 2) {
            ckmax(ans, sum);
        }
    }

    int mx = -inf;
    for (int i = 0; i < n; i++) {
        if (plus_inds.size() && plus_inds.back() == i) {
            sum -= a[i];
            plus_inds.pop_back();
        }
        if (i % 2 == 0) {
            ckmax(ans, a[i] + sum);
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
