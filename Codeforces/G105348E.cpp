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
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define len(x) (int)((x).size())
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
#define pct __builtin_popcountll 
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

V<vi> g;
vi max_dep, ans;

void precalc(int u, int p) {
    for (int v : g[u]) if (v != p) {
        precalc(v, u);
        ckmax(max_dep[u], max_dep[v]+1);
    }
}

void reroot(int u, int p, int super) {
    int mx0 = 0, mx1 = 0, mx0_nod = -1;
    for (int v : g[u]) if (v != p) {
        if (max_dep[v]+1 > mx0) {
            ckmax(mx1, mx0);
            mx0 = max_dep[v]+1;
            mx0_nod = v;
        } else {
            ckmax(mx1, max_dep[v]+1);
        }
    }
    ans[u] = mx0+max(super, mx1);
    for (int v : g[u]) if (v != p) {
        reroot(v, u, max(super+1, mx0_nod == v ? mx1+1 : mx0+1));
    }
}


void solve() {
    int n; cin >> n;
    g.assign(n, vi());
    max_dep.assign(n, 0);
    ans.assign(n, 0);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    precalc(0, -1);
    reroot(0, -1, 0);
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
