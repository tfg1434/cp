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
    int n, m, k; cin >> n >> m >> k;
    V<string> a(n);
    for (string& i : a) cin >> i;
    V<string> ans(n, string(m, '.'));
    for (int i = 0; i < n; i++) {
        int last_a = -1;
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 'A') {
                last_a = j;
            } else if (a[i][j] == 'B') {
                ans[i][j] = last_a != -1 && j-last_a <= k ? 'N' : 'Y';
            }
        }

        int last_b = m;
        for (int j = m-1; j >= 0; j--) {
            if (a[i][j] == 'B') {
                last_b = j;
            } else if (a[i][j] == 'A') {
                ans[i][j] = last_b != m && last_b-j <= k ? 'N' : 'Y';
            }
        }
    }

    for (string s : ans) cout << s << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
