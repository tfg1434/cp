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

void solve() {
    int x0, y0, x1, y1; cin >> x0 >> y0 >> x1 >> y1;
    if (x0 > x1) swap(x0, x1);
    if (y0 > y1) swap(y0, y1);
    int a = x1-x0, b = y1-y0;
    if (a > b) swap(a, b);
    int x = a, y = b-a;

    int ans;
    if (x <= y) ans = x + (y-x+1)/2;
    else ans = y+(2*(x-y)+2)/3;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
