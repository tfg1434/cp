#include <bits/stdc++.h>
#include "aliens.h"
using namespace std;
#define int long long
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
    if (a.x == b.x) return a.y > b.y;
    return a.x < b.x;
}
template<class T> T sqr(const T& a) { return a*a; }
int cdiv(int a, int b) {return a/b + ((a^b)>0&&a%b);}

int n, m, k;
V<pt> inp, pts;

// void solve() {
    // cin >> n >> m >> k;
#undef int
long long take_photos(int N, int M, int K, vector<int> XS, vector<int> YS) {
#define int long long
    n = N; m = M; k = K;
    inp.resize(n);
    for (int i = 0; i < n; i++) {
        // cin >> inp[i]; 
        inp[i] = {XS[i], YS[i]};
        if (inp[i].x > inp[i].y) inp[i] = {inp[i].y, inp[i].x};
    }
    inp.pb({-1, -1}); n++;
    sort(all(inp), [&](const pt& a, const pt& b) {return a < b;});

    int max_y = -2;
    for (int i = 0; i < n; i++) {
        if (!ckmax(max_y, inp[i].y)) continue;
        pts.pb(inp[i]);
    }
    n = pts.size();
    k = min(n-1, k);

    vi l(n), r(n);
    for (int i = 0; i < n; i++) l[i] = pts[i].x, r[i] = pts[i].y+1;
    vi dp(n, inf);
    dp[0] = 0;
    for (int p = 0; p < k; p++) {
        vi a(n-1), b(n-1);
        for (int i = 0; i < n-1; i++) {
            int cpp = r[i]-l[i+1];
            if (cpp < 0) cpp = 0;
            a[i] = dp[i] + sqr(l[i+1]) - cpp;
            b[i] = 2*l[i+1];
        }
        V<pt> ch = { {0, p} };
        vi new_dp(n, inf);
        int cur_entry = 0;
        for (int i = p+1; i < n; i++) {
            while (cur_entry+1 < ch.size() && ch[cur_entry+1].x <= r[i]) {
                cur_entry++;
            }
            int j = ch[cur_entry].y;
            new_dp[i] = sqr(r[i]) + a[j] - b[j]*r[i];
            if (i == n-1 || p == 0) {
                continue;
            }
            while (!ch.empty()) {
                int j = ch.back().y;
                int X = ch.back().x;
                if (a[i]-b[i]*X <= a[j]-b[j]*X) {
                    ch.pop_back();
                } else {
                    break;
                }
            }
            if (ch.empty()) {
                ch.pb({0ll, i});
            } else {
                int j = ch.back().y;
                int X = cdiv(a[i]-a[j], b[i]-b[j]);
                ch.pb({X, i});
            }
            if (cur_entry >= ch.size()) {
                cur_entry = ch.size()-1;
            }
        }
        dp = new_dp;
    }
    // cout << dp.back() << '\n';
    return dp.back();
}

// signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    // solve();
    // return 0;
// }

