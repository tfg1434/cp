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

using pt = complex<int>;
#define x real()
#define y imag()
template<class T> istream& operator>>(istream& in, complex<T>& o) {
    T X, Y; in >> X >> Y; o.real(X); o.imag(Y); return in;
}
template<class T> bool operator<(const complex<T>& a, const complex<T>& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
const pt zero = {0, 0};

void solve() {
    int n; cin >> n;    
    V<pt> a(n);
    pt c;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
        c += a[i];
    }
    c *= 2;
    for (int i = 0; i < n; i++) {
        a[i] *= 2*n;
        if (a[i] == c) {
            cout << "No\n";
            return;
        }
        a[i] -= c;
    }

    int mx = 0;
    map<array<int, 2>, int> cnt;
    auto add_dir = [&](pt dir) {
        if (dir.y < 0 || (dir.y == 0 && dir.x < 0)) dir *= -1;
        dir /= gcd(dir.x, dir.y);
        cnt[{dir.x, dir.y}]++;
        ckmax(mx, cnt[{dir.x, dir.y}]);
    };

    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) {
        auto dir = (a[i]+a[j])/2LL;
        if (dir == zero) {
            dir = {-(a[i]-a[j]).y, (a[i]-a[j]).x};
        } else {
            if ((conj(zero - dir)*(a[i] - dir)).x) continue;
        }
        add_dir(dir);
    }

    if (mx == n/2) {
        cout << "Yes\n";
        return;
    }
    cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
