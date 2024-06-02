#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int mod = 998244353;

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

int pw(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b%2) res = res*a%mod;
        b /= 2;
        a = a*a%mod;
    }
    return res;
}
int inv(int a) { return pw(a, mod-2); }

const int max_n = 3e5;
int half = inv(2);
int p[max_n], cnt[max_n], dp[max_n][2], edges[max_n][2], n, k, a[max_n], ans;
V<array<int, 2>> g[max_n];

void dfs(int u, int p) {
    for (auto [i, v] : g[u]) if (v != p) {
        dfs(v, u);
        cnt[u] += cnt[v];
        (ans += cnt[v]*(k-cnt[v])%mod*(1+mod-dp[i][0]+mod-dp[i][1])) %= mod;
        int dir = edges[i][0] == u;
        (ans += (cnt[v]+1)*(k-cnt[v]-1)%mod*dp[i][1-dir]) %= mod;
        (ans += (cnt[v]-1)*(k-cnt[v]+1)%mod*dp[i][dir]) %= mod;
    }
}

void solve() {
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> a[i], a[i]--;
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb({i, v}); g[v].pb({i, u});
        edges[i][0] = u; edges[i][1] = v;
    }
    for (int i = 0; i < k; i++) {
        p[a[i]] = 1;
        cnt[a[i]] = 1;
    }

    for (int i = 0; i < n-1; i++) {
        auto [u, v] = edges[i];
        dp[i][0] = p[u]*(1+mod-p[v])%mod*half%mod;
        dp[i][1] = p[v]*(1+mod-p[u])%mod*half%mod;
        p[u] = (p[u]+dp[i][1]+mod-dp[i][0])%mod;
        p[v] = (p[v]+dp[i][0]+mod-dp[i][1])%mod;
    }
    dfs(0, -1);

    (ans *= inv(k*(k-1)/2 % mod)) %= mod;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
