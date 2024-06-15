#include <bits/stdc++.h>
using namespace std;
#define int int64_t

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

const int X = 2e5+1;
struct SegmentTree {
    struct Node {
        int32_t l, r, mx;
        Node() {
            l = r = -1;
            mx = 0;
        }
    } t[8'000'000];
    int tree_sz = 1;
    void extend(int v) {
        if (t[v].l == -1) {
            t[v].l = tree_sz++;
            t[v].r = tree_sz++;
        }
    }
    int range_max(int v, int l, int r, int L, int R) {
        if (r <= L || R <= l) return 0;
        if (L <= l && r <= R) return t[v].mx;
        int m = (l+r)/2;
        extend(v);
        return max(range_max(t[v].l, l, m, L, R), range_max(t[v].r, m, r, L, R));
    }
    int range_max(int L, int R) { return range_max(0, -X, X, L, R); }
    void point_relax(int v, int l, int r, int i, int x) {
        if (l == r-1) {
            ckmax(t[v].mx, (int32_t)x);
            return;
        }
        int m = (l+r)/2;
        extend(v);
        if (i < m) point_relax(t[v].l, l, m, i, x);
        else point_relax(t[v].r, m, r, i, x);
        t[v].mx = max(t[t[v].l].mx, t[t[v].r].mx);
    }
    void point_relax(int i, int x) { point_relax(0, -X, X, i, x); }
};

SegmentTree tr[2];

void solve() {
    int n, x; cin >> n >> x;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    auto A = a; sort(all(A));
    for (int i = 0; i < n; i++) {
        a[i] = lwb(A, a[i]);
    }

    int ans = 0;
    vi dp(2);
    for (int i = n-1; i >= 0; i--) {
        dp[0] = tr[0].range_max(a[i]+1, X)+1;
        if (x > 0) {
            dp[1] = max(tr[0].range_max(upb(A, A[a[i]]-x), X), tr[1].range_max(a[i]+1, X))+1;
        }
        tr[0].point_relax(a[i], dp[0]);
        tr[1].point_relax(a[i], dp[1]);
        ckmax(ans, max(dp[0], dp[1]));
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
