// this is slow, and there's a bug! ;)
// need to do 2-pointers merging like mergesort

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
V<array<int, 3>> inp;
map<array<int, 3>, vi> inds;
vi ans, z, x, y;

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

void dnc(int l, int r) {
    if (l == r-1) return;
    int m = (l+r)/2;

    V<array<int, 4>> events; // x, type, y, INFO(z)
    for (int i = l; i < m; i++) events.pb({x[i], 1, y[i], z[i]});
    for (int i = m; i < r; i++) events.pb({ x[i], 0, y[i], -1 });

    auto process_events = [&](bool minus=false) {
        sort(rall(events));
        for (auto [X, TYPE, Y, INFO] : events) {
            if (TYPE == 1) {
                int dominated_by = range_sum(Y+1, n);
                // ps("query", Y+1, n, dominated_by);
                for (int ind : inds[{INFO, X, Y}]) {
                    if (minus) ans[ind] -= dominated_by;
                    else ans[ind] += dominated_by;
                }
            } else {
                // ps("add", Y);
                point_add(Y, 1);
            }
        }
        for (auto [X, TYPE, Y, INFO] : events) 
            if (TYPE == 0) point_add(Y, -1);
    };
    process_events();

    // correct for overcounting those w/ equal z
    events.clear();
    for (int i = l; i < m; i++) if (z[i] == z[m])
        events.pb({x[i], 1, y[i], z[i]});
    for (int i = m; i < r; i++) if (z[i] == z[m])
        events.pb({x[i], 0, y[i], -1});
    process_events(true);
    
    dnc(l, m);
    dnc(m, r);
}

void solve() {
    cin >> n;
    inp.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> inp[i][0] >> inp[i][1] >> inp[i][2];
        for (int j = 0; j < 3; j++) inp[i][j]--;
        inds[{ inp[i][0], inp[i][1], inp[i][2] }].pb(i);
    }
    sort(all(inp));
    x.resize(n); y.resize(n); z.resize(n);
    for (int i = 0; i < n; i++) {
        z[i] = inp[i][0];
        x[i] = inp[i][1];
        y[i] = inp[i][2];
    }
    init_tree();
    // point_add(0, 5);
    // point_add(5, 5);
    // ps(range_sum(0, 6));
    dnc(0, n);
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
