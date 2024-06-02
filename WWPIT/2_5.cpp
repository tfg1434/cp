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

int n, q;
vi a;
V<bool> ok;

void solve() {
    cin >> n >> q;
    a.resize(n);
    ok.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    while (q--) {
        int l, r, k; cin >> l >> r >> k; l--;
        for (int i = l; i < r; i++) ok[i] = true;
        int ans = 0;
        for (int b = 16; b >= 0; b--) {
            int cnt = 0;
            for (int i = l; i < r; i++) if (ok[i])
                cnt += (a[i] & (1 << b)) > 0;
            if (cnt >= k) {
                ans |= 1 << b;
                for (int i = l; i < r; i++) {
                    if (!(a[i] & (1 << b))) ok[i] = false;
                }
            }
        }
        cout << ans << '\n';
        for (int i = l; i < r; i++) ok[i] = false;
    } 
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
