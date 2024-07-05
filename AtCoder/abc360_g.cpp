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

const int MAX = 1e9+1;
struct Node {
    int l, r, mx;
    Node() : l(-1), r(-1), mx() {}
} t[24'000'000];
int cur_node=1;

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
void point_ckmax(int i, int x) { point_ckmax(0, 0, MAX, i, x); }

int range_max(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return t[v].mx;
    int m = (l+r)/2;
    extend(v);
    return max(range_max(t[v].l, l, m, L, R), range_max(t[v].r, m, r, L, R));
}
int range_max(int L, int R) { return range_max(0, 0, MAX, L, R); }

void solve() {
    int n; cin >> n;
    vi a(n); 
    for (int i = 0; i < n; i++) cin >> a[i];
    int mx = 0;
    vi lis(n);
    for (int i = n-1; i >= 0; i--) {
        lis[i] = range_max(a[i]+1, MAX)+1;
        point_ckmax(a[i], lis[i]);
        ckmax(mx, lis[i]);
    }

    V<vi> group(mx+1);
    for (int i = 0; i < n; i++) group[lis[i]].pb(i);
    V<bool> reachable(n);
    for (int i : group[1]) reachable[i] = true;
    for (int x = 1; x <= mx; x++) {
        sort(all(group[x]));
        int m = group[x].size();

        int p = 0;
        int k = 0;
        for (int j = 0; j < m-1; j++) {
            bool reachable = false;
            if (x == 1) {
                reachable = true;
            } else {
                while (p < group[x-1].size() && a[group[x-1][p]] > a[group[x][j]]) p++;
                reachable = p < group[x-1].size();
            }
            if (!reachable) continue;

            if (x == mx) {
                cout << mx+1 << '\n';
                return;
            }
            while (k < group[x+1].size() && group[x+1][k] < group[x][j+1]) k++;
            if (k == group[x+1].size()) break;
            if (a[group[x+1][k]] > a[group[x][j]]+1) {
                cout << mx+1 << '\n';
                return;
            }
        }

        k = 0;
        for (int j = 0; j < m; j++) if (reachable[j]) {

        }
    }
    cout << mx << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
