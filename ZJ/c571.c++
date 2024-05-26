// AC

#include <bits/stdc++.h>
using namespace std;

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

int n;
V<array<int, 4>> v;
vi x, y, z, ans;

vi t;
void init_tree() {
    int size = 1;
    while (size < 2*n) size *= 2;
    t.resize(size);
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

bool cmp(const array<int, 4>& a, const array<int, 4>& b) {
    if (a[0] != b[0]) return a[0] > b[0];
    if (a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}

void cdq(int l, int r) {
    if (l == r-1) return;
    int m = (l+r)/2;
    cdq(l, m); cdq(m, r);

    V<array<int, 4>> tmp;
    vi hist;
    int a = l, b = m;
    while (a < m && b < r) {
        if (v[a][1] > v[b][1]) point_add(v[a][2], 1), hist.pb(v[a][2]), tmp.pb(v[a++]);
        else ans[v[b][3]] += range_sum(v[b][2]+1, n), tmp.pb(v[b++]);
    }
    while (a < m) tmp.pb(v[a++]);
    while (b < r) ans[v[b][3]] += range_sum(v[b][2]+1, n), tmp.pb(v[b++]);
    for (int i = l; i < r; i++) v[i] = tmp[i-l];
    for (int pos : hist) point_add(pos, -1);
}

void solve() {
    cin >> n;    
    x.resize(n); y.resize(n); z.resize(n); ans.resize(n);
    for (int i = 0; i < n; i++) {
        int x, y, z; cin >> x >> y >> z; x--; y--; z--;
        v.push_back({x, y, z, i});
    }
    sort(all(v), cmp);
    init_tree();
    cdq(0, n);
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
