#include <bits/stdc++.h>
using namespace std;
using db = long double;
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
    int k, q; cin >> k >> q;
    vi ans(q);
    V<array<int, 2>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0];
        queries[i][1] = i;
    }
    sort(all(queries));

    // Process dp
    // dp[d][k] = probability of getting k orbs after d days
    int pos = 0;
    V<db> dp(k+1); 
    dp[0] = 1;
    for (int i = 1; i < 7500; i++) {
        for (int j = k-1; j >= 0; j--) {
            dp[j+1] = 1.L*(k-j)/k*dp[j] + 1.L*(j+1)/k*dp[j+1];
        }
        dp[0] = 0;

        while (pos < queries.size() && dp[k]*2000 >= queries[pos][0]) {
            ans[queries[pos++][1]] = i;
        }
    }

    for (int i = 0; i < q; i++) cout << ans[i] << " \n"[i==q-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
