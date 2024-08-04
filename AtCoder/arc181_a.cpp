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
    for (int& i : a) cin >> i, i--;
    if (is_sorted(all(a))) {
        cout << 0 << '\n';
        return;
    }

    V<bool> seen(n+1);
    int mex = 0;
    for (int i = 0; i < n; i++) {
        seen[a[i]] = true;
        while (seen[mex]) mex++;
        if (mex == i+1 && i == a[i]) {
            cout << 1 << '\n';
            return;
        }
    }

    if (a[0] == n-1 && a[n-1] == 0) {
        cout << 3 << '\n';
        return;
    }
    cout << 2 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
