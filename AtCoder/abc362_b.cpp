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
template<class T> bool operator>(const complex<T>& a, const complex<T>& b) {
    if (a.x == b.x && a.y == b.y) return false;
    return (!(a < b));
}
bool cmp(const pt& a, const pt& b) {
    return a < b;
}
int cross(pt a, pt b) { return (conj(a)*b).y; }
int cross(pt a, pt b, pt c) { return cross(b-a, c-a); }
bool half(pt a) { return a.y > 0 || (!a.y && a.x > 0); }

void solve() {
    array<pt, 4> a;
    for (int i = 0; i < 3; i++) cin >> a[i];
    a[3] = a[0];
    array<pt, 4> sides;
    for (int i = 0; i < 3; i++) { 
        sides[i] = a[i+1]-a[i];
    }
    sides[3] = sides[0];
    for (int i = 0; i < 3; i++) {
        if ((conj(sides[i])*sides[i+1]).x == 0) {
            cout << "Yes\n";
            return;
        }
    }
    cout << "No\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
