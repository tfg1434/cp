#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using pl = pair<ll,ll>;
#define f first
#define s second

#define tcT template<class T
#define tcTU tcT, class U
tcT> using V = vector<T>; 
using vl = V<ll>;
using vpl = V<pl>;

#define sz(x) ll((x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define ins insert 
#define pb push_back
#define ft front()
#define bk back()

tcT> bool ckmin(T& a, const T& b) {
    return b < a ? a = b, 1 : 0; 
} 
tcT> bool ckmax(T& a, const T& b) {
    return a < b ? a = b, 1 : 0; 
} 

vl a;
ll n;
V<vpl> dp; // (value, vertex)
V<vl> g;

ll f(ll x, ll y) {
    if (x > y) swap(x, y);
    return y + (ll)sqrt(x); // i did min+sqrt(max) first bro
}

void calc_dp(ll u, ll p) {
    if (sz(g[u]) - (u != p) == 0) {
        dp[u].pb({a[u], -1});
        return;
    } 

    for (auto v : g[u]) if (v != p) {
        calc_dp(v, u);
        dp[u].pb({f(a[u], dp[v].bk.f), v});
    }

    sort(all(dp[u]));
}

ll ans = 0;

void reroot(ll u, ll p, ll super) {
    ckmax(ans, max( dp[u].bk.f, super));

    if (sz(g[u]) - (u != p) == 0) return;

    ll used = -1;
    ll best_child = 0, second_best_child = 0;
    best_child = dp[u].bk.f;
    used = dp[u].bk.s;
    if (sz(dp[u]) > 1) 
        second_best_child = dp[u][sz(dp[u])-2].f;

    for (auto v : g[u]) if (v != p) {
        ll use = v == used ? second_best_child : best_child;

        reroot(v, u, f(max(super, use), a[v]));
    }
}

void solve() {
    cin >> n;

    g = V<vl>(n);
    a = vl(n);
    dp = V<vpl>(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        ll u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }

    calc_dp(0, 0);
    reroot(0, 0, sz(dp[0]) > 1 ? dp[0][sz(dp[0])-2].f : 0ll);

    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll tc = 1;
    // cin >> tc;
    while (tc--) solve();

    return 0;
}
