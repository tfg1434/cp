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

#define pct __builtin_popcountll
constexpr int p2(int x) { return (int)1 << x; }
const int LOG = 60;

void solve() {
    int n; cin >> n;
    int m = pct(n);
    if (m == 1) {
        cout << 1 << '\n';
        cout << n << '\n';
        return;
    }
    vi ans(m);
    vi bits;
    for (int b = LOG-1; b >= 0; b--) if (n & p2(b)) bits.pb(b);
    for (int i = 0; i < m; i++) {
        int b = bits[i];
        for (int j = 0; j < m; j++) {
            ans[j] |= p2(b);
        }
        for (int j = 0; j <= i; j++) if (j%2 == i%2) {
            ans[j] ^= p2(b);
        }
    }
    m++;
    ans.pb(n);

    cout << m << '\n';
    for (int i = 0; i < m; i++) cout << ans[i] << " \n"[i==m-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}


