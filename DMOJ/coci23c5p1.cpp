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

struct Piece {
    char b;
    int h, w, u, d;
};

void solve() {
    int n; cin >> n;
    V<Piece> pieces(n);
    for (int i = 0; i < n; i++){
        char b; cin >> b;
        int h, w; cin >> h >> w;
        int u, d; cin >> u >> d;
        pieces[i] = {b, h, w, u, d};
    }

    V<array<int, 4>> rects;
    V<char> colors;
    rects.pb({0, 0, -1, -1});
    int cx = 0, cy = 0;
    int mx = 0, my = 0;
    for (int i = 0; i < n; i++) {
        int ind; cin >> ind; ind--;
        auto [b, h, w, u, d] = pieces[ind];
        colors.pb(b);
        rects.back()[2] = h;
        rects.back()[3] = w;
        cx += h; cy += w;
        ckmax(mx, cx); ckmax(my, cy);

        if (i < n-1) {
            if (u == 0) cy -= w-(d-1);
            if (u == 1) cx -= d;
            rects.pb({cx, cy, -1, -1});
        }
    }

    V<string> sol(mx, string(my, '.'));
    for (int i = 0; i < n; i++) {
        auto [x, y, h, w] = rects[i];
        char c = colors[i];
        for (int j = x; j < x+h; j++) {
            for (int k = y; k < y+w; k++) {
                sol[j][k] = c;
            }
        }
    }
    cout << mx << ' ' << my << '\n';
    for (int i = mx-1; i >= 0; i--) cout << sol[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
