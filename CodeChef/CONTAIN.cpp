// SLOW AND WRONG

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
int n, q;
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

void solve() {
    cin >> n >> q;
    V<pt> a(n); for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) {
        pt candle; cin >> candle;
        vb used(n);
        int layers = 0;
        while (true) {
            center = {inf, inf};
            for (int j = 0; j < n; j++) if (!used[j]) {
                if (a[j] < center) center = a[j];
            }
            if (center.x == inf) break;
            sort(all(a), cmp);
            vector<int> ch;
            for (int j = 0; j < n; j++) if (!used[j]) {
                while (ch.size() > 1 && (conj(a[ch.back()] - a[ch[ch.size()-2]])*(a[j]-a[ch.back()])).y <= 0) {
                    ch.pop_back();
                }
                ch.pb(j);
            }

            bool ok = true;
            for (int j = 0; j < ch.size(); j++) {
                used[ch[j]] = true;
                auto side = a[ch[(j+1)%ch.size()]]-a[ch[j]];
                if ((conj(side)*(candle-a[ch[j]])).y <= 0) {
                    ok = false;
                    break;
                }
            }

            if (!ok) break;
            layers++;
        }

        cout << layers << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
