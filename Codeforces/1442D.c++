// today on the discovery channel:
// can we do it w/o D&C, just an extra flag in the DP?
//
// It doesn't work, because with this approach you have to add every broken prefix into the dp
// The D&C works because by calculating the entire DP w/o a single item, now you can 
// consider the contribution of this item in O(inp[i].size()) instead of O(MAX)
// (because you have the extra info that this is the last added elem)

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
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmax(T& a, T b) {return a<b ? a=b, 1 : 0;}

const int max_n = 3000;
int n, k, sum[max_n];
vi inp[max_n];
V<vi> dp;

void calc_dp() {
    for (int i = 0; i < n; i++) {
        auto DP = dp;

        for (int flag = 0; flag < 2; flag++) {
            for (int j = max_n-inp[i].size(); j >= 0; j--) {
                if (DP[flag][j] != -1)
                    ckmax(dp[flag][j+inp[i].size()], DP[flag][j]+sum[i]);
            }
        }
        for (int cur = 0, cnt = 1; cnt <= inp[i].size(); cnt++) {
            cur += inp[i][cnt-1];
            for (int j = max_n-cnt; j >= 0; j--) {
                if (DP[false][j] != -1) 
                    ckmax(dp[true][j+cnt], DP[false][j]+cur);
            }
        }

        // for (int j = 0; j <= k; j++) ps(j, dp[0][j], dp[1][j]);
    }
}

void solve() {
    dp.assign(2, vi(max_n+1, -1));
    dp[0][0] = 0;

    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        int sz; cin >> sz; inp[i].resize(sz);
        for (auto& x : inp[i]) cin >> x, sum[i] += x;
    }
    calc_dp();

    int ans = max(dp[false][k], dp[true][k]);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
