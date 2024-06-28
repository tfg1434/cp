#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vi b(n); for (int i = 0; i < n; i++) cin >> b[i];
    int A = 0, B = 0;
    int plus = 0, minus = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == -1 && b[i] == -1) minus++;
        else if (a[i] == 1 && b[i] == 1) plus++;
        else if (!a[i]) B += max(0LL, b[i]);
        else if (!b[i]) A += max(0LL, a[i]);
        else if (a[i] > 0) A++;
        else if (b[i] > 0) B++;
    }

    while (minus > 0) {
        if (A > B) swap(A, B);
        B--;
        minus--;
    }
    while (plus > 0) {
        if (A > B) swap(A, B);
        A++;
        plus--;
    }
    cout << min(A, B) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
