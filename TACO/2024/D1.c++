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
    int min_x = MAX, max_x = -MAX, min_y = MAX, max_y = -MAX;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        int X = x+y, Y = x-y;
        ckmin(min_x, X); ckmax(max_x, X);
        ckmin(min_y, Y); ckmax(max_y, Y);
        a[i] = {X, Y};
    }

    int lo = -1, hi = min(max_x - min_x, max_y - min_y);
    while (hi-lo > 1) {
        int k = (lo+hi)/2;
        bool found = false;
        for (int left : {min_x, max_x-k}) {
            for (int top : {min_y, max_y-k}) {
                int MIN_X = MAX, MAX_X = -MAX, MIN_Y = MAX, MAX_Y = -MAX;
                V<bool> del(n);
                for (int i = 0; i < n; i++) {
                    auto [x, y] = a[i];
                    del[i] = left <= x && x <= left+k && top <= y && y <= top+k;
                    if (!del[i]) {
                        ckmin(MIN_X, x); ckmax(MAX_X, x);
                        ckmin(MIN_Y, y); ckmax(MAX_Y, y);
                    }
                }

                for (int LEFT : {MIN_X, MAX_X-k}) {
                    for (int TOP : {MIN_Y, MAX_Y-k}) {
                        auto DEL = del;
                        int cur_min_x = MAX, cur_max_x = -MAX, cur_min_y = MAX, cur_max_y = -MAX;
                        for (int j = 0; j < n; j++) if (!del[j]) {
                            auto [x, y] = a[j];
                            del[j] = LEFT <= x && x <= LEFT+k && TOP <= y && y <= TOP+k;
                            if (!del[j]) {
                                ckmin(cur_min_x, x); ckmax(cur_max_x, x);
                                ckmin(cur_min_y, y); ckmax(cur_max_y, y);
                            }
                        }
                        found |= cur_max_x - cur_min_x <= k && cur_max_y - cur_min_y <= k;
                        del = DEL;
                    }
                }
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
