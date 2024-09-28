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

int C2(int n) {
    return n*(n-1)/2;
}

void solve() {
    int n; cin >> n;    
    int r, i; cin >> r >> i; r--; i--;

    int ans = n*(2*n+3)*(n+1)/8 - (n+1)/2/4;
    ans -= (i+1)*(r-i+1);

    int max_w = min(n-1-r, r+1);
    for (int w = 1; w <= max_w; w++) {
        int left_over = max((int)0, 0 - (i-(w-1))), right_over = max((int)0, i+w-1 - r);
        ans -= w-left_over-right_over;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
