// (implementation details)
// my long(ish) code w/o the doubling trick gets WA on one test (a large one with most queries wrong)
// untested since written on plane 

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

using pt = array<int, 2>;

int cross(array<int, 2> a, array<int, 2> b) {
    return b[1]*a[0] - a[1]*b[0];
}
bool operator<(array<int, 2> a, array<int, 2> b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] < b[0];
}
array<int, 2> operator -(const array<int, 2>& a, const array<int, 2>& b) {
    return {a[0]-b[0], a[1]-b[1]};
}


void solve() {
    int n; cin >> n;
    V<pt> pts(n);
    for (int i = 0; i < n; i++) {
        cin >> pts[i][0] >> pts[i][1];
    }

    auto bw_and_below = [&](int i, int j, int k) {
        if (pts[i][0] > pts[j][0]) swap(i, j);
        return pts[i][0] < pts[k][0] && pts[k][0] < pts[j][0] && cross(pts[k]-pts[i], pts[j]-pts[i]) > 0;
    };
    auto below = [&](int i, int j) {
        return pts[i][0] == pts[j][0] && pts[i][1] < pts[j][1];
    };

    V<vi> under(n, vi(n+1));
    for (int i = 0; i < n; i++) {
        // unexpected bug -- starting j from i+1
        // i mixed up def of under[i][j] -- forgot it's not about unordered pairs
        for (int j = 0; j < n; j++) if (pts[i][0] < pts[j][0]) { 
            for (int k = 0; k < n; k++) if (k != i && k != j) {
                under[i][j] += 2*bw_and_below(i, j, k) + below(i, k) + below(j, k);
            }
            under[j][i] = -under[i][j];
            ps(under[i][j]);
        }
    }

    vi ans(n-2);
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                int sum = abs(under[i][j]+under[j][k]+under[k][i])/2;
                sum -= bw_and_below(i, j, k) || bw_and_below(j, k, i) || bw_and_below(k, i, j);

                    // sum = under[tri[0].s][tri[2].s];
                    // sum -= under[tri[0].s][tri[1].s];
                    // sum -= under[tri[1].s][tri[2].s];
                    // sum += under[tri[1].s][n];

                // int sum;
                // if (tri[0].f[0] == tri[1].f[0] || tri[1].f[0] == tri[2].f[0] || tri[2].f[0] == tri[0].f[0]) {
                    // vi under_vals = {under[tri[0].s][tri[1].s], under[tri[1].s][tri[2].s], under[tri[0].s][tri[2].s]};
                    // sort(all(under_vals));
                    // sum = under_vals[2]-under_vals[1]-1;
                // } else {
                    // sum = under[tri[0].s][tri[2].s];
                    // sum -= under[tri[0].s][tri[1].s];
                    // sum -= under[tri[1].s][tri[2].s];
                    // sum += under[tri[1].s][n];

                    // if (sum > 0) {
                        // // correct for counting the bottom point of the triangle
                        // sum--;
                    // } else {
                        // sum = -sum;
                    // }
                // }

                // ps(sum);
                ans[sum]++;
            }
        }
    }

    for (int i = 0; i < n-2; i++) cout << ans[i] << '\n';
}

void setIn(string s)  { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (s.size() && fopen((s+".in").c_str(), "r")) setIn(s+".in"), setOut(s+".out");
}

signed main() {
    setIO("triangles");
    solve();
    return 0;
}
