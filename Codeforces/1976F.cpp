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

// dp(u, k) = max number of edges covered in subtree u by choosing k leaves
// gap[i] = dp(u, i+1)-dp(u, i)
// when we merge one dp (say dp[u]) into new_dp, the process is as follows:
// 1. merge the set of gaps
// we are missing the edge connecting these two trees, so
// 2. add 1 to the first gap (if you have no leaves you dont get it), and if
//    you have leaves then you do

int leaves;
V<multiset<int>> gaps;
V<vi> g;
void calc_dp(int u, int p) {
    bool is_leaf = true;
    for (int v : g[u]) if (v != p) {
        is_leaf = false;
        calc_dp(v, u);
        if (gaps[v].size() > gaps[u].size()) {
            swap(gaps[u], gaps[v]);
        }
        for (int gap : gaps[v]) {
            gaps[u].insert(gap);
        }
        int mn = *gaps[u].begin();
        gaps[u].erase(gaps[u].begin());
        gaps[u].insert(mn+1);
    }
    if (is_leaf) {
        gaps[u].insert(0);
        leaves++;
    }
}

void solve() {
    int n; cin >> n;
    leaves = 0;
    g.assign(n, vi());
    gaps.assign(n, multiset<int>());

    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    calc_dp(0, -1);
    int ans = 0;
    vi gaps0(all(gaps[0]));
    for (int i = 0; i+1 < gaps0.size(); i++) gaps0[i+1] += gaps0[i];
    // choose 2k-1 non-root leaves
    for (int k = 1; k <= n-1; k++) {
        if (2*k-1 <= leaves) {
            cout << n-1-gaps0[2*k-1-1] << ' ';
        } else {
            cout << 0 << ' ';
        }
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
