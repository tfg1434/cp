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
    int n, k; cin >> n >> k;    
    string target; cin >> target;
    vi cnt(k);
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < k; j++) {
            cnt[j] += s[j]-'0';
        }
    }

    V<vi> dp(k+1, vi(n));
    V<V<array<int, 2>>> back(k+1, V<array<int, 2>>(n));
    dp[0][0] = true;
    for (int i = 0; i < k; i++) {
        for (int carry = 0; carry < n; carry++) if (dp[i][carry]) {
            bool put_1 = false;
            for (int cand_val : {carry+cnt[k-1-i], carry+n-cnt[k-1-i]}) {
                if (cand_val%2 == target[k-1-i]-'0') {
                    dp[i+1][cand_val/2] = true;
                    back[i+1][cand_val/2] = {put_1, carry};
                }
                put_1 = true;
            }
        }
    }

    if (!dp[k][0]) {
        cout << -1 << '\n';
        return;
    }
    string ans(k, '.');
    int last_carry = 0;
    for (int i = k; i >= 1; i--) {
        ans[k-i] = back[i][last_carry][0]+'0';
        last_carry = back[i][last_carry][1];
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
