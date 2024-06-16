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
    V<V<array<int, 2>>> events(2);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        int X = x+y, Y = x-y;
        events[abs(X)%2].pb({Y, X});
    }

    int64_t ans = 0;
    for (int p = 0; p < 2; p++) {
        sort(all(events[p]));
        multiset<int> above, below;
        for (int i = 0; i < events[p].size(); i++) {
            auto [Y, X] = events[p][i];
            below.insert(X);
        }

        for (int i = 0; i+1 < events[p].size(); i++) {
            auto [Y, X] = events[p][i];
            above.insert(X);
            below.erase(below.find(X));
            if (above.size() && below.size()) {
                int coef = (events[p][i+1][0] - Y) / 2;
                ans += 1LL * coef * max(0, min(*rbegin(above), *rbegin(below)) - max(*begin(above), *begin(below))) / 2;
            }
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
