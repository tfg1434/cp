// 0-indexed queries
// yes, you do use the swapped versions of L[i-1] and R[i-1]

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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

const int max_n = 1e6, max_bit = 20;
int n, p, q;
vi a, b;

int mask[max_n], dat[max_bit][max_n+1];
void precalc(int l, int r, int lvl) {
    if (l == r-1) return;
    int m = (l+r)/2;
    dat[lvl][m] = 1;
    for (int i = m-1; i >= l; i--) dat[lvl][i] = a[i]*dat[lvl][i+1]%p;
    for (int i = m+1; i <= r; i++) dat[lvl][i] = dat[lvl][i-1]*a[i-1]%p;
    for (int i = m; i < r; i++) mask[i] |= 1<<lvl;
    precalc(l, m, lvl+1);
    precalc(m, r, lvl+1);
}
int query(int L, int R) {
    if (L == R-1) return a[L];
    if (R == n) {
        int tz = __builtin_ctz(~mask[L]);
        return dat[tz][L]*dat[tz][n]%p;
    }
    int tz = __builtin_ctz(mask[L]^mask[R]);
    return dat[tz][L]*dat[tz][R]%p;
}

void solve() {
    memset(mask, 0, sizeof mask);
    memset(dat, 0, sizeof dat);
    cin >> n >> p >> q; 
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i] %= p;
    precalc(0, n, 0);
    b.resize(q/64+2);
    for (int i = 0; i < b.size(); i++) cin >> b[i];

    int x = 0;
    int l, r;
    for (int i = 0; i < q; i++) {
        if (i % 64 == 0) {
            l = (b[i/64]+x)%n;
            r = (b[i/64+1]+x)%n;
        } else {
            l = (l+x)%n;
            r = (r+x)%n;
        }
        if (l > r) swap(l, r);
        int ans = query(l, r+1);
        x = (ans+1)%p;
    }
    cout << x << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
