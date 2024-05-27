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
template<class T> bool operator<=(const complex<T>& a, const complex<T>& b) {
    if (a.x == b.x) return a.y <= b.y;
    return a.x < b.x;
}
bool on_seg(const pt& a, const pt& b, const pt& c) {
    if ((conj(b-a)*(c-a)).y) return false;
    return a <= c && c <= b || b <= c && c <= a;
}
int n, q, k;
V<pt> a;

void solve() {
    cin >> n >> q >> k;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    a.pb(a[0]);

    int ans = 0;
    for (int i = 0; i < q; i++) {
        pt p; cin >> p;
        int lo = 1, hi = n-1;
        if ((conj(a[lo]-a[0])*(p-a[0])).y < 0) continue;
        while (hi-lo > 1) {
            int mid = (lo+hi)/2;
            (conj(a[mid]-a[0])*(p-a[0])).y >= 0 ? lo = mid : hi = mid;
        }
        if ((conj(a[hi]-a[0])*(p-a[0])).y > 0) continue;

        ans += (conj(a[lo+1]-a[lo])*(p-a[lo])).y >= 0;
    }

    cout << (ans >= k ? "YES" : "NO") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
