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
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int n, k;
vi a;
// the number of cows used if we stop once benefit passes certain margin
int calc(double margin) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
        cnt += (sqrt(1+4*a[i]/margin)-1)/2;
    return cnt;
}

void solve() {
    cin >> n >> k; k -= n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    double lo = 0, hi = 1e12;
    for (int i = 0; i < 200; i++) {
        double m = (lo+hi)/2;
        calc(m) >= k ? lo = m : hi = m;
    }

    int tot = 0;
    double ans = 0;
    for (int i = 0; i < n; i++) {
        int x = (sqrt(1+4*a[i]/lo)-1)/2;
        tot += x;
        ans += 1.0*a[i]/(x+1);
    }

    cout << (int)round(ans - (k-tot)*lo) << '\n';
}

signed main() {
    if (fopen("tallbarn.in", "r")) {
        freopen("tallbarn.in", "r", stdin);
        freopen("tallbarn.out", "w", stdout);
    }
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
