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
const int max_n = 150;
pt v[max_n];
int n, ans;

pt center;
bool cmp(pt a, pt b) {
    bool ctg_a = a < center;
    bool ctg_b = b < center;
    if (ctg_a != ctg_b) return ctg_a < ctg_b;
    auto A = a-center, B = b-center;
    int cross = (conj(A)*B).y;
    if (cross) return cross > 0;
    return norm(a) < norm(b);
}
int cross(const pt& a, const pt& b) {
    return a.y*b.x - a.x*b.y;
    return (conj(a)*b).y;
}

void solve() {
    cin >> n; 
    for (int i = 0; i < n; i++) cin >> v[i];
    for (int p = 0; p < n; p++) {
        center = v[p];
        sort(begin(v), begin(v)+n, cmp);
        for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) for (int k = j+1; k < n; k++) for (int l = k+1; l < n; l++) {
            V<pt> pts = {v[i], v[j], v[k], v[l]};
            pts.pb(pts.front());
            bool ok = true;
            for (int z = 0; z < 4; z++) {
                ok &= cross(pts[z+1]-pts[z], v[p]-pts[z]) > 0;
            }
            ans += ok;
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
