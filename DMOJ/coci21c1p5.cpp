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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

vi t;
int n;

void init_tree() {
    int size = 1; 
    while (size < 2*n) size *= 2;
    t.assign(size, 0);
}
void point_set(int v, int l, int r, int i, int x) {
    if (l == r-1) {
        t[v] = x;
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_set(2*v+1, l, m, i, x);
    else point_set(2*v+2, m, r, i, x);
    t[v] = max(t[2*v+1], t[2*v+2]);
}
void point_set(int i, int x) { point_set(0, 0, n, i, x); }
int range_max(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return max(range_max(2*v+1, l, m, L, R), range_max(2*v+2, m, r, L, R));
}
int range_max(int L, int R) { return range_max(0, 0, n, L, R); }

void solve() {
    cin >> n;
    vi p(n); for (int i = 0; i < n; i++) cin >> p[i], p[i]--;
    init_tree();

    int len = 0;
    V<vi> where(n+1);
    vi pos(n+1);
    for (int i = n-1; i >= 0; i--) {
        int mx = range_max(p[i], n);
        where[mx+1].pb(i);
        ckmax(len, mx+1);
        point_set(p[i], mx+1);
    }
    for (int i = 1; i <= len; i++) reverse(all(where[i]));

    vi path;
    auto dfs = [&](auto&& dfs, int i, int j) {
        if (i == 0) return true;
        while (pos[i] < where[i].size() && (j != -1 && where[i][pos[i]] < j)) pos[i]++;
        if (pos[i] == where[i].size() || (j != -1 && p[where[i][pos[i]]] < p[j])) return false;

        while (pos[i] < where[i].size() && (j == -1 || p[where[i][pos[i]]] > p[j])) {
            if (dfs(dfs, i-1, where[i][pos[i]])) {
                path.pb(where[i][pos[i]]);
                pos[i]++;
                return true;
            }
            pos[i]++;
        }
        return false;
    };

    V<vi> sol;
    while (true) {
        path.clear();
        if (dfs(dfs, len, -1)) {
            reverse(all(path));
            sol.pb(path);
        } else {
            break;
        }
    }

    cout << sol.size() << ' ' << len << '\n';
    for (auto v : sol) {
        for (int i = 0; i < len; i++) {
            cout << v[i]+1 << " \n"[i==len-1];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
