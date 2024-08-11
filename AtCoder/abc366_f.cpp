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

bool operator <(const array<int, 2>& x, const array<int, 2>& y) {
    auto [a1, b1] = x;
    auto [a2, b2] = y;
    return (a2-1)*b1 < (a1-1)*b2;
}
// template<class T> void bubble_sort(V<T>& a) {
    // int n = a.size();
    // for (int i = 0; i < n; i++) {
        // for (int j = 0; j < n-1-i; j++) {
            // if (a[j] > a[j+1]) {
                // swap(a[j], a[j+1]);
            // }
        // }
    // }
// }

int eval(array<int, 2> f, int x) {
    return f[0]*x+f[1];
}

void solve() {
    int n, k; cin >> n >> k;
    V<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0] >> a[i][1];
    // bubble_sort(a);
    // sort(all(a));
    sort(all(a), [&](array<int, 2> x, array<int, 2> y) {
        auto [a1, b1] = x;
        auto [a2, b2] = y;
        return b1 * (a2 - 1) > b2 * (a1 - 1); 
    });
    // reverse(all(a));

    vi dp(k+1);
    dp[0] = 1;
    for (int i = 0; i < n; i++) {
        auto DP = dp;
        for (int j = 0; j < k; j++) {
            ckmax(dp[j+1], eval(a[i], DP[j]));
        }
    }

    cout << dp[k] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
