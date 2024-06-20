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

int c2(int x) { return x*(x-1)/2; }

const int N = 5e4;
int tin[N], tout[N], timer, euler[N];
int sub[N], hr[N], hc[N], n, par[N], sum_light[N];
bool a[N];
vi g[N];
void init() {
    fill(all(sub), 1);
    fill(all(hc), -1);
}

vi t;
V<bool> buf;
void build(int v=0, int l=0, int r=n) {
    if (l == r-1) {
        t[v] = a[euler[l]];
        return;
    }
    int m = (l+r)/2;
    build(2*v+1, l, m);
    build(2*v+2, m, r);
    t[v] = t[2*v+1]+t[2*v+2];
}
void init_tree() {
    int size = 1;
    while (size < 2*n) size *= 2;
    t.resize(size);
    buf.resize(size);
    build();
}
void pd(int v, int l, int r) {
    if (!buf[v]) return;
    t[v] = r-l - t[v];
    if (l < r-1) {
        buf[2*v+1] = !buf[2*v+1];
        buf[2*v+2] = !buf[2*v+2];
    }
    buf[v] = false;
}
void range_flip(int L, int R, int v=0, int l=0, int r=n) {
    pd(v, l, r);
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        buf[v] = true;
        pd(v, l, r);
        return;
    }
    int m = (l+r)/2;
    range_flip(L, R, 2*v+1, l, m);
    range_flip(L, R, 2*v+2, m, r);
    t[v] = t[2*v+1]+t[2*v+2];
}
int range_sum(int L, int R, int v=0, int l=0, int r=n) {
    pd(v, l, r);
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return range_sum(L, R, 2*v+1, l, m) + range_sum(L, R, 2*v+2, m, r);
}

void calc_sub(int u, int p) {
    for (int v : g[u]) if (v != p) {
        calc_sub(v, u);
        sub[u] += sub[v];
    }
}

void init_hld(int u, int p) {
    par[u] = p;
    euler[timer] = u;
    tin[u] = timer++;
    int mx = 0;
    for (int v : g[u]) if (v != p) {
        if (ckmax(mx, sub[v])) hc[u] = v;
    }
    if (hc[u] != -1) {
        hr[hc[u]] = hr[u];
        init_hld(hc[u], u);
    }
    for (int v : g[u]) if (v != p && v != hc[u]) {
        hr[v] = v;
        init_hld(v, u);
    }
    tout[u] = timer;
}


void calc_hld(int u, int p) {
    if (hc[u] != -1) {
        calc_hld(hc[u], u);
    }
    for (int v : g[u]) if (v != p && v != hc[u]) {
        calc_hld(v, u);
        sum_light[u] += c2(range_sum(tin[v], tout[v]));
    }
}

void solve() {
    init();
    int q; cin >> n >> q;
    for (int i = 0; i < n; i++) {
        int bw; cin >> bw;
        a[i] = bw;
    } 
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    calc_sub(0, -1);
    init_hld(0, -1);
    init_tree();
    calc_hld(0, -1);

    while (q--) {
        int tp, u; cin >> tp >> u; u--;
        if (tp == 1) {
            {
                int U = u;
                while (true) {
                    if (hr[U] != 0) {
                        sum_light[par[hr[U]]] -= c2(range_sum(tin[hr[U]], tout[hr[U]]));
                    } else {
                        break;
                    }
                    U = par[hr[U]];
                }
            }

            while (true) {
                if (hr[u] != 0) {
                    range_flip(tin[hr[u]], tin[u]+1);
                    sum_light[par[hr[u]]] += c2(range_sum(tin[hr[u]], tout[hr[u]]));
                } else {
                    range_flip(tin[hr[u]], tin[u]+1);
                    break;
                }
                u = par[hr[u]];
            }


        } else {
            if (hc[u] == -1) {
                cout << 0 << '\n';
                continue;
            }

            int ans = c2(range_sum(tin[u], tout[u]));
            ans -= sum_light[u]; 
            ans -= c2(range_sum(tin[hc[u]], tout[hc[u]]));
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
