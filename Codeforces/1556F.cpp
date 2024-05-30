// dunno why it fails second sample

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int P = 1e9+7;

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
        if (b%2) res = res*a%P;
        b /= 2;
        a = a*a%P;
    }
    return res;
}
int inv(int a) {
    return pw(a, P-2);
}

const int max_n = 14;
int n, a[max_n], to[max_n][1 << max_n], g[max_n][max_n], dp[1 << max_n];

void solve() {
    cin >> n; 
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j) {
        g[i][j] = a[i] * inv(a[i]+a[j]) % P;
    }
    for (int i = 0; i < n; i++) {
        for (int m = 1; m < (1 << n); m++) if (!(m & (1 << i))){
            int p = 1;
            for (int j = 0; j < n; j++) if (m & (1 << j)) {
                p = p*g[i][j]%P;
            }
            to[i][m] = p;
        }
    }

    for (int m = 1; m < (1 << n); m++) {
        int tot = 0;
        int s = m & (m-1);
        while (s > 0) {
            int S = m - s;

            int p = 1;
            for (int i = 0; i < n; i++) if (s & (1 << i)) {
                p = p * to[i][S] % P;
            }
            tot += dp[s] * p % P;
            tot %= P;

            s = m & (s-1);
        }

        dp[m] = (1-tot+P)%P;
    }

    int ans = 0;
    for (int m = 1; m < (1 << n); m++) {
        int M = (1 << n)-1 - m;

        int p_out = 1;
        for (int i = 0; i < n; i++) if (m & (1 << i)) {
            p_out *= to[i][M];
            p_out %= P;
        }
        ans += dp[m] * __builtin_popcount(m) % P * p_out;
        ans %= P;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
