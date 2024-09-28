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

vi t;
void init_tree() {
    int siz = 1;
    while (siz < 2*n) siz *= 2;
    t.resize(siz);
}
void point_set(int i, int x, int u=0, int l=0, int r=n) {
    if (l == r-1) {
        t[u] = x;
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_set(i, x, 2*u+1, l, m);
    else point_set(i, x, 2*u+2, m, r);
}
int query(int L, int R, int u=0, int l=0, int r=n) {
    if (r <= L || R <= l) return 1;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return query(L, R, 2*u+1, l, m)*query(L, R, 2*u+2, m, r);
}

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    build(b);

    int q; cin >> q;
    while (q--) {
        int typ; cin >> typ;
        if (typ == 1) {
            int i, x; 
        }
        if (typ == 2) {

        }
        if (typ == 3) {
            int l, r; cin >> l >> r; l--;
            a[l]+
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

