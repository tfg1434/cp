// WA on a bunch of tcs. dunno why, come back tomorrow

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

const int N = 50;
// dp(l, r, lo, hi) = maximum non-dec subseq length on [l, r)
int dp[N][N+1][N+1][N+1];

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int& i : a) cin >> i;

    int ans = 0;
    for (int len = 1; len <= n; len++) {
        for (int l = 0; l+len <= n; l++) {
            int r = l+len;
            for (int lo = 1; lo <= n; lo++) {
                for (int hi = lo; hi <= n; hi++) {
                    if (len == 1) {
                        dp[l][r][lo][hi] = lo <= a[l] && a[l] <= hi;
                        continue;
                    }

                    int res = 0;
                    // neither border is part of the subseq
                    ckmax(res, max(dp[l+1][r][lo][hi], dp[l][r-1][lo][hi]));
                    // border IS part of the subseq
                    if (lo <= a[l] && a[l] <= hi) ckmax(res, 1+dp[l+1][r][a[l]][hi]);
                    if (lo <= a[r-1] && a[r-1] <= hi) ckmax(res, 1+dp[l][r-1][lo][a[r-1]]);

                    int x = a[r-1], y = a[l];
                    if (lo <= x && x <= y && y <= hi)
                        ckmax(res, 2+dp[l+1][r-1][x][y]);
                    if (lo <= x && x <= hi)
                        ckmax(res, 1+dp[l+1][r-1][x][hi]);
                    if (lo <= y && y <= hi)
                        ckmax(res, 1+dp[l+1][r-1][lo][y]);

                    ckmax(ans, res);
                    dp[l][r][lo][hi] = res;
                }
            }
        }
    }

    cout << ans << '\n';
}

void setIn(string s)  { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (s.size() && fopen((s+".in").c_str(), "r")) setIn(s+".in"), setOut(s+".out");
}
signed main() {
    setIO("subrev");
    solve();
    return 0;
}
