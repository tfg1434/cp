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

const int MAX_DIST = 2e8;

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); 
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));

    while (q--) {
        int b, k; cin >> b >> k; 
        int lo = -1, hi = MAX_DIST+1;
        while (hi-lo > 1) {
            int max_dist = (lo+hi)/2;
            int max_cnt = upb(a, b+max_dist) - (lwb(a, b-max_dist)-1) - 1;
            max_cnt < k ? lo = max_dist : hi = max_dist;
        }
        cout << hi << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
