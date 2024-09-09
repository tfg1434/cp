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

const int N = 100;
int dpl[N][N][N*N/4], dpr[N][N][N*N/4];

void solve() {
    int n, l, r, k;
    cin >> n >> l >> r >> k; l--;
    ckmin(k, N*N/4-1);
    vi a(n);
    for (int& i : a) cin >> i;

    for (int pos_in = l; pos_in < r; pos_in++) {
        for (int pos_out = 0; pos_out < l; pos_out++) {
            for (int money = 0; money <= k; money++) {
                int& x = dpl[pos_in][pos_out][money];
                if (pos_in > l) {
                    ckmax(x, dpl[pos_in-1][pos_out][money]);
                }
                if (pos_out > 0) {
                    ckmax(x, dpl[pos_in][pos_out-1][money]);
                }
                if (money >= pos_in-pos_out) {
                    int prv_state = 0;
                    if (pos_in > l && pos_out > 0) {
                        prv_state = dpl[pos_in-1][pos_out-1][money-(pos_in-pos_out)];
                    }
                    ckmax(x, prv_state+a[pos_in]-a[pos_out]);
                }
                // ps(pos_in, pos_out, money, x);
            }
        }
    }
    
    for (int pos_in = r-1; pos_in >= l; pos_in--) {
        for (int pos_out = r; pos_out < n; pos_out++) {
            for (int money = 0; money <= k; money++) {
                int& x = dpr[pos_in][pos_out][money];
                if (pos_in < r) {
                    ckmax(x, dpr[pos_in+1][pos_out][money]);
                }
                if (pos_out > r) {
                    ckmax(x, dpr[pos_in][pos_out-1][money]);
                }
                if (pos_out-pos_in <= money) {
                    int prv_state = 0;
                    if (pos_in < r && pos_out > r) {
                        prv_state = dpr[pos_in+1][pos_out-1][money-(pos_out-pos_in)];
                    }
                    ckmax(x, prv_state+a[pos_in]-a[pos_out]);
                }
                // ps(pos_in, pos_out, money, x);
            }
        }
    }

    int ans = 0;
    for (int i = l-1; i < r; i++) {
        for (int money = 0; money <= k; money++)  {
            int res = 0;
            if (i >= l) {
                res += dpl[i][l-1][money];
            }
            if (i+1 < r) {
                res += dpr[i+1][n-1][k-money];
            }
            ckmax(ans, res);
        }
    }

    int interval_sum = 0;
    for (int i = l; i < r; i++) interval_sum += a[i];
    cout << interval_sum-ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
