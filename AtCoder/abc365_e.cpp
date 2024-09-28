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

const int LOG = 27;
constexpr int p2(int x) { return (int)1 << x; }

void solve() {
    int n; cin >> n;
    vi a(n); for (int& i : a) cin >> i;

    int ans = 0;
    for (int b = 0; b < LOG; b++) {
        V<array<int, 2>> segs[2];
        int sum[2]; sum[0] = sum[1] = 0;
        int side = 0;
        bool has_bit = false;
        for (int i = 0; i < n; i++) if (a[i] & p2(b)) {
            has_bit = true;
            if (!segs[1-side].size()) {
                segs[side].pb({0, i+1});
            } else {
                segs[side].pb({ segs[1-side].back()[1], i+1 });
            }
            sum[side] += segs[side].back()[1]-segs[side].back()[0];
            side ^= 1;
        }
        if (!has_bit) continue;
        segs[side].pb({ segs[1-side].back()[1], n+1 });
        sum[side] += segs[side].back()[1]-segs[side].back()[0];
        ans += sum[0]*sum[1]*p2(b);
    }
    for (int i = 0; i < n; i++) ans -= a[i];

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
