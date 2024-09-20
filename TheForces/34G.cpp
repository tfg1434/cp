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
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

int timer = 1;
const int N = 3e5 + 1;
int tin[N], tout[N], tout0[N], ind[N];
vi g[N];

int t[4*N], buf[4*N];
void pull(int v) { t[v] = max(t[2*v+1],t[2*v+2]); }
void push(int v, int len) {
    if (!buf[v]) return;
    t[v] += buf[v];
    if (len > 1) {
        buf[2*v+1] += buf[v];
        buf[2*v+2] += buf[v];
    }
    buf[v] = 0;
}
void range_add(int L, int R, int x, int u=0, int l=1, int r=N+1) {
    push(u, r-l);
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        buf[u] = x;
        push(u, r-l);
        return;
    }
    int m = (l+r)/2;
    range_add(L, R, x, 2*u+1, l, m);
    range_add(L, R, x, 2*u+2, m, r);
    pull(u);
}
int range_max(int L, int R, int u=0, int l=1, int r=N+1) {
    push(u, r-l);
    if (r <= L || R <= l) return -inf;
    if (L <= l && r <= R) return t[u];
    int m = (l+r)/2;
    int res = max(range_max(L, R, 2*u+1, l, m), range_max(L, R, 2*u+2, m, r));
    return res;
}

void dfs(int u, int p) {
    bool first = true;
    for (int v : g[u]) if (v != p) {
        if (first) {
            tin[u] = timer;  
            first = false;
        }
        ind[v] = timer++;
        tout0[u] = timer;
    }
    for (int v : g[u]) if (v != p) {
        dfs(v, u);
    }
    tout[u] = timer;
}

void solve() {
    int n, q; cin >> n >> q; 
    for (int i = 0; i < n-1; i++){
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    dfs(0, -1);

    ind[0] = timer++;
    while (q--) {
        int typ, u; cin >> typ >> u; u--;
        if (typ == 1) {
            int val; cin >> val;
            range_add(ind[u], ind[u]+1, val);
            // range_add(ind[u], ind[u], val);
            if (tin[u]) range_add(tin[u], tout[u], val);
            // if (tin[u]) range_add(tin[u], tout[u]-1, val);
        }
        if (typ == 2) {
            int val; cin >> val;
            assert(tin[u]);
            range_add(tin[u], tout0[u], val);
            // range_add(tin[u], tout0[u]-1, val);
        }
        if (typ == 3) {
            int ans = range_max(ind[u], ind[u]+1);
            // int ans = range_max(ind[u], ind[u]);
            if (tin[u]) ckmax(ans, range_max(tin[u], tout[u]));
            // if (tin[u]) ckmax(ans, range_max(tin[u], tout[u]-1));
            cout << ans << '\n';
        }
        if (typ == 4) {
            assert(tin[u]);
            int ans = range_max(tin[u], tout0[u]);
            // int ans = range_max(tin[u], tout0[u]-1);
            cout << ans << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
