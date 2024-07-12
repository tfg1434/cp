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
    int n, S; cin >> n >> S;
    if (S < n || S > n*(n+1)/2) {
        cout << -1 << '\n';
        return;
    }
    S -= n;

    vi sol;
    int cur = n-1;
    while (S > 0 && S >= cur) {
        S -= cur;
        sol.pb(cur);
        cur--;
    }
    if (S > 0) sol.pb(S);
    sol.pb(0);
    while (sol.size() < n)  {
        if (cur != S) sol.pb(cur);
        cur--;
    }
    reverse(all(sol));
    for (int i = 0; i < n; i++) cout << sol[i] << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}


