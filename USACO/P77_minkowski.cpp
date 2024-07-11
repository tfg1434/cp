#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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
int half(pt a) { return a.x < 0 || (!a.x && a.y < 0); }

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
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }

V<pt> convex_hull(V<pt> pts) {
    nth_element(pts.begin(), pts.begin(), pts.end(), [&](const pt& a, const pt& b) { return a < b; });
    auto leftmost = pts[0];
    for (pt& p : pts) p -= leftmost;
    sort(all(pts), [&](const pt& a, const pt& b) { 
        if (cross(a, b)) return cross(a, b) > 0;
        return norm(a) < norm(b);
    }); 
    V<pt> hull;
    for (pt p : pts) {
        while (hull.size() > 1 && (cross(end(hull)[-2], end(hull)[-1], p)) <= 0) {
            hull.pop_back();
        }
        hull.pb(p);
    }
    for (pt& p : hull) p += leftmost;
    return hull;
}

void solve() {
    int n; cin >> n;

    pt start;
    V<pt> all_sides;
    for (int i = 0; i < n; i++) {
        int g; cin >> g;        
        V<pt> pts(g);
        for (int j = 0; j < g; j++) cin >> pts[j];
        pts = convex_hull(pts);
        g = pts.size();
        start += pts[0];
        V<pt> pg(g);
        for (int j = 1; j <= g; j++) {
            pg[j-1] = pts[j%g] - pts[j-1];
        }
        all_sides.insert(all_sides.end(), all(pg));
    }

    sort(all(all_sides), [&](pt a, pt b) {
        if (half(a) != half(b)) return half(a) < half(b);
        return cross(a, b) > 0;
    });

    int ans = 0;
    for (pt side : all_sides) {
        start += side;
        ckmax(ans, norm(start));
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
