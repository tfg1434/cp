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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int n;
vi a;

int dnc(int l, int r) {
    if (l == r) return 0;
    int mn = *min_element(begin(a)+l, begin(a)+r);
    int pos = -1;
    for (int i = l; i < r; i++) {
        if (a[i] == mn) pos = i;
        a[i] -= mn;
    }
    return min(mn + dnc(l, pos) + dnc(pos+1, r), r-l);
}

void solve() {
    cin >> n;
    a.resize(n); for (int i = 0; i < n; i++) cin >> a[i];
    cout << dnc(0, n) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
