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

const int MAX = 1e9+1;

namespace SegmentTree {
struct Node {
    int l, r, mx;
    Node() : l(-1), r(-1), mx() {}
} t[25'000'000];
int cur_node;

struct Tree {
    int root;

    void extend(int v) {
        if (t[v].l == -1) {
            t[v].l = cur_node++;
            t[v].r = cur_node++;
        }
    }

    void pull(int v) {
        t[v].mx = max(t[t[v].l].mx, t[t[v].r].mx);
    }

    void point_ckmax(int v, int l, int r, int i, int x) {
        if (l == r-1) {
            ckmax(t[v].mx, x);
            return;
        }
        int m = (l+r)/2;
        extend(v);
        if (i < m) point_ckmax(t[v].l, l, m, i, x);
        else point_ckmax(t[v].r, m, r, i, x);
        pull(v);
    }
    void point_ckmax(int i, int x) { point_ckmax(root, 1, MAX, i, x); }

    void point_ckmin(int v, int l, int r, int i, int x) {
        if (l == r-1) {
            ckmin(t[v].mx, x);
            return;
        }
        int m = (l+r)/2;
        extend(v);
        if (i < m) point_ckmin(t[v].l, l, m, i, x);
        else point_ckmin(t[v].r, m, r, i, x);
        pull(v);
    }
    void point_ckmin(int i, int x) { point_ckmin(root, 1, MAX, i, x); }

    int range_max(int v, int l, int r, int L, int R) {
        if (r <= L || R <= l) return 0;
        if (L <= l && r <= R) return t[v].mx;
        int m = (l+r)/2;
        extend(v);
        return max(range_max(t[v].l, l, m, L, R), range_max(t[v].r, m, r, L, R));
    }
    int range_max(int L, int R) { return range_max(root, 1, MAX, L, R); }
    Tree() {
        root = cur_node++;
    }
};
}

void solve() {
    int n; cin >> n;
    vi a(n); 
    for (int i = 0; i < n; i++) cin >> a[i];

    SegmentTree::Tree left, right;
    map<int, vi> longest_starting_at;
    for (int i = n-1; i >= 0; i--) {
        int best_len = right.range_max(a[i]+1, MAX)+1;
        longest_starting_at[a[i]].pb(best_len);
        right.point_ckmax(a[i], best_len);
    }

    int ans = 0;
    for (int i = 0; i < n; i++) { // set a[i] = a[i-1]+1 (or 0 if !i)
        longest_starting_at[a[i]].pop_back();
        right.point_ckmin(a[i], longest_starting_at[a[i]].size() ? longest_starting_at[a[i]].back() : 0); 

        int new_val = !i ? 0 : a[i-1]+1;
        int left_len = left.range_max(1, new_val);
        int right_len = right.range_max(new_val+1, MAX);
        ckmax(ans, left_len+1+right_len);

        left.point_ckmax(a[i], left.range_max(1, a[i])+1);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
