// it took me so long, but it brought me so much joy :))))

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
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

const int max_n = 2e5, max_bit = 18;
int n, q, a[max_n];
int dat[max_bit][max_n+1], mask[max_n];

void precalc(int l, int r, int lvl) {
    if (l == r-1) return;
    int m = (l+r)/2;
    dat[lvl][m] = inf;
    for (int i = m-1; i >= l; i--) dat[lvl][i] = min(dat[lvl][i+1], a[i]);
    for (int i = m+1; i <= r; i++) dat[lvl][i] = min(dat[lvl][i-1], a[i-1]);
    for (int i = m; i < r; i++) mask[i] |= 1<<lvl;
    precalc(l, m, lvl+1);
    precalc(m, r, lvl+1);
}

void solve() {
    cin >> n >> q; 
    for (int i = 0; i < n; i++) cin >> a[i];
    precalc(0, n, 0);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--;
        if (l == r-1) {
            cout << a[l] << '\n';
            continue;
        }
        if (r == n) {
            int lvl = __builtin_ctz(~mask[l]);
            cout << min(dat[lvl][l], dat[lvl][n]) << '\n';
            continue;
        }
        int lvl = __builtin_ctz(mask[l]^mask[r]);
        cout << min(dat[lvl][l], dat[lvl][r]) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
