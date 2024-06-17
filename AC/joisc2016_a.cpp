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
vi t;
void init_tree() {
    int size = 1;
    while (size < 2*(n+q)) size *= 2;
    t.resize(size);
}
void point_relax(int v, int l, int r, int i, int x) {
    if (l == r-1) {
        ckmax(t[v], x);
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_relax(2*v+1, l, m, i, x);
    else point_relax(2*v+2, m, r, i, x);
    t[v] = max(t[2*v+1], t[2*v+2]);
}
void point_relax(int i, int x) { point_relax(0, 0, n+q, i, x); }
int range_max(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return max(range_max(2*v+1, l, m, L, R), range_max(2*v+2, m, r, L, R));
}
int range_max(int L, int R) { return range_max(0, 0, n+q, L, R); }

void solve() {
    cin >> n >> q;
    init_tree();
    vi heights;
    V<array<int, 2>> doll(n);
    for (int i = 0; i < n; i++) {
        cin >> doll[i][0] >> doll[i][1];
        heights.pb(doll[i][1]);
    }

    V<pair<array<int, 2>, int>> queries(q);
    for (int i = 0; i < q; i++) {
        cin >> queries[i].f[0] >> queries[i].f[1];
        heights.pb(queries[i].f[1]);
        queries[i].s = i;
    }

    sort(all(heights));
    for (int i = 0; i < n; i++) doll[i][1] = lwb(heights, doll[i][1]);
    for (int i = 0; i < q; i++) queries[i].f[1] = lwb(heights, queries[i].f[1]);

    sort(all(doll), [&](const array<int, 2>& a, const array<int, 2>& b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    });
    sort(rall(queries));

    vi ans(q);
    for (int i = 0, j = 0; i < q; i++) {
        while (j < n && doll[j][0] >= queries[i].f[0]) {
            int mx = range_max(0, doll[j][1]+1);
            point_relax(doll[j][1], mx+1);
            j++;
        }
        ans[queries[i].s] = range_max(0, queries[i].f[1]+1);
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
