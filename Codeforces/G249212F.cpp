// wait of course you can't do 2^41 iterations
//
// Branching F
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
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

bool vis[45][45];
int ans;

unordered_map<int, int> rhombus;
void precomp_rec(int msk, int i, int x, int y) {
    if (i == 5) {
        rhombus[msk]++;
        return;
    }
    for (int dx : {-1,0, 1}) for (int dy : {-1, 0, 1}) if (abs(dx)+abs(dy) == 1) {
        int nx = x+dx, ny = y+dy;
        if (!vis[nx][ny]) {
            vis[nx][ny] = true;
            precomp_rec(msk, i+1, x+dx, y+dy);
            vis[nx][ny] = false;
        }
    }
}


void rec(int i, int x, int y) {
    if (i == 16) {
        int msk = 0;
        int layer = 0;
        int i = 0, j = 0;
        while (layer < 9) {
            if (j >= min(2*layer+1, 2*(8-layer)+1)) {
                layer++;
                j = 0;
            }

            int dy = layer-4;
            int dx = j-layer;
            if (vis[22+dx][22+dy]) msk |= 1 << i;
            i++; j++;
        }
        ans += rhombus[msk];
        return;
    }

    for (int dx : {-1,0, 1}) for (int dy : {-1, 0, 1}) if (abs(dx)+abs(dy) == 1) {
        int nx = x+dx, ny = y+dy;
        if (!vis[nx][ny]) {
            vis[nx][ny] = true;
            rec(i+1, x+dx, y+dy);
            vis[nx][ny] = false;
        }
    }
}


void solve() {
    for (int msk = 0; msk < (1LL << 41); msk++) if (msk & (1LL << 20)){
        int layer = 0;
        int i = 0, j = 0;
        while (layer < 9) {
            if (j >= min(2*layer+1, 2*(8-layer)+1)) {
                layer++;
                j = 0;
            }
            if (msk & (1LL << i)) {
                int dy = layer-4;
                int dx = j-layer;
                vis[22+dx][22+dy] = true;
            }
            i++; j++;
        }

        precomp_rec(msk, 1, 22, 22);
        memset(vis, 0, sizeof vis);
    }
    ps(rhombus);

    vis[22][22] = true;
    rec(1, 22, 22);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
