#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

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

int n, m;
const int max_n = 1e4;
int w[max_n], f[max_n];
const int max_m = 1e5;
int a[max_m+1], step[max_m+1];
bool dp[max_m+1];

void solve() {
    cin >> n >> m;    
    for (int i = 0; i < n; i++) cin >> w[i];
    for (int i = 0; i < n; i++) cin >> f[i];

    dp[0] = true;
    for (int i = 0; i < n; i++) {
        memset(a, -1, sizeof a);
        for (int sum = 0; sum <= m; sum++) {
            if (dp[sum]) {
                a[sum] = 0;
            } else {
                if (sum >= w[i] && a[sum-w[i]] != -1) {
                    a[sum] = a[sum-w[i]]+1;
                    if (a[sum] <= f[i]) {
                        dp[sum] = true;
                        step[sum] = i; 
                    }
                }
            }
        }
    }

    for (int i = m; i >= 0; i--) if (dp[i]) {
        vi ans(n);
        while (i > 0) {
            ans[step[i]]++;
            i -= w[step[i]];
        }
        for (int j = 0; j < n; j++) cout << ans[j] << " \n"[j==n-1];
        break;
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
