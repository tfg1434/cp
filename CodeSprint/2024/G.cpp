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
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }

const int max_n = 1e5, max_k = 20, thres = 25; // k+lgk
const int max_bit = 1e6*thres;
int n, a[max_n];
bitset<2*max_bit+1> dp;

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    if (n >= thres) {
        cout << "0\n";
        return;
    }
    for (int i = 0; i < min(n, thres); i++) {
        dp |= dp << a[i];
        dp |= dp >> a[i];
        dp.set(a[i] + max_bit);
        dp.set(-a[i] + max_bit);
    }
    int ans = inf;
    for (int i = max_bit; i <= 2*max_bit; i++) if (dp.test(i))
        ans = min(ans, __builtin_popcount(i-max_bit));
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
