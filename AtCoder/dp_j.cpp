#include <bits/stdc++.h>
using namespace std;

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

const int max_n = 300;
int n, c[4];

double memo[max_n+1][max_n+1][max_n+1];
double r(int i, int j, int k) {
    auto& v = memo[i][j][k];
    if (!i && !j && !k) return v = 0;
    if (v > 0.5) return v;

    if (i > 0) v += r(i-1, j, k) * i;
    if (j > 0) v += r(i+1, j-1, k) * j;
    if (k > 0) v += r(i, j+1, k-1) * k;
    v += n;
    v *= 1.0 / (i + j + k);
    return v;
}

void solve() {
    cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i], c[a[i]]++;
    cout << fixed << setprecision(9) << r(c[1], c[2], c[3]) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
