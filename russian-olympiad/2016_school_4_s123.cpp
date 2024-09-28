// subtask 1-3

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
V<bool> vis;
vi match;
 
bool kuhn(int v) {
    if (vis[v]) return false;
    vis[v] = true;
    for (int to : g[v]) if (match[to] == -1 || kuhn(match[to])) {
        match[to] = v;
        return true;
    }
    return false;
}
 
void solve() {
    int w, h, s, q; cin >> w >> h >> s >> q;
    match.assign(w*h, -1);
    V<array<int, 2>> base(s);
    for (int i = 0; i < s; i++) {
        int x, y; cin >> x >> y; x--; y--;
        base[i] = {x, y};
    }
    auto dist = [&](int i, int x, int y) {
        return max(abs(x-base[i][0]), abs(y-base[i][1]));
    };

    int robot_cnt = 0;
    int t; cin >> t;
    for (int i = 0; i < t; i++) {
        int b, n, m; cin >> b >> n >> m; b--;
        g.resize(robot_cnt+n);
        for (int j = 0; j < n; j++) {
            for (int x = 0; x < w; x++) for (int y = 0; y < h; y++) if (dist(b, x, y) <= m) {
                g[robot_cnt].pb(w*y+x);
            }
            robot_cnt++;
        }

        int matches = 0;
        for (int j = robot_cnt-n; j < robot_cnt; j++) {
            vis.assign(robot_cnt, false);
            bool ret = kuhn(j);
            matches += ret;
        }
        if (matches < n) {
            cout << i << ' ' << matches << '\n';
            return;
        }
    }
    cout << t << ' ' << 0 << '\n';
}

void setIn(string s)  { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (s.size() && fopen((s+".in").c_str(), "r")) setIn(s+".in"), setOut(s+".out");
}
 
signed main() {
    setIO("mining");
    solve();
    return 0;
}

