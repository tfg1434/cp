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
    int n; cin >> n;    
    vi a(n);
    map<int, vi> where;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        where[a[i]].pb(i);
    }
    if (where.size() == 1) {
        cout << "NO\n";
        return;
    }
    string ans = string(n, 'R');
    int mx = 0;
    for (auto [u, v] : where) ckmax(mx, (int)v.size());
    for (auto [u, v] : where) if (v.size() == mx) {
        ans[v.back()] = 'B';
        break;
    }
    cout << "YES\n";
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
