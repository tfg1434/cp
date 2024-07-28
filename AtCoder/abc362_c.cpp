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
    int n; cin >> n;    
    int sum_gap = 0, sum_r = 0;
    V<array<int, 2>> a(n);
    for (int i = 0; i < n; i++) { 
        int l, r; cin >> l >> r;
        a[i] = {l, r};
        sum_gap += r-l;
        sum_r += r;
    }
    if (sum_r < 0 || sum_r-sum_gap > 0) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
    for (int i = 0; i < n; i++) {
        int x = a[i][1];
        int d = min(a[i][1]-a[i][0], sum_r);
        sum_r -= d;
        x -= d;
        cout << x << " \n"[i==n-1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
