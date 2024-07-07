#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

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

// n=1?
void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vi pre_max(n+1, -inf), suf_max(n), pre_sum(n+1), suf_sum(n), pre_min(n+1, inf), suf_min(n);
    for (int i = 0; i < n; i++) {
        pre_max[i+1] = max(pre_max[i], a[i]);
        pre_min[i+1] = min(pre_min[i], a[i]);
        pre_sum[i+1] = pre_sum[i]+a[i];
    }
    suf_max[n-1] = suf_min[n-1] = suf_sum[n-1] = a[n-1];
    for (int i = n-2; i >= 0; i--) {
        suf_max[i] = max(suf_max[i+1], a[i]);
        suf_min[i] = min(suf_min[i+1], a[i]);
        suf_sum[i] = suf_sum[i+1]+a[i];
    }

    int ans = 0;
    for (int i = 1; i < n; i++) {
        int min_l = pre_sum[i]-pre_max[i];
        int max_l = pre_sum[i]-pre_min[i];
        int min_r = suf_sum[i]-suf_max[i];
        int max_r = suf_sum[i]-suf_min[i];
        ckmax(ans, abs(min_l - max_r));
        ckmax(ans, abs(max_l - min_r));
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
