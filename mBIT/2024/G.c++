#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 2e18;

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

const int max_x = 1e9+1;

struct Node {
    int32_t l, r;
    int mn;
    Node() {
        l = r = -1;
        mn = inf;
    }
};

struct SegmentTree {
    int tree_sz;
    V<Node> t;
    SegmentTree() { 
        tree_sz = 1;
        t.resize(6'000'000);
    };
    void extend(int v) {
        if (t[v].l == -1) {
            t[v].l = tree_sz++;
            t[v].r = tree_sz++;
            t[t[v].l] = Node();
            t[t[v].r] = Node();
        }
    }
    int range_min(int v, int l, int r, int L, int R) {
        if (r <= L || R <= l) return inf;
        if (L <= l && r <= R) return t[v].mn;

        int m = (l+r)/2;
        extend(v);
        return min(range_min(t[v].l, l, m, L, R), range_min(t[v].r, m, r, L, R));
    }
    int range_min(int L, int R) {
        // ps("min on", L, R, "is", range_min(0, 0, max_x, L, R));
        return range_min(0, 0, max_x, L, R);
    }
    void point_relax(int v, int l, int r, int i, int x, bool force=false) {
        if (l == r-1) {
            if (force) t[v].mn = x;
            else ckmin(t[v].mn, x);
            return;
        }
        int m = (l+r)/2;
        extend(v);
        if (i < m) point_relax(t[v].l, l, m, i, x);
        else point_relax(t[v].r, m, r, i, x);
        t[v].mn = min(t[t[v].l].mn, t[t[v].r].mn);
    }
    void point_relax(int i, int x, bool force=false) {
        // ps("set", i, x);
        point_relax(0, 0, max_x, i, x, force);
    }
    void clear() {
        for (int i = 0; i < tree_sz; i++) t[i] = Node();
        tree_sz = 1;
    }
};

SegmentTree pos, neg;

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vi dp(n+1, inf);
    dp[0] = 0;
    int min_dp = inf;
    for (int j = 1; j <= n; j++) {
        if (j < n) {
            ckmin(dp[j], pos.range_min(a[j], max_x) - a[j]-abs(a[j]-a[j-1]));
            ckmin(dp[j], neg.range_min(0, a[j]) + a[j]-abs(a[j]-a[j-1]));
        } else {
            ckmin(dp[j], min_dp);
        }

        ckmin(dp[j], dp[0] - (j<n ? abs(a[j]-a[j-1]) : 0));

        ckmin(min_dp, dp[j]);
        pos.point_relax(a[j-1], dp[j]+a[j-1]);
        neg.point_relax(a[j-1], dp[j]-a[j-1]);
    }

    int base = 0;
    for (int i = 0; i+1 < n; i++) base += abs(a[i]-a[i+1]);
    cout << dp[n]+base << '\n';

    pos.clear();
    neg.clear();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

