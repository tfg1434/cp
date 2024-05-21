#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 2e18;

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

int fdiv(int a, int b) {
    if (b < 0) {
        a = -a;
        b = -b;
    }
    if (a >= 0) return a/b;
    return -((-a + b - 1) / b);
}

const int max_coord = 1e9+1;
int n;
vi a, p, q;

void solve() {
    cin >> n;
    p.resize(n+1); q.resize(n+1); a.resize(n+1);
    {
        V<array<int, 3>> pts(n+1);
        for (int i = 0; i < n; i++) cin >> pts[i][0] >> pts[i][1] >> pts[i][2];
        n++; pts.back() = {0, max_coord, 0};
        sort(all(pts));
        for (int i = 0; i < n; i++) p[i] = pts[i][0], q[i] = pts[i][1], a[i] = pts[i][2];
    }

    vi dp(n, -inf); dp[0] = 0;
    V<array<int, 2>> ch = {{max_coord, 0}};
    int cur_best = 0;
    for (int j, coord, i = 1; i < n; i++) {
        while (cur_best+1 < ch.size() && ch[cur_best+1][0] >= q[i]) cur_best++;
        j = ch[cur_best][1];
        dp[i] = dp[j] + (p[i]-p[j])*q[i] - a[i];

        while (true) {
            j = ch.back()[1];
            coord = ch.back()[0];
            if (dp[j]-coord*p[j] <= dp[i]-coord*p[i]) {
                ch.pop_back();
            } else {
                break;
            }
        }
        j = ch.back()[1];
        coord = min(fdiv(dp[i]-dp[j], p[i]-p[j]), max_coord);
        if (coord >= 0) ch.pb({coord, i});
        ckmin(cur_best, (int)ch.size()-1);
    }

    int ans = *max_element(all(dp));
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
