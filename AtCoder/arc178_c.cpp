#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

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
    int n, l; cin >> n >> l;
    vi a(n);
    for (int& i : a) cin >> i;
    int mx = *max_element(all(a));
    vi dp(mx+1, inf);
    dp[0] = 0;
    for (int i = 0; i < mx; i++) {
        for (int j = 1; j < l; j++) {
            int I = i+j*(l-j);
            if (I > mx) break;
            ckmin(dp[I], dp[i]+1);
        }
    }

    for (int i = 0; i < n; i++) {
        if (dp[a[i]] == inf) dp[a[i]] = -1;
        cout << dp[a[i]] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
