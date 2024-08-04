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

void solve() {
    int n; cin >> n;
    vi x(n), y(n);
    for (int i = 0; i < n; i++) cin >> x[i];
    for (int i = 0; i < n; i++) cin >> y[i];
    vi inds(n); iota(all(inds), 0);
    sort(all(inds), [&](int i, int j) {
        bool cat_a = !(x[i] < y[i]);
        bool cat_b = !(x[j] < y[j]);
        if (cat_a != cat_b) return cat_a < cat_b;
        if (!cat_a) return x[i] < x[j];
        return y[i] > y[j];
    });

    int ans = 0, buf = 0;
    for (int i : inds) {
        int saved = min(buf, x[i]);
        buf -= saved;
        ans += x[i]+y[i]-saved;
        buf += y[i];
    }

    cout << ans << '\n';
    for (int i = 0; i < n; i++) {
        cout << inds[i]+1 << " \n"[i==n-1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

