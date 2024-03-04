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

const ll N = 3e5+1;
ll a[N];
ll n;
vpl dp[N], pd[N];
vl g[N];

ll f(ll x, ll y) {
    if (x > y) swap(x, y);
    return x + (ll)sqrt(y);
}

// dp[u] is coming up, pd[u] is going down
// note that if this node only has one child, you can choose either
// to go up or go down
// note that these arrays only track paths that go down to the
// leaves, since paths will always be more valuable this way
//
// pd is weig
void calc_dp(ll u, ll p) {
    if (sz(g[u]) - (u != p) == 0) {
        dp[u].pb({a[u], -1});
        pd[u]
    } 
    for (auto v : g[u]) if (v != p) {
        calc_dp(v, u);
        dp[u].pb({ f(dp[v].bk, a[u]), v });
        pd[u].pb({ f(pd[v].bk, a[u]), v });
    }

    sort(all(dp[u]));
    sort(all(pd[u]));
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n-1; i++) {
        ll u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }

    calc_dp(0, 0);
    for (int i = 0; i < n; i++) {
        for (auto[x, y] : dp[i]) {

        }
    }
}

signed main() {
    ios::sync_with_stdio(0)->cin.tie(0);
    
    ll tc = 1;
    cin >> tc;
    while (tc--) solve();

    return 0;
}
