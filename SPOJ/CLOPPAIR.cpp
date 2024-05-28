// find the closest two points on the plane!
// AC

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
template<class T> T dist(const complex<T>& a, const complex<T>& b) {
    return norm(a-b);
}
int n, d=inf, s0, s1;
V<pair<pt, int>> v;

void dnc(int l, int r) {
    if (l == r-1) return;
    int m = (l+r)/2;
    int mid_x = v[m].f.x;
    dnc(l, m); dnc(m, r);

    V<pair<pt, int>> tmp;
    vi lef, rig;
    int a = l, b = m;
    auto ck_lef = [&]() {
        if (mid_x-v[a].f.x < d) lef.pb(a);
        tmp.pb(v[a++]);
    };
    auto ck_rig = [&]() {
        if (v[b].f.x-mid_x < d) rig.pb(b);
        tmp.pb(v[b++]);
    };
    auto relax = [&](int i, int j) {
        if (ckmin(d, dist(v[i].f, v[j].f))) s0 = v[i].s, s1 = v[j].s;
    };
    while (a < m && b < r) {
        if (v[a].f.y < v[b].f.y) ck_lef();
        else ck_rig();
    }
    while (a < m) ck_lef();
    while (b < r) ck_rig();

    for (int j = m, i = l; i < m; i++) {
        while (j < r && v[j].f.y < v[i].f.y) j++;
        if (j < r) relax(i, j);
        if (j+1 < r) relax(i, j+1);
    }
    for (int j = l, i = m; i < r; i++) {
        while (j < m && v[j].f.y < v[i].f.y) j++;
        if (j < m) relax(i, j);
        if (j+1 < m) relax(i, j+1);
    }

    for (int i = l; i < r; i++) v[i] = tmp[i-l];
}

void solve() {
    cin >> n;        
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i].f, v[i].s = i;
    sort(all(v), [&](const pair<pt, int>& a, const pair<pt, int>& b) {return a.f < b.f;});
    dnc(0, n);

    if (s0 > s1) swap(s0, s1);
    cout << s0 << ' ' << s1 << ' ' << fixed << setprecision(6) << sqrtl(1.L*d) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
