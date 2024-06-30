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

// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define pct __builtin_popcount
constexpr int p2(int x) { return (int)1 << x; }
constexpr int msk2(int x) { return p2(x)-1; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 

void solve(int n, const vi& p) {
    // int n; cin >> n;
    // vi p(n);
    // for (int i = 0; i < n; i++) cin >> p[i], p[i]--;

    int ans = 0;
    for (int i = 1; i < p2(n)-1; i++) {
        vi a[2], A[2];
        for (int j = 0; j < n; j++) {
            bool c = i & p2(j);
            a[c].pb(p[j]);
            A[c].pb(j);
        }
        int fps = 0;
        for (int c = 0; c < 2; c++) {
            sort(all(a[c]));
            for (int j = 0; j < a[c].size(); j++) fps += a[c][j] == A[c][j];
        }
        ckmax(ans, fps);
    }

    assert(ans == n || ans == n-2);
    // cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int n = 8;
    vi p(n); iota(all(p), 0);
    do {
        solve(n, p);
    } while (next_permutation(all(p)));
    // int tc; cin >> tc; while (tc--) solve();
    return 0;
}
