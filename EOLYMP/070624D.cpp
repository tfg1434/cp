#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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

#define pct __builtin_popcountll
constexpr int p2(int x) { return (int)1 << x; }
constexpr int msk2(int x) { return p2(x)-1; }
const int LOG = 50;

void solve() {
    int n, q; cin >> n >> q;
    int cur_l = 1, cur_r = 1;
    V<array<int, 2>> layers;
    layers.pb({cur_l, cur_r});
    auto hm_have_bit = [](int i, int n) -> int{ 
        if (n < p2(i)) return 0;
        int f = (n/p2(i) + 1) / 2;
        int cnt = 0;
        cnt += (f-1)*p2(i) + min(p2(i), n-(2*f-1)*p2(i)+1);
        return cnt;
    };
    while (cur_r < n) {
        int cnt = 0;
        for (int i = 0; i < LOG; i++) {
            cnt += hm_have_bit(i, cur_r) - hm_have_bit(i, cur_l-1);
        }
        cur_l = cur_r+1;
        cur_r += cnt;
        layers.pb({cur_l, cur_r});
    }

    auto par = [&](int v) -> int {
        if (v == 1) return 0;
        if (v == 2) return 1;
        int dep = upb(layers, {v, inf})-1;
        int cnt_from_l = v - layers[dep-1][1];
        int lo = layers[dep-1][0]-1, hi = layers[dep-1][1];
        while (hi-lo > 1) {
            int mi = (lo+hi)/2;
            int bits_on_pre = 0;
            for (int i = 0; i < LOG; i++) {
                bits_on_pre += hm_have_bit(i, mi) - hm_have_bit(i, layers[dep-2][1]);
            }
            bits_on_pre >= cnt_from_l ? hi = mi : lo = mi;
        }
        return hi;
    };

    while (q--) {
        int u, v; cin >> u >> v;
        int steps = 0;
        while (u != v) {
            steps++;
            if (u > v) swap(u, v);
            v = par(v);
        }
        cout << steps << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
