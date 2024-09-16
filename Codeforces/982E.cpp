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
#define len(x) (int)((x).size())
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

int eea(int a, int b, int& x, int& y) {
    x = 1, y = 0;
    int x1 = 0, y1 = 1;
    int a1 = a, b1 = b;
    while (b1) {
        int q = a1/b1;
        tie(x, x1) = make_tuple(x1, x-q*x1);
        tie(y, y1) = make_tuple(y1, y-q*y1);
        tie(a1, b1) = make_tuple(b1, a1-q*b1);
    }
    return a1;
}
int crm(int a, int n, int b, int m) {
    int t0, t1;
    int d = eea(n, m, t0, t1);
    if ((a-b)%d) return -1;
    int mod = n*m/d;
    int x = t0*(b-a)/d % (m/d);
    x = ((a+x*n)%mod+mod)%mod;
    return x;
}

void solve() {
    int n, m, x, y, vx, vy; cin >> n >> m >> x >> y >> vx >> vy; 

    if ((!x || x == n) && !vx) {
        cout << x << ' ' << (vy == -1 ? 0 : m) << '\n';
        return;
    }
    if ((!y || y == m) && !vy) {
        cout << (vx == -1 ? 0 : n) << ' ' << y << '\n';
        return;
    }
    if (!vx || !vy) {
        cout << -1 << '\n';
        return;
    }

    int t = crm(-x/vx, n, -y/vy, m);
    assert(t);
    if (t == -1) {
        cout << "-1\n";
        return;
    }
    int x_side = abs(x+t*vx)/n % 2, y_side = abs(y+t*vy)/m % 2;
    cout << x_side*n << ' ' << y_side*m << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
