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

const int LOG = 59;
constexpr int p2(int x) { return (int)1 << x; }

void solve() {
    int a, b, g; cin >> a >> b >> g;
    if (a < b) {
        cout << 0 << '\n';
        if (g == 1) cout << -1 << '\n';
        return;
    }
    bool ok = true;
    int single_bits = 0;
    int dist = 0;
    int target = a-b;
    for (int bit = LOG; bit >= 0; bit--) {
        if (target & p2(bit)) {
            if (!(b & p2(bit))) ok = false;
        } else if (b & p2(bit)) {
            if (!single_bits) dist += p2(bit);
            else dist -= p2(bit);
            single_bits++;
        }
    }
    if (!ok) {
        cout << 0 << '\n';
        if (g == 1) cout << -1 << '\n';
    } else {
        cout << p2(single_bits) << '\n';
        if (g == 1) cout << dist << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
