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
    int n, c; cin >> n >> c;
    V<array<int, 3>> a(n); // t, k, ind
    for (int i = 0; i < n; i++) {
        cin >> a[i][0] >> a[i][1];
        a[i][2] = i;
    }
    a.pb({0, 69, 69}); n++;
    sort(all(a));

    vi ans;
    set<array<int, 2>> s;
    for (int i = n-1; i-1 >= 0; i--) {
        s.insert({ a[i][1], a[i][2] });
        int gap = (a[i][0]-a[i-1][0])*c;
        while (!s.empty() && gap) {
            auto [u, v] = *s.begin();
            if (gap < u) {
                s.erase(s.begin());
                s.insert({ u-gap, v });
                gap = 0;
            } else {
                ans.pb(v);
                s.erase(s.begin());
                gap -= u;
            }
        }
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i]+1 << " \n"[i==ans.size()-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
