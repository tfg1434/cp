#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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

vi par;
int find(int u) {
    return par[u] == u ? u : par[u] = find(par[u]);
};

void solve() {
    int n, q; cin >> n >> q;

    par.resize(n+1);
    iota(all(par), 0);

    V<array<int, 3>> ranges;
    for (int i = 0; i < q; i++) {
        int l, r, c; cin >> l >> r >> c; l--;
        ranges.pb({c, l, r});
    }
    sort(all(ranges));

    int mst_cost = 0, mst_cnt = 0;
    for (auto [w, l, r] : ranges) {
        mst_cost += w, mst_cnt++;
        l = find(l);
        while (l+1 < r) {
            par[l] = l+1;
            mst_cost += w, mst_cnt++;
            l = find(l);
        }
    }

    if (mst_cnt < n+q-1) {
        cout << -1 << '\n';
        return;
    }
    cout << mst_cost << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
