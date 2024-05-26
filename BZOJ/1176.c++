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

int sign(int x) {
    if (x < 0) return -1;
    if (x > 0) return 1;
    return 0;
}

struct node {
    int x, y, val, ind;
};
int S, W;
V<node> v;
vi ans;

vi t;
void init_tree() {
    int size = 1;
    while (size < 2*W) size *= 2;
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
void point_add(int i, int x) { point_add(0, 0, W, i, x); }
int range_sum(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return range_sum(2*v+1, l, m, L, R) + range_sum(2*v+2, m, r, L, R);
}
int range_sum(int L, int R) { return range_sum(0, 0, W, L, R); }

void cdq(int l, int r) {
    if (l == r-1) return;
    int m = (l+r)/2;
    cdq(l, m); cdq(m, r);

    V<node> tmp;
    V<array<int, 2>> hist;
    int a = l, b = m;
    while (a < m && b < r) {
        if (v[a].x < v[b].x) {
            point_add(v[a].y, v[a].val);
            hist.pb({v[a].y, v[a].val});
            tmp.pb(v[a++]);
        } else {
            ans[abs(v[b].ind)] += sign(v[b].ind)*range_sum(0, v[b].y);
            tmp.pb(v[b++]);
        }
    }
    while (a < m) tmp.pb(v[a++]);
    while (b < r) {
        ans[abs(v[b].ind)] += sign(v[b].ind)*range_sum(0, v[b].y);
        tmp.pb(v[b++]);
    }
    for (int i = l; i < r; i++) v[i] = tmp[i-l];
    for (int i = 0; i < hist.size(); i++) 
        point_add(hist[i][0], -hist[i][1]);
}

void solve() {
    cin >> S >> W;    
    init_tree();
    ans.pb(-1);
    int tp; while (cin >> tp) {
        if (tp == 3) break;
        if (tp == 1) {
            int x, y, a; cin >> x >> y >> a; x--; y--;
            v.pb({x, y, a, 0});
        }
        if (tp == 2) {
            int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1; x0--; y0--;
            v.pb({x1, y1, 0, (int)ans.size()});
            v.pb({x0, y0, 0, (int)ans.size()});
            v.pb({x1, y0, 0, (int)-ans.size()});
            v.pb({x0, y1, 0, (int)-ans.size()});
            ans.pb(S*(x1-x0)*(y1-y0));
        }
    }
    cdq(0, v.size());
    for (int i = 1; i < ans.size(); i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
