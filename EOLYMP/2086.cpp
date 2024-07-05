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

V<vi> g;
vi match;
V<bool> vis;

bool kuhn(int v) {
    if (vis[v]) return false;
    vis[v] = true;
    for (int to : g[v]) {
        if (match[to] == -1 || kuhn(match[to])) {
            match[to] = v;
            match[v] = to;
            return true;
        }
    }
    return false;
}

void solve() {
    int n, m, a, b; cin >> n >> m >> a >> b; 
    auto in = [&](int x, int y) {
        return 0 <= x && x < n && 0 <= y && y < m;
    };
    V<string> s(n);
    int tot = 0;
    for (int i = 0; i < n; i++) cin >> s[i], tot += count(all(s[i]), '*');

    g.resize(n*m);
    match.resize(n*m, -1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (s[i][j] == '*') {
            for (int dx : {-1, 0, 1}) for (int dy : {-1, 0, 1}) if (abs(dx)+abs(dy) == 1) {
                int ni = i+dx, nj = j+dy;
                if (in(ni, nj) && s[ni][nj] == '*') {
                    g[i*m+j].pb(ni*m+nj);
                    g[ni*m+nj].pb(i*m+j);
                }
            }
        }
    }

    int cnt = 0;

    for (int v = 0; v < n*m; v++) if (match[v] == -1) {
        for (int to : g[v]) {
            if (match[to] == -1) {
                match[to] = v;
                match[v] = to;
                cnt++;
                break;
            }
        }
    }

    for (int i = 0; i < n*m; i++) if (match[i] == -1){
        vis.assign(n*m, false);
        cnt += kuhn(i);
    }
    int ans = min(cnt*a + (tot-2*cnt)*b, tot*b);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}


