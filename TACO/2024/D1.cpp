// WA
// I claim two squares have to be at the corners of the min-area rectangle... ig it's wrong
// Right, only one square has to be

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

const int MAX = 2e9;

void solve() {
    int n; cin >> n;
    V<array<int, 2>> a(n);
    int min_x = MAX, max_x = -MAX;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        int X = x+y, Y = x-y;
        ckmin(min_x, X); ckmax(max_x, X);
        a[i] = {X, Y};
    }

    int lo = -1, hi = 2e9;
    while (hi-lo > 1) {
        int k = (lo+hi)/2;
        vi min_y(2, MAX), max_y(2, -MAX);
        for (int i = 0; i < n; i++) { 
            auto [x, y] = a[i];
            if (x - min_x <= k) {
                ckmin(min_y[0], y);
                ckmax(max_y[0], y);
            }
            if (max_x - x <= k) {
                ckmin(min_y[1], y);
                ckmax(max_y[1], y);
            }
        }

        bool found = false;
        for (int top_l : {min_y[0], max_y[0]-k}) {
            for (int top_r : {min_y[1], max_y[1]-k}) {
                int cur_min_x = MAX, cur_max_x = -MAX, cur_min_y = MAX, cur_max_y = -MAX;
                for (int i = 0; i < n; i++) {
                    auto [x, y] = a[i];
                    if (x <= min_x+k && top_l <= y && y <= top_l+k) continue;
                    if (x >= max_x-k && top_r <= y && y <= top_r+k) continue;
                    ckmin(cur_min_x, x); ckmax(cur_max_x, x);
                    ckmin(cur_min_y, y); ckmax(cur_max_y, y);
                }

                found |= cur_max_x - cur_min_x <= k && cur_max_y - cur_min_y <= k;
            }
        }
        found ? hi = k : lo = k;
    }

    cout << hi << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
