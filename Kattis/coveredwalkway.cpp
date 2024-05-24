// standard dp with cht optimization
// wa on test 3

#include <bits/stdc++.h>
using namespace std;
#define int int64_t

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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
int sq(int x) {return x*x;}
int cdiv(int a, int b) {
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return a/b;
    return -((-a+b-1)/b);
}

int n, c;
vi a;

void solve() {
    cin >> n >> c;
    a.resize(n); for (int i = 0; i < n; i++) cin >> a[i];
    vi dp(n+1);
    dp[0] = 0;
    int cur_best = 0;
    V<array<int, 2>> ch = {{0, 0}};
    for (int j, x, i = 1; i <= n; i++) {
        while (cur_best+1 < ch.size() && ch[cur_best+1][0] <= a[i-1]) {
            cur_best++;
        }

        j = ch[cur_best][1];
        dp[i] = dp[j]+sq(a[j])-2*a[j]*a[i-1] + c+sq(a[i-1]);

        if (i < n) {
            while (ch.size()) {
                x = ch.back()[0];
                j = ch.back()[1];
                if (dp[j]+sq(a[j]) - 2*a[j]*x >= dp[i]+sq(a[i]) - 2*a[i]*x) {
                    ch.pop_back();
                } else {
                    break;
                }
            }
            if (!ch.size()) {
                ch.pb({0, i});
            } else {
                int inter = cdiv(dp[i]+sq(a[i])-(dp[j]+sq(a[j])), 2*a[i] - 2*a[j]);
                ch.pb({inter, i});
            }

            if (cur_best >= ch.size()) cur_best = ch.size()-1;
        }
    }
    cout << dp[n] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

