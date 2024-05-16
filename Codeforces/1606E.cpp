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

const int mod = 998244353;
const int max_n = 500;
int f[max_n+1][max_n+1];
int n, x;
int pw[max_n+1][max_n+1];
int C[max_n+1][max_n+1];
void precalc() {
    for (int i = 0; i <= max_n; i++) for (int j = 0; j <= max_n; j++) {
        pw[i][j] = (j == 0) ? 1 : 1LL*pw[i][j-1]*i % mod;
    }
    C[0][0] = 1;
    for (int i = 1; i <= max_n; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i-1][j-1]+C[i-1][j];
            if (C[i][j] >= mod) C[i][j] -= mod;
        }
    }
}

void solve() {
    cin >> n >> x;
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i-1; j++) {
            f[i][j] = pw[j][i] - pw[j-1][i];
            if (f[i][j] < 0) f[i][j] += mod;
        }
        for (int j = i; j <= x; j++) {
            for (int k = 2; k <= i; k++) {
                f[i][j] += 1ll*C[i][k]*f[k][j-(i-1)]%mod*pw[i-1][i-k]%mod;
                if (f[i][j] >= mod) f[i][j] -= mod;
            }
        }
    }

    int ans = 0;
    for (int j = 1; j <= x; j++) {
        ans += f[n][j];
        if (ans >= mod) ans -= mod;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    precalc();
    solve();
    return 0;
}
