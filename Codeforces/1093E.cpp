#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx,avx2")

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

int n, q;
struct node {
    int x, y, ind, sgn, val;
};
V<node> v;
vi ans;

vi t;
void init_tree() {
    int size = 1;
    while (size < 2*n) size *= 2;
    t.assign(size, 0);
}
void point_add(int v, int l, int r, int i, int x) {
    if (l == r-1) {
        t[v] += x;
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_add(2*v+1, l, m, i, x);
    else point_add(2*v+2, m, r, i, x);
    t[v] = t[2*v+1] + t[2*v+2];
}
void point_add(int i, int x) { point_add(0, 0, n, i, x); }
int range_sum(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return range_sum(2*v+1, l, m, L, R) + range_sum(2*v+2, m, r, L, R);
}
int range_sum(int L, int R) { return range_sum(0, 0, n, L, R); }


void cdq(int l, int r) {
    if (l == r-1) return;
    int m = (l+r)/2;
    cdq(l, m); cdq(m, r);

    V<node> tmp;
    V<array<int, 2>> hist;
    int a = l, b = m;
    while (a < m && b < r) {
        if (v[a].x >= v[b].x) point_add(v[a].y, v[a].val), hist.pb({ v[a].y, v[a].val }), tmp.pb(v[a++]);
        else ans[v[b].ind] += v[b].sgn*range_sum(v[b].y, n), tmp.pb(v[b++]);
    }
    while (a < m) tmp.pb(v[a++]);
    while (b < r) ans[v[b].ind] += v[b].sgn*range_sum(v[b].y, n), tmp.pb(v[b++]);
    for (int i = l; i < r; i++) v[i] = tmp[i-l];
    for (int i = 0; i < hist.size(); i++) point_add(hist[i][0], -hist[i][1]);
}

void solve() {
    cin >> n >> q;
    vi a(n), b(n), wa(n), wb(n); 
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--, wa[a[i]] = i;
    for (int i = 0; i < n; i++) cin >> b[i], b[i]--, wb[b[i]] = i;
    init_tree();

    ans.pb(69);
    for (int i = 0; i < n; i++) v.pb(node{wa[i], wb[i], 0, 0, 1});
    for (int i = 0; i < q; i++) {
        int tp; cin >> tp;
        if (tp == 1) {
            int la, ra, lb, rb; cin >> la >> ra >> lb >> rb; la--; lb--;
            v.pb(node{la, lb, (int)ans.size(), 1, 0});
            v.pb(node{ra, rb, (int)ans.size(), 1, 0});
            v.pb(node{la, rb, (int)ans.size(), -1, 0});
            v.pb(node{ra, lb, (int)ans.size(), -1, 0});
            ans.pb(0);
        } else {
            int x, y; cin >> x >> y; x--; y--;
            v.pb(node{wa[b[x]], x, 0, 0, -1});
            v.pb(node{wa[b[y]], y, 0, 0, -1});
            swap(b[x], b[y]);
            v.pb(node{wa[b[x]], x, 0, 0, 1});
            v.pb(node{wa[b[y]], y, 0, 0, 1});
        }
    }

    cdq(0, v.size());

    for (int i = 1; i < ans.size(); i++) {
        cout << ans[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
