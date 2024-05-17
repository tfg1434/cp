#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

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

template<class T> bool ckmin(T& a, const T& b) {
    return a>b ? a=b, 1 : 0;
}

int n, m;
string a, b;
const int max_n = 1000;
int dp[max_n+1][max_n+1];

void solve() {
    cin >> a >> b;
    n = a.size();
    m = b.size();
    for (int i = 0; i <= n; i++) fill(all(dp[i]), inf);
    dp[0][0] = 0;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            if (i > 0 && j > 0) {
                if (a[i-1] == '?' || b[j-1] == '?' || a[i-1] == b[j-1]) 
                    ckmin(dp[i][j], dp[i-1][j-1]+1);
                if (a[i-1] == '*') ckmin(dp[i][j], dp[i][j-1]+1);
                if (b[j-1] == '*') ckmin(dp[i][j], dp[i-1][j]+1);
            }
            if (i > 0) {
                if (a[i-1] == '*') ckmin(dp[i][j], dp[i-1][j]);
            }
            if (j > 0) {
                if (b[j-1] == '*') ckmin(dp[i][j], dp[i][j-1]);
            }
        }
    }

    if (dp[n][m] == inf) {
        cout << "No solution!";
        return;
    } 
    cout << dp[n][m] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
