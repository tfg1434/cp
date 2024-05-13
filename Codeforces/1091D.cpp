// TLE

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const double eps = 1e-9;

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

int n, S;
V<pair<pt, int>> P;
V<tuple<pt, int, int>> segments;

pt center;
bool cmp(pt a, pt b) {
    bool ctg_a = a < center;
    bool ctg_b = b < center;
    if (ctg_a != ctg_b) return ctg_a < ctg_b;
    int cross = (conj(a)*b).y;
    if (cross == 0) return norm(a) < norm(b);
    return cross > 0;
}

void solve() {
    cin >> n >> S;
    P.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> P[i].f; P[i].s = i;
    }

    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j)
        segments.pb({P[j].f-P[i].f, i, j});
    sort(all(segments), [&](tuple<pt, int, int> a, tuple<pt, int, int> b) {
        return cmp(get<0>(a), get<0>(b));
    });

    pt perp(-get<0>(segments[0]).y, get<0>(segments[0]).x);
    sort(all(P), [&](pair<pt, int> a, pair<pt, int> b) {
        return (conj(a.f)*perp).x < (conj(b.f)*perp).x;
    });
    vi where(n); for (int i = 0; i < n; i++) where[P[i].s] = i;

    for (int i = 0; i < segments.size(); i++) {
        auto [vec, pi, pj] = segments[i]; perp = pt(-vec.y, vec.x);

        double len = sqrt(1.0*vec.x*vec.x+vec.y*vec.y);
        double perp_len = sqrt(1.0*perp.x*perp.x+perp.y*perp.y);
        auto eval = [&](const pt& a) { // area is lt, eq, or gt. a is the vector from pi to the pt
            double lhs = len*(conj(a)*perp).x/perp_len;
            double rhs = 2*S;
            if (abs(lhs-rhs) < eps) return 0;
            if (lhs < rhs) return -1;
            return 1;
        };
        int lo = 0, hi = n;
        while (lo < hi) {
            int ind = (lo+hi)/2;
            (eval(P[ind].f-P[where[pi]].f) == -1) ? lo=ind+1 : hi = ind;
        }

        if (hi == n || eval(P[hi].f-P[where[pi]].f) != 0) {
            swap(P[where[pi]], P[where[pj]]);
            swap(where[pi], where[pj]);
            continue;
        }

        cout << "Yes\n";
        cout << P[where[pi]].f.x << ' ' << P[where[pi]].f.y << '\n';
        cout << P[where[pj]].f.x << ' ' << P[where[pj]].f.y << '\n';
        cout << P[hi].f.x << ' ' << P[hi].f.y << '\n';
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
