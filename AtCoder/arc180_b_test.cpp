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
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];

    V<array<int, 2>> ans;
    while (true) {
        int d = n, x, y;
        for (int i = 0; i+k < n; i++) {
            for (int j = i+k; j < n; j++) {
                if (a[i] > a[j] && ckmin(d, a[i]-a[j])) {
                    x = i; y = j;
                }
            }
        }

        if (d == n) break;
        ps(d);
        ans.pb({x, y});
        swap(a[x], a[y]);
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        cout << x+1 << ' ' << y+1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

