// 3 tcs wrong?

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
bool half(pt a) { return a.y > 0 || (!a.y && a.x > 0); }

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

    pt final_vec;
    V<pt> best(n);
    V<tuple<pt, pt, int>> events;
    for (int i = 0; i < n; i++) {
        int g; cin >> g;        
        V<pt> pts(g);
        for (int j = 0; j < g; j++) cin >> pts[j];
        pts = convex_hull(pts);
        g = pts.size();

        best[i] = *max_element(all(pts), cmp);
        final_vec += best[i];

        for (int j = 0; j < g; j++) {
            pt prv = !j ? pts.back() : pts[j-1];
            events.pb({(pts[j]-prv)*pt{0, -1}, pts[j], i });
        }
    }

    int ans = norm(final_vec);
    sort(all(events), [](const tuple<pt, pt, int>& a, const tuple<pt, pt, int>& b) {
        pt A = get<0>(a), B = get<0>(b);
        if (half(A) != half(B)) return half(A) < half(B);
        return cross(A, B) > 0;
    });
    for (auto [key, p, group] : events) {
        final_vec -= best[group];
        best[group] = p;
        final_vec += best[group];
        ckmax(ans, norm(final_vec));
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

