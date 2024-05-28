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
    return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

int n, d=inf, s0, s1;
V<pair<pt, int>> v;
void relax(const pair<pt, int>& a, const pair<pt, int>& b) {
    if (ckmin(d, dist(a.f, b.f))) s0 = a.s, s1 = b.s;
}
bool cmp_y(const pair<pt, int>& a, const pair<pt, int>& b) {
    return a.f.y < b.f.y || (a.f.y == b.f.y && a.f.x < a.f.x);
}

void dnc(int l, int r) {
    if (l == r-1) return;
    int m = (l+r)/2;
    int mid_x = v[m].f.x;
    dnc(l, m); dnc(m, r);

    V<pair<pt, int>> aux;
    merge(v.begin()+l, v.begin()+m, v.begin()+m, v.begin()+r,
            back_inserter(aux), cmp_y);
    copy(all(aux), v.begin()+l);

    int aux_sz = 0;
    for (int i = l; i < r; i++) {
        for (int j = aux_sz-1; j >= 0 && v[i].f.y-aux[j].f.y < d; j--) {
            relax(v[i], aux[j]);
        }
        aux[aux_sz++] = v[i];
    }
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
