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

int between(int l, int r, bool exclusive) {
    if (exclusive) {
        l++;
        r--;
    }
    if (l%2) l++;
    if (r%2) r--;
    return max(0LL, (r-l)/2+1);
}

void solve() {
    int n, lq, rq; cin >> n >> lq >> rq;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(all(a));
    auto mixed_positional = [&](int x) {
        vi d(n);
        for (int i = 0; i < n; i++) {
            d[i] = x/a[i];
            x -= d[i]*a[i];
        }
        return d;
    };
    auto lp = mixed_positional(lq), rp = mixed_positional(rq);
    if (lq == rq) {
        bool all_even = true;
        for (int i = 0; i < n; i++) all_even &= a[i]%2 == 0;
        cout << (all_even ? 0 : 1) << '\n';
    }
    // ps(lp);
    // ps(rp);

    vi tot_choices(n), even_choices(n); 
    for (int i = 1; i < n; i++) {
        tot_choices[i] = a[i-1]/a[i];
        even_choices[i] = (tot_choices[i]-1) / 2 + 1;
    }

    V<vi> dp(n+1, vi(3));
    dp[1][0] = lp[0]%2 == 0;
    dp[1][2] = rp[0]%2 == 0;
    dp[1][1] = between(lp[0], rp[0], true);
    bool all_same = lp[0] == rp[0];
    for (int i = 1; i < n; i++) {
        if (lp[i]%2 == 0) dp[i+1][0] = dp[i][0];
        if (rp[i]%2 == 0) dp[i+1][2] = dp[i][2];

        if (all_same) {
            dp[i+1][1] = dp[i][1]*even_choices[i] + ((dp[i][0]+dp[i][2])*between(lp[i], rp[i], true));
        } else {
            dp[i+1][1] = dp[i][1]*even_choices[i] + dp[i][0]*between(lp[i], tot_choices[i], true) + dp[i][2]*between(-1, rp[i], true);
        }
        all_same &= lp[i] == rp[i];
    }

    int ans = rq-lq+1;
    ans -= dp[n][0]+dp[n][1]+dp[n][2];
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
