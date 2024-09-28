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
#define len(x) (int)((x).size())
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

void solve() {
    int n; cin >> n;    
    array<vi, 2> a;
    for (int side = 0; side < 2; side++) {
        a[side].resize(n);
        for (int& i : a[side]) cin >> i;
    }

    array<vi, 2> pre, suf;
    for (int side = 0; side < 2; side++) {
        pre[side].resize(n+1);
        suf[side].resize(n);
        for (int i = 0; i < n; i++) {
            pre[side][i+1] = gcd(pre[side][i], a[side][i]);
        }
        for (int i = n-1; i >= 0; i--) {
            if (i < n-1) suf[side][i] = suf[side][i+1];
            suf[side][i] = gcd(suf[side][i], a[side][i]);
        }
    }

    if (n <= 20) {
        int ans = 0, ways = 0;
        for (int i = 0; i < n; i++) {
            array<int, 2> cur_g{};
            for (int j = i+1; j <= n; j++) {
                int G = 0;
                for (int side = 0; side < 2; side++) {
                    cur_g[side] = gcd(cur_g[side], a[1-side][j-1]);
                    int g = gcd(pre[side][i], gcd(cur_g[side], j < n ? suf[side][j] : 0));
                    G += g;
                }
                if (ckmax(ans, G)) ways = 0;
                if (G >= ans) ways++;
            }
        }

        cout << ans << ' ' << ways << '\n';
        // return;
    }

    int ans = pre[0][n]+pre[1][n];
    for (int i = 0; i < n; i++) if (pre[0][i] != pre[0][i+1] || pre[1][i] != pre[1][i+1]){
        array<int, 2> cur_g{};
        for (int j = i+1; j <= n; j++) {
            int G = 0;
            for (int side = 0; side < 2; side++) {
                cur_g[side] = gcd(cur_g[side], a[1-side][j-1]);
                int g = gcd(pre[side][i], gcd(cur_g[side], j < n ? suf[side][j] : 0));
                G += g;
            }
            ckmax(ans, G);
        }
    }

    auto count_fixed(array<int, 2> g) {
        if (g[0] <= 0 || g[1] <= 0) return 0;
        if (a[1][g]%g[1]) return 0;
        vector dp(n+1, vi(3));
        dp[0][0] = 1;
        for (int i = 0; i < n; i++) if (pre[]){
        }
    };

    int ways = 0;
    for (int d = 1; d*d <= a[0]; d++) if (a[0]%d==0){
        ways += count_fixed({ d, ans-d });
        if (d*d < a[0])
            ways += count_fixed({ a[0]/d, ans-a[0]/d });
    }

    // cout << ans << ' ' << ways << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}


