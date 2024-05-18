#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

const int max_n = 2e5, max_bit = 17;
int n, q, a[max_n], ans[max_n];
array<int, 2> queries[max_n];
int lef[max_n+1], rig[max_n+1];

void answer_queries(int l, int r, vi query_inds) {
    if (l == r-1) {
        for (int ind : query_inds) ans[ind] = a[l];
        return;
    }
    int m = (l+r)/2;
    lef[m] = rig[m] = inf;
    lef[m-1] = a[m-1];
    for (int i = m-2; i >= l; i--) lef[i] = min(lef[i+1], a[i]);
    rig[m+1] = a[m];
    for (int i = m+2; i <= r; i++) rig[i] = min(rig[i-1], a[i-1]);
    vi todo[2];
    for (auto ind : query_inds) {
        if (queries[ind][0] <= m && m <= queries[ind][1]) {
            ans[ind] = min(lef[queries[ind][0]], rig[queries[ind][1]]);
            continue;
        }
        todo[queries[ind][0] >= m].pb(ind);
    }
    answer_queries(l, m, todo[0]);
    answer_queries(m, r, todo[1]);
}

void solve() {
    cin >> n >> q; 
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) {
        cin >> queries[i][0] >> queries[i][1]; queries[i][0]--;
    }
    vi query_inds(q); iota(all(query_inds), 0);
    answer_queries(0, n, query_inds);
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
