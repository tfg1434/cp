// why is https://qoj.ac/submission/477132 wrong?

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

int area(int a, int b, int c) {
    int s = (a+b+c)/2;
    return s*(s-a)*(s-b)*(s-c);
}

void solve() {
    int n; cin >> n;
    vi a(n);
    for (auto& x : a) cin >> x;
    sort(all(a));
    int ans = -1;
    for (int i = 0; i+2 < n; i++) if (a[i]+a[i+1] > a[i+2]) {
        ckmax(ans, area(a[i], a[i+1], a[i+2]));
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
