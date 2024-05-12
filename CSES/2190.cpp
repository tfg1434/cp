// Three cases
// Non-parallel
// Parallel and inf slope
// Parallel and finite slope

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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

const double eps = 1e-9;
using pt = complex<double>;
#define x real()
#define y imag()
template<class T> istream& operator>>(istream& in, complex<T>& o) {
    T X, Y; in >> X >> Y; o.real(X); o.imag(Y); return in;
}

pt intersect(pt a1, pt d1, pt a2, pt d2) {
    auto t = (conj(a2-a1)*d2).y / (conj(d1)*d2).y;
    return a1 + t*d1;
}

void solve() {
    pt a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a.x > b.x) swap(a, b);
    if (c.x > d.x) swap(c, d);
    if (a.x > c.x) swap(a, c), swap(b, d);

    if (abs((conj(b-a)*(d-c)).y) < eps) {
        if (abs(a.x-b.x) < eps) {
            if (a.y > b.y) swap(a, b);
            if (c.y > d.y) swap(c, d);
            if (a.y > c.y) swap(a, c), swap(b, d);
            bool flag = abs(a.x-c.x) < eps && (int)b.y >= (int)c.y;
            cout << (flag ? "YES" : "NO") << '\n';
            return;
        } 

        auto d = b-a; d /= d.x;
        if (abs((a-d*a.x).y - (c-d*c.x).y) < eps && (int)b.x >= (int)c.x) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }

    auto check = [&](double a, double b) {
        return b-a > eps || abs(b-a) < eps;
    };

    auto inter = intersect(a, b-a, c, d-c);
    if (check(a.x, inter.x) && check(inter.x, b.x))
    if (check(c.x, inter.x) && check(inter.x, d.x)) {
        if (a.y > b.y) swap(a, b);
        if (c.y > d.y) swap(c, d);
        if (check(a.y, inter.y) && check(inter.y, b.y))
        if (check(c.y, inter.y) && check(inter.y, d.y)) {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int ttt; cin >> ttt; while (ttt--) solve();
    return 0;
}
