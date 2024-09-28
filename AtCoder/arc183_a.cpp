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
    int n, k; cin >> n >> k;
    vi ans;
    if (n % 2 == 0) {
        ans.pb(n/2-1);
        for (int j = n-1; j >= 0; j--) {
            for (int i = j==n/2-1; i < k; i++) ans.pb(j);
        }
    } else {
        for (int i = 0; i < k; i++) ans.pb(n/2);
        ans.pb(n/2-1);
        for (int j = n-1; j >= 0; j--) if (j != n/2) {
            for (int i = j==n/2-1; i < k; i++) ans.pb(j);
        }
    }

    for (int i = 0; i < n*k; i++) {
        cout << ans[i]+1 << " \n"[i==n*k-1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
