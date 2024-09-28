#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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

vi cf(int p, int q) {
    vi a;
    while (q > 0) {
        a.pb(p/q);
        tie(p, q) = (q, p%q);
    }
    return a;
}

// a, b are inf- terminated
// a != b
// returns a < b
bool cmp(const vi& a, const vi& b) {
    int n = a.size(), m = b.size();
    for (int i = 0; i < min(n, m); i++) if (a[i] != b[i]) {
        if (i % 2 == 0) return a[i] < b[i];
        return a[i] > b[i];
    }
}

array<vi, 2> pm_eps(const vi& a) {
    // a = [] is inf, and so +- eps are the same
    if (!a.size()) return {a, a};
    auto p = a;
    p.pb(inf);
    auto q = a;
    q.back()--;
    q.pb(1);
    q.pb(inf);
    if (!cmp(p, q)) swap(p, q);
    return {p, q};
}

array<int, 2> convergents(const vi& a) {
    int p0 = 0, p1 = 1;
    int q0 = 1, q1 = 0;
    int n = a.size();
    for (int i = 0; i < n; i++) {
        int p = p1*a[i]+p0;
        int q = q1*a[i]+q0;
        tie(p1, p0) = (p, p1);
        tie(q1, q0) = (q, q1);
    }
    return { p1, q1 };
}

// p0/q0 != p1/q1
array<int, 2> middle(int p0, int q0, int p1, int q1) {
    auto a0 = pm_eps(p0, q0)[1];
    auto a1 = pm_eps(p1, q1)[0];
    vi a;
    int n = a0.size(), m = a1.size();
    for (int i = 0; i < min(n, m); i++) {
        a.pb(min(a0[i], a1[i]));
        if (a0[i] != a1[i]) break;
    }
    a.back()++;
    auto [p, q] = convergents(a);
    return {p, q};
}

bool cmp_rat(int p0, int q0, int p1, int q1) {
    return p0*q1 < p1*q0;
}

void solve() {
    int n; cin >> n;
    vi C(n), J(n);
    for (int i = 0; i < n; i++) cin >> C[i];
    for (int i = 0; i < n; i++) cin >> J[i];
    for (int i = 0; i+1 < n; i++) {
        int dx = C[i+1]-C[i], dy = J[i+1]-J[i];
        if (dx > 0) {
            if (dy >= 0) continue;
            if (dy < 0) {
                upd_max(R, {dx, -dy});
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
