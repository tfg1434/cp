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
    int n, l, r; cin >> n >> l >> r;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    bool cont = false;
    V<vi> b;
    for (int i = 0; i < n; i++) {
        if (a[i] > r) cont = false;
        else if (l <= a[i] && a[i] <= r) ans++, cont=false;
        else {
            if (!cont) b.pb({a[i]});
            else b.back().pb(a[i]);
            cont = true;
        }
    }

    for (auto vec : b) {
        int sum = 0, j = 0;
        for (int i = 0; i < vec.size(); i++) {
            sum += vec[i];
            while (sum > r) {
                sum -= vec[j];
                j++;
            }
            if (sum >= l) {
                sum = 0;
                ans++;
                j = i+1;
            }
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
