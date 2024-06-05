#include <bits/stdc++.h>
using namespace std;
using db = long double;

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

#define pct __builtin_popcount
constexpr int p2(int x) { return (int)1 << x; }
constexpr int msk2(int x) { return p2(x)-1; }

const int max_n = 18;
int n;
db a[max_n][max_n], dp[p2(max_n)];

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

    dp[msk2(n)] = 1;
    for (int i = msk2(n); i > 0; i--) {
        int pc = pct(i);
        for (int k = 0; k < n; k++) if (i & p2(k)) {
            for (int j = 0; j < n; j++) if (!(i & p2(j))) {
                dp[i] += dp[i ^ p2(j)] * 2/(1.L*pc*(pc+1)) * a[k][j];
            }
        }
    }

    for (int i = 0; i < n; i++) cout << dp[p2(i)] << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cout << fixed << setprecision(6) << '\n';
    solve();
    return 0;
}
