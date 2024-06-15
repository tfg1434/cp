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

const int X = 1e9+1;
struct Node {
    int l, r, mx;
    Node() {
        l = r = -1;
        mx = 0;
    }
} t[7'000'000];
int tree_sz = 1;
void extend(int v) {
    if (t[v].l == -1) {
        t[v].l = tree_sz++;
        t[v].r = tree_sz++;
    }
}
int range_max(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return t[v].mx;
    int m = (l+r)/2;
    extend(v);
    return max(range_max(t[v].l, l, m, L, R), range_max(t[v].r, m, r, L, R));
}
int range_max(int L, int R) { return range_max(0, -X, X, L, R); }
void point_relax(int v, int l, int r, int i, int x) {
    if (l == r-1) {
        ckmax(t[v].mx, x);
        return;
    }
    int m = (l+r)/2;
    extend(v);
    if (i < m) point_relax(t[v].l, l, m, i, x);
    else point_relax(t[v].r, m, r, i, x);
    t[v].mx = max(t[t[v].l].mx, t[t[v].r].mx);
}
void point_relax(int i, int x) { point_relax(0, -X, X, i, x); }


void solve() {
    int n; cin >> n;
    V<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) {
        int s, t; cin >> s >> t;
        a[i] = {s-t, s+t};
    }
    sort(all(a), [](const array<int, 2>& x, const array<int, 2>& y) {
        if (x[1] == y[1]) return x[0] < y[0];
        return x[1] > y[1];
    });

    vi lds(n);
    for (int i = 0; i < n; i++) {
        int mx = range_max(a[i][0]+1, X);
        lds[i] = mx+1;
        point_relax(a[i][0], mx+1);
    }

    cout << range_max(-X, X) << '\n';
    for (int i = 0; i < n; i++) {
        int t = (a[i][1]-a[i][0])/2;
        int s = a[i][0] + t;
        cout << s << ' ' << t << ' ' << lds[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
