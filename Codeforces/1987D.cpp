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

void solve() {
    int n; cin >> n;
    vi a(n), freq(n);
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; a[i]--;
        cnt += !freq[a[i]];
        freq[a[i]]++;
    }

    vi dp(n+1, -1);
    dp[0] = 0;
    for (int i = 0; i < n; i++) if (freq[i]) {
        auto DP = dp;
        fill(all(dp), -1);
        for (int buf = 0; buf <= n; buf++) if (DP[buf] != -1) {
            if (freq[i] <= buf) ckmax(dp[buf-freq[i]], DP[buf]+1);
            ckmax(dp[buf+1], DP[buf]);
        }
    }

    cout << cnt-*max_element(all(dp)) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

