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

const int max_n = 40, max_k = 2500, max_pairs = 400;
int n, k;
bitset<max_k+1> dp[max_n+1][max_n+1][max_pairs+1];

void solve() {
    cin >> n >> k;
    string s; cin >> s;
    dp[0][0][0].set(0);
    for (int i = 0; i < n; i++) {
        for (int zeros = 0; zeros <= n; zeros++) {
            for (int pairs = 0; pairs <= max_pairs; pairs++) {
                if (!dp[i][zeros][pairs].count()) continue;
                if (s[i] == 'N' || s[i] == '?') {
                    dp[i+1][zeros+1][pairs] |= dp[i][zeros][pairs];
                } 
                if (s[i] == 'A' || s[i] == '?') {
                    dp[i+1][zeros][pairs+zeros] |= dp[i][zeros][pairs];
                } 
                if (s[i] == 'C' || s[i] == '?') {
                    dp[i+1][zeros][pairs] |= dp[i][zeros][pairs] << pairs;
                } 
                if (s[i] != 'N' && s[i] != 'A' && s[i] != 'C') {
                    dp[i+1][zeros][pairs] |= dp[i][zeros][pairs];
                }
            }
        }
    }

    bool possible = false;
    int s_zeros, s_pairs;
    for (int zeros = 0; zeros <= n; zeros++) {
        for (int pairs = 0; pairs <= max_pairs; pairs++) {
            if (dp[n][zeros][pairs].test(k)) {
                possible = true;
                s_zeros = zeros;
                s_pairs = pairs;
            }
        }
    }
    if (!possible) return (void) (cout << "-1\n");

    string ans(n, '*');
    int cur = k;
    for (int i = n-1; i >= 0; i--) {
        if ((s[i] == 'N' || s[i] == '?') && s_zeros > 0 && dp[i][s_zeros-1][s_pairs].test(k)) {
            ans[i] = 'N';
            s_zeros--;
            continue;
        }
        if ((s[i] == 'A' || s[i] == '?') && s_pairs >= s_zeros && dp[i][s_zeros][s_pairs-s_zeros].test(k)) {
            ans[i] = 'A';
            s_pairs -= s_zeros;
            continue;
        }
        if ((s[i] == 'C' || s[i] == '?') && k >= s_pairs && dp[i][s_zeros][s_pairs].test(k-s_pairs)) {
            ans[i] = 'C';
            k -= s_pairs;
            continue;
        }
        if ((s[i] != 'N' && s[i] != 'A' && s[i] != 'C') && dp[i][s_zeros][s_pairs].test(k)) {
            ans[i] = s[i] == '?' ? 'Z' : s[i];
            continue;
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
