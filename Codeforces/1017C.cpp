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
    int k = sqrt(n);
    int beat = (n+k-1)/k;
    if (k-1 > 0 && ckmin(beat, (n+k-2)/(k-1))) k--;
    else if (k+1 <= n && ckmin(beat, (n+k)/(k+1))) k++;

    int cur = n;
    for (int i = 0; i < beat; i++) {
        for (int j = max(1, cur-k+1); j <= cur; j++) cout << j << ' ';
        cur -= k;
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
