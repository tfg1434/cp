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
    int n, m; cin >> n >> m;    
    vi a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    vi pre(m+1);
    int cur = 0;
    for (int i = 0; i < n; i++) {
        pre[cur] += a[i];
        pre[min(cur+b[i], m)] -= a[i];
        if (cur+b[i] > m) {
            pre[0] += a[i];
            pre[cur+b[i]-m] -= a[i];
        }
        (cur += b[i]) %= m;
    }
    for (int i = 0; i < m; i++) {
        pre[i+1] += pre[i];
        cout << pre[i] << " \n"[i==m-1];
    }
}


signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
