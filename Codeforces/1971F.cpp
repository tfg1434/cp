#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

#define int int64_t

int r;

void solve() {
    cin >> r;
    int extra = 0;

    int hi = r+1, lo = r+1;
    for (int x = 0; x <= r; x++) {
        while (x*x+hi*hi >= (r+1)*(r+1)) hi--;
        while (lo >= 0 && x*x+lo*lo >= r*r) lo--;
        extra += hi-lo;
    }

    cout << 4*extra-4 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
