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

void solve() {
    vi a(3); for (int i = 0; i < 3; i++) cin >> a[i];
    if ((a[0]+a[1]+a[2]) % 2) {
        cout << -1 << '\n';
        return;
    }
    sort(rall(a));
    int ans = 0;
    while (true) {
        if (!a[0] || !a[1]) break;
        ans++; a[0]--; a[1]--;
        sort(rall(a));
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
