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

struct SegmentTree {
    vi t;
    SegmentTree(int n) {
        int size = 1;
        while (size < 2*n) size *= 2;
        t.resize(size);
    }
    void pull(int v) {
        t[v] = t[2*v+1] + t[2*v+2];
    }
    int range_sum(int v, int l, int r, int L, int R) {
        if (r <= L || R <= l) return 0;
        if (L <= l && r <= R) return t[v];
        int m = (l+r)/2;
        return range_sum(2*v+1, l, m, L, R) + range_sum(2*v+2, m, r, L, R)
    }
    void point_add(int v, int l, int r, int i, int x) {
        if (l == r-1) {
            t[v] += x;
            return;
        }
        int m = (l+r)/2;
        if (i < x) point_add(2*v+1, l, m, i, x);
        pull(v);
    }
};

void solve() {
    cin >> n;
    V<array<int, 2>> pairs;
    vi xs;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r;
        pairs[i] = {l, r};
        xs.pb(l); xs.pb(r);
    }
    sort(all(xs));
    int m = xs.size();
    V<vi> rbs(m);
    for (auto [l, r] : pairs) {
        l = lwb(all(xs), l);
        r = lwb(all(xs), r);
        rbs[l].pb(r);
    }

    for (int l = 0; l < m; l++) {


        for (int r : rbs[l]) {

        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
