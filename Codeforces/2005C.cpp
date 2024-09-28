#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

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

int narek(char c) {
    if (c == 'n') return 0;
    if (c == 'a') return 1;
    if (c == 'r') return 2;
    if (c == 'e') return 3;
    if (c == 'k') return 4;
    return -1;
}

void solve() {
    int n, m; cin >> n >> m;    

    vector delta(n, V<array<int, 2>>(5));
    for (int i = 0; i < n; i++) {
        for (int c = 0; c < 5; c++) {
            delta[i][c] = {c, 0};
        }
    }
    for (int i = 0; i < n; i++) {
        vi a;
        for (int j = 0; j < m; j++) {
            char c; cin >> c;
            int ind = narek(c);
            if (ind != -1) a.pb(ind);
        }

        for (int c : a) {
            for (int x = 0; x < 5; x++) {
                if (delta[i][x][0] == c) {
                    delta[i][x][0] = (delta[i][x][0]+1)%5;
                    if (!delta[i][x][0]) delta[i][x][1] += 5;
                } else {
                    delta[i][x][1]--;
                }
            }
        }
    }

    vector dp(n+1, vi(5, -inf));
    dp[0][0] = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            ckmax(dp[i+1][delta[i][j][0]], dp[i][j]+delta[i][j][1]);
            ckmax(dp[i+1][j], dp[i][j]);
        }
    }
    int ans = 0;
    for (int c = 0; c < 5; c++) {
        ckmax(ans, dp[n][c]-c);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
