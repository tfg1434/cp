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

// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define pct __builtin_popcount
constexpr int p2(int x) { return (int)1 << x; }
constexpr int msk2(int x) { return p2(x)-1; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 

void solve() {
    int n, m; cin >> n >> m; 
    V<V<bool>> wall(n, V<bool>(n));
    for (int i = 0; i < m; i++) {
        int x, y; cin >> x >> y; x--; y--;
        wall[x][y] = true;
    }

    V<V<array<int, 2>>> sqr(4);
    for (int dx : {-2, -1, 1, 2}) for (int dy : {-2, -1, 1, 2}) if (abs(dx)+abs(dy) == 3){
        int x = n/2+dx;
        int y = n/2+dy;
        if (0 <= x && x < n && 0 <= y && y < n && !wall[x][y]) {
            sqr[0].pb({x, y});
        }
    }

    for (int d : {-1, 1}) {
        for (int i = 1; i <= n/2; i++) {
            int x = n/2+i*d;
            int y = n/2;
            if (wall[x][y]) break;
            sqr[3].pb({x, y});
        }
    }
    for (int d : {-1, 1}) {
        for (int i = 1; i <= n/2; i++) {
            int x = n/2;
            int y = n/2+i*d;
            if (wall[x][y]) break;
            sqr[3].pb({x, y});
        }
    }

    for (int d : {-1, 1}) {
        for (int i = 1; i <= n/2; i++) {
            int x = n/2+i*d;
            int y = n/2+i*d;
            if (wall[x][y]) break;
            sqr[2].pb({x, y});
        }
    }
    for (int d : {-1, 1}) {
        for (int i = 1; i <= n/2; i++) {
            int x = n/2+i*d;
            int y = n/2-i*d;
            if (wall[x][y]) break;
            sqr[2].pb({x, y});
        }
    }

    for (int dx : {-1, 0, 1}) for (int dy : {-1, 0, 1}) if (abs(dx)+abs(dy) > 0) {
        int x = n/2+dx, y = n/2+dy;
        if (0 <= x && x < n && 0 <= y && y < n && !wall[x][y]) sqr[1].pb({ x, y });
    }

    int ans = 0;
    for (int i = 0; i < 4; i++) {
        sort(all(sqr[i]));
    }
    for (int a = 0; a < p2(4); a++) if (pct(a) == 2) {
        vi bits;
        for (int j = 0; j < 4; j++) if (a & p2(j)) bits.pb(j);
        V<array<int, 2>> res;
        set_union(all(sqr[bits[0]]), all(sqr[bits[1]]), back_inserter(res));
        ckmax(ans, (int)res.size());
    }
    cout << ans+1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
