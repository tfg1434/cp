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

int terminal_case(int x, int y, int k) {
    return ((x-1+k)%(y-1)) + 1;
}

void solve() {
    int x, y, k; cin >> x >> y >> k;

    while (k > 0) {
        x++; k--;
        int nxt_mut_y = (x+y-1)/y*y;
        if (nxt_mut_y - x <= k) {
            k -= nxt_mut_y-x;
            x = nxt_mut_y;
            while (x % y == 0) x /= y;
            if (x == 1) {
                cout << terminal_case(x, y, k) << '\n';
                return;
            }
        } else {
            x += k;
            k = 0;
        }
    }

    cout << x << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
