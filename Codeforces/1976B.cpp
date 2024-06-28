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

int dist(int l, int r, int x) {
    if (l <= x && x <= r) return 0;
    if (x < l) return l-x;
    return x-r;
}

int n;
vi a, b;

void solve() {
    cin >> n; a.resize(n); b.resize(n+1);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n+1; i++) cin >> b[i];
    int mn = 1e9, cost = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > b[i]) swap(a[i], b[i]);
        ckmin(mn, dist(a[i], b[i], b[n]));
        cost += b[i]-a[i];
    }
    cout << cost+mn+1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
