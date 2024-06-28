#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int mod = 1e9+7;

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

int pw(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b%2) res = res*a%mod;
        b /= 2;
        a = a*a%mod;
    }
    return res;
}
int inv(int a) { return pw(a, mod-2); }

int half = inv(2);
const int max_n = 500;
int dp[max_n+1][max_n+1], a[max_n], n, m, ans;

void solve() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int y = 0; y <= m; y++) dp[0][y] = 1;
    for (int x = 1; x <= m; x++) for (int y = 1; y <= m; y++) {
        dp[x][y] = half*(dp[x-1][y] + dp[x][y-1])%mod;
    }

    ans = m+1-a[0];
    for (int i = 0; i+1 < n; i++) {
        int x = a[i+1]-a[i];
        for (int bar = a[i+1]+1; bar <= m+1; bar++) {
            int y = bar-a[i+1];
            (ans += 1+mod-dp[x][y]) %= mod;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
