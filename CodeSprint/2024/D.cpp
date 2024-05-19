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

int n;
vi xs, ys;
const int max_n = 2e5;

vi t;
int range_max(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return max(range_max(2*v+1, l, m, L, R), range_max(2*v+2, m, r, L, R));
}
void point_set(int v, int l, int r, int i, int x) {
    if (l == r-1) {
        t[v] = max(t[v], x);
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_set(2*v+1, l, m, i, x);
    else point_set(2*v+2, m, r, i, x);
    t[v] = max(t[2*v+1], t[2*v+2]);
}
void init_tree() {
    int size = 1;
    while (size < 2*max_n) size *= 2;
    t.resize(size);
}

void solve() {
    init_tree();
    cin >> n; 
    xs.resize(n); ys.resize(n);
    for (int i = 0; i < n; i++) cin >> xs[i] >> ys[i];
    auto XS = xs, YS = ys; sort(all(XS)); sort(all(YS));
    for (int i = 0; i < n; i++) xs[i] = lwb(XS, xs[i]), ys[i] = lwb(YS, ys[i]);
    // for (int i = 0; i < n; i++) ps(xs[i], ys[i]);
    map<int, V<array<int, 2>>> m;
    for (int i = 0; i < n; i++) {
        m[xs[i]].pb({ys[i], i});
    }
    m[n].pb({n, n});

    vi dp(n+1);
    for (auto [u, v] : m) {
        for (auto [y, ind] : v) {
            dp[ind] = range_max(0, 0, max_n, 0, y)+1;
            // ps(u, y, dp[ind]);
        }
        for (auto [y, ind] : v) {
            // relax with the maximum value
            point_set(0, 0, max_n, y, dp[ind]);
        }
    }

    cout << dp[n]-1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
