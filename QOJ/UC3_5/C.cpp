#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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

const int LOG = 101;

void solve() {
    int n, m; cin >> n >> m;
    V<vi> a(n, vi(m));
    V<vi> pre(n+1, vi(m+1));
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            a[i][j] = s[j]-'0';
            pre[i+1][j+1] = pre[i+1][j]+pre[i][j+1]-pre[i][j]+a[i][j];
        }
    }
    auto is_filled = [&](int x0, int x1, int y0, int y1) {
        assert(x0<x1 && y0<y1);
        return pre[x1][y1]-pre[x0][y1]-pre[x1][y0]+pre[x0][y0] == (x1-x0)*(y1-y0);
    };


    V<vi> pc_pos_b(LOG, vi(m));
    for (int exp_b=0, cur_b=1; cur_b < 2*m; exp_b++, cur_b*=2) {
        int pos_b = 0;
        for (int j = 0; j < m; j++) {
            while (pos_b*m/cur_b < j) pos_b++;
            pc_pos_b[exp_b][j] = pos_b;
        }
    }

    int ans = inf;
    for (int exp_a=0, cur_a=1; cur_a < 2*n; exp_a++, cur_a*=2) {
        int pos_a = 0;
        for (int i = 0; i < n; i++) {
            while (pos_a*n/cur_a < i) pos_a++;
            int la = pos_a*n/cur_a;
            int ra = ((pos_a+1)*n + cur_a-1)/cur_a;

            for (int j = 0; j < m; j++) {
                for (int exp_b = 0, cur_b = 1; cur_b < 2*m; exp_b++, cur_b *= 2) {
                    int lb = pc_pos_b[exp_b][j]*m/cur_b;
                    int rb = ((pc_pos_b[exp_b][j]+1)*m + cur_b-1)/cur_b;

                    if (ra <= n && rb <= m) {
                        // ps(la, ra, )
                        if (is_filled(la, ra, lb, rb)) {
                            ps(exp_b, lb, rb);
                            ckmin(ans, exp_a+exp_b);
                        }
                    }
                }
            }
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
