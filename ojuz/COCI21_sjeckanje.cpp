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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

bool same_sign(int x, int y) {
    if (!x || !y) return true;
    return x<0&&y<0 || x>0&&y>0;
}
const array<int, 4> zero = {0, 0, 0, 0};

int n;
vi d;
V<array<int, 4>> t;
array<int, 4> merge(int l, int m, int r, array<int, 4> a, array<int, 4> b) {
    array<int, 4> res = zero;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (m-l == 1 && (i == 1 || i == 2)) continue;
            if (r-m == 1 && (j == 1 || j == 2)) continue;
            if (i%2 && (j==0b10 || j == 0b11) && !same_sign(d[m-1], d[m])) continue;

            int new_shape = (i&0b10)+(j&0b01);
            ckmax(res[new_shape], a[i]+b[j]);
        }
    }
    return res;
}
void init_tree() {
    int siz = 1;
    while (siz < 2*n) siz *= 2;
    t.resize(siz, zero);
}
void point_upd(int ind, int u=0, int l=0, int r=n) {
    if (l == r-1) {
        t[u][0] = 0;
        t[u][3] = abs(d[ind]);
        return;
    }
    int m = (l+r)/2;
    if (ind < m) point_upd(ind, 2*u+1, l, m);
    else point_upd(ind, 2*u+2, m, r);
    t[u] = merge(l, m, r, t[2*u+1], t[2*u+2]);
}

void solve() {
    int q; cin >> n >> q;
    vi a(n);
    for (int& i : a) cin >> i;
    n--;
    init_tree();
    d.resize(n);
    for (int i = 0; i < n; i++) {
        d[i] = a[i+1]-a[i];
        point_upd(i);
    }

    while (q--) {
        int l, r, x; cin >> l >> r >> x; l--;
        if (l-1 >= 0) {
            d[l-1] += x;
            point_upd(l-1);
        }
        if (r-1 < n) {
            d[r-1] -= x;
            point_upd(r-1);
        }
        cout << *max_element(all(t[0])) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
