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
    vi a(n), min_r(n+1, n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int k = 1; k <= n; k++) {
        if (k*(k+1)/2 > n) break;
        int K = k;
        map<int, int> f;
        for (int i = 0; i < n; i++) {
            f[a[i]]++;
            if (f.size() == K) {
                if (--K == 0) {
                    min_r[k] = i;
                    break;
                }
                f.clear();
            }
        }
    }

    int k = 1;
    for (int i = 0; i < n; i++) {
        while (k+1 <= n && min_r[k+1] <= i) k++;
        cout << k << " \n"[i==n-1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
