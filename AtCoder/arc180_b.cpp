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
    vi p(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i]; p[i]--;
        q[p[i]] = i;
    }

    V<array<int, 2>> ans;
    for (int i = 0; i < n; i++) {
        vi positions;
        for (int j = 0; j < i; j++) {
            if (q[j] - q[i] >= k) positions.pb(j);
        }

        int last = i;
        while (positions.size()) {
            ans.pb({q[positions.back()], q[last]});
            swap(q[positions.back()], q[last]);
            last = positions.back();
            positions.pop_back();
        }
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans) {
        if (x > y) swap(x, y);
        cout << x+1 << ' ' << y+1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
