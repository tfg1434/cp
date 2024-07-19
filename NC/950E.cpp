// n <= 500 for an O(n log n) problem

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
    int m; cin >> m;
    int n; cin >> n;
    V<vi> at(n+1);
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        at[d].pb(i);
    }
    int W = 0;
    vi w(n);
    for (int i = 0; i < n; i++) cin >> w[i], W += w[i];

    int score = 0;
    multiset<int> prices;
    for (int d = n; d >= 1; d--) {
        for (int ind : at[d]) prices.insert(w[ind]);
        if (prices.size()) {
            int mx = *rbegin(prices);
            score += mx;
            prices.erase(prices.find(mx));
        }
    }
    cout << max((int)0, m-W+score) << '\n'; // for some reason, 0LL breaks on their machine (c++17)
                                            // write this from now on
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
