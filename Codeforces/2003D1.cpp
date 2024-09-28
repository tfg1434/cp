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
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int len; cin >> len;
        vi a(len);
        for (int& x : a) cin >> x;
        sort(all(a));
        int mex0 = 0, mex1 = 0;
        bool skipped = false;
        for (int x : a) {
            if (mex0 == x) mex0++;
            if (mex1 == x) mex1++;
            if (x == mex1+1 && !skipped) {
                mex1 += 2;
                skipped = true;
            }
        }
        mex1 += !skipped;

        ckmax(mx, mex1);
    }

    if (m >= mx) {
        cout << mx*(mx+1) + (m-mx)*(m-mx+1)/2 + mx*(m-mx) << '\n';
    } else {
        cout << (m+1)*mx << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

