#include <bits/stdc++.h>
using namespace std;

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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int n, q, B;
V<vi> g;
vi c, lvl, sons, par;
multiset<array<int, 2>> lvls;
int cnt[3];
void precalc(int u, int p) {
    par[u] = p;
    if (p != -1) lvl[u] = lvl[p]+1;
    for (int v : g[u]) if (v != p) {
        precalc(v, u);
        sons[u] += c[v];
    }
    if (c[u]) {
        lvls.insert({ lvl[u], u });
        cnt[min(2, sons[u])]++;
    }
}

void solve() {
    cin >> n >> q; 
    c.resize(n);
    lvl.assign(n, 0);
    sons.assign(n, 0);
    par.assign(n, -1);
    lvls.clear();
    memset(cnt, 0, sizeof cnt);
    g.assign(n, vi());
    B = 0;

    for (int i = 0; i < n; i++) cin >> c[i], B += c[i];
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    precalc(0, -1);
    
        // ps(B, cnt[0], cnt[1], cnt[2]);
    while (q--) {
        int u; cin >> u; u--;
        
        B -= c[u];
        cnt[min(2, sons[u])] -= c[u];
        if (par[u] != -1) {
            cnt[min(2, sons[par[u]])] -= c[par[u]];
            sons[par[u]] -= c[u];
            cnt[min(2, sons[par[u]])] += c[par[u]];
        }
        if (c[u]) lvls.erase(lvls.find({ lvl[u], u }));

        c[u] = 1-c[u];

        if (c[u]) lvls.insert({ lvl[u], u });
        if (par[u] != -1) {
            cnt[min(2, sons[par[u]])] -= c[par[u]];
            sons[par[u]] += c[u];
            cnt[min(2, sons[par[u]])] += c[par[u]];
        }
        cnt[min(2, sons[u])] += c[u];
        B += c[u];

        // ps(B, cnt[0], cnt[1], cnt[2]);
        if (B == 0) {
            cout << "NO\n";
            continue;
        }
        int highest = (*begin(lvls))[1];
        bool ok = false;
        ok |= cnt[0] == 1 && cnt[1] == B-1 && !cnt[2];
        ok |= cnt[0] == 2 && cnt[1] == B-3 && cnt[2] == 1 && sons[highest]==2;
        cout << (ok ? "YES" : "NO") << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
