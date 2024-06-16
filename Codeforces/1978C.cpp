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
    int n, k; cin >> n >> k;
    int i = 0, j = n;
    vi ans(n);
    while (i < j) {
        if (abs(i+1-j) + abs(j - (i+1)) <= k) {
            k -= abs(i+1-j) + abs(j-(i+1));
            ans[i] = j;
            ans[j-1] = i+1;
            i++;
            j--;
        } else {
            ans[j-1] = j;
            j--;
        }
    }

    if (k == 0) {
        cout << "YES\n";
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i==n-1];
        return;
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
