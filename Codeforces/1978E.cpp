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
    int n; cin >> n;
    string a, b; cin >> a >> b;
    auto A = a; auto B = b;
    for (int i = 1; i+1 < n; i++) if (a[i-1] == '0' && a[i+1] == '0') b[i] = '1';
    for (int i = 1; i+1 < n; i++) if (b[i-1] == '1' && b[i+1] == '1') a[i] = '1';
    auto aa = a, bb = b;
    vi pre(n+1);
    for (int i = 0; i < n; i++) pre[i+1] = pre[i]+a[i]-'0';
    
    int q; cin >> q;
    while (q--) {
        int l, r; cin >> l >> r; l--;
        if (l == r-1) {
            cout << A[l]-'0' << '\n';
            continue;
        }
        b[l] = B[l]; b[r-1] = B[r-1];
        a[l] = A[l]; a[r-1] = A[r-1];
        a[l+1] = b[l] == '1' && (l+2 < r && b[l+2] == '1') ? '1' : A[l+1];
        a[r-2] = b[r-1] == '1' && (r-3 >= l && b[r-3] == '1') ? '1' : A[r-2];

        int ans = a[l]-'0' + a[r-1]-'0';
        if (l+1 < r-1) ans += a[l+1]-'0';
        if (r-2 > l+1) ans += a[r-2]-'0';
        if (l+2 < r-2) ans += pre[r-2] - pre[l+2];
        cout << ans << '\n';

        b[l] = bb[l]; b[r-1] = bb[r-1];
        a[l] = aa[l]; a[l+1] = aa[l+1];
        a[r-1] = aa[r-1]; a[r-2] = aa[r-2];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
