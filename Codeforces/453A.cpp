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

double pw(int a, int b) {
    double res = 1;
    while (b > 0) {
        if (b % 2) res *= a;
        b /= 2;
        a *= a;
    }
    return res;
}

void solve() {
    int m, n; cin >> m >> n;
    double res = 0;
    for (int i = 0; i < m; i++) {
        res -= pw(i, n);
    }
    res += pw(m, n+1);
    res /= pw(m, n);
    cout << fixed << setprecision(4) << res << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
