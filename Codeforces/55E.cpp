#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 2e18;

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
bool point_in_pg(const V<pt>& a, pt p) {
    int lo = 1, hi = a.size()-1;
    if ((conj(a[lo]-a[0])*(p-a[0])).y < 0) return false;
    while (hi-lo > 1) {
        int mid = (lo+hi)/2;
        (conj(a[mid]-a[0])*(p-a[0])).y >= 0 ? lo = mid : hi = mid;
    }
    if ((conj(a[hi]-a[0])*(p-a[0])).y > 0) return false;
    return (conj(a[lo+1]-a[lo])*(p-a[lo])).y >= 0;    
}

int c3(int n) { return n*(n-1)*(n-2)/6; }
int gauss(int n) { return n*(n+1)/2; }

int n;
V<pt> a;

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(all(a));
    a.insert(end(a), all(a));

    int q; cin >> q;
    while (q--) {
        pt p; cin >> p;
        if (!point_in_pg(a, p)) {
            cout << "0\n";
            continue;
        }

        int ans = 0;
        int j = 1;
        for (int i = 0; i < n; i++) {
            while ((conj(p-a[i])*(a[j]-a[i])).y < 0) j++;
            int dist = gauss(n-(j-i)-1);
            ans += dist;
        }
        cout << c3(n) - ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
