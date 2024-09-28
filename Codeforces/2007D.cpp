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

V<vi> g;
string s;
int cnt[4];

void dfs(int u, int p) {
    bool leaf = true;
    for (int v : g[u]) if (v != p) {
        leaf = false;
        dfs(v, u);
    }
    
    if (leaf) {
        if (s[u] == '?') cnt[2]++;
        else cnt[s[u]-'0']++;
    } else if (u) {
        cnt[3] += s[u] == '?';
    }
}

void solve() {
    int n; cin >> n;     
    g.assign(n, vi());
    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < n-1; i++) {
        int u, v; cin >> u >> v; u--; v--;
        g[u].pb(v); g[v].pb(u);
    }
    cin >> s;
    dfs(0, -1);

    int ans = 0;
    if (s[0] == '?') {
        // ps(n, cnt_non_leaf_root, cnt[0], cnt[1], cnt[2]);
        if (cnt[0] == cnt[1] && cnt[3]%2) {
            ckmax(ans, cnt[0]+(cnt[2]+1)/2);
        } 
        ckmax(ans, max(cnt[0], cnt[1])+cnt[2]/2);

    } else {
        ans += cnt[1-(s[0]-'0')];
        ans += (cnt[2]+1)/2;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
