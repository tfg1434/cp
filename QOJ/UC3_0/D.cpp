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

void solve() {
    int n, m; cin >> n >> m;    
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vi b(m); for (int i = 0; i < m; i++) cin >> b[i];
    auto fi = find(all(a), b[0]) - begin(a);
    bool ans = false;
    for (int i = 0; i < m; i++) {
        if (a[(fi+i)%n] != b[i]) break;
        if (i == m-1) ans = true;
    }
    for (int i = 0; i < m; i++) {
        if (a[(fi-i+n)%n] != b[i]) break;
        if (i == m-1) ans = true;
    }

    cout << (ans ? 1 : 0) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
