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

int ext_gcd(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int d = ext_gcd(b, a%b, x1, y1);
    x = y1;
    y = x1 - y1*(a/b);
    return d;
}

void solve() {
    // ps(gcd(0, 0)); 0
    // ps(5%0); error
    // ps(0%0); error
    // return;
    int p, q, x, y; cin >> p >> q >> x >> y; 
    p = abs(p); q = abs(q); x = abs(x); y = abs(y);
    if (!p && !q) {
        cout << (!x && !y ? "YES" : "NO") << '\n';
        return;
    }

    int g = gcd(p, q);
    if (!(x%g) && !(y%g)) {
        x /= g; y /= g; p /= g; q /= g;

        int a, b;
        ext_gcd(p, q, a, b);
        a *= x; b *= x;
        int c, d;
        ext_gcd(p, q, c, d);
        c *= y; d *= y;
        if (!((a+b+c+d)%2) || q%2 != p%2) {
            cout << "YES\n";
            return;
        }
    }

    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
