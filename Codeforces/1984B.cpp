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
    int inp; cin >> inp;
    string s = to_string(inp); int n = s.size();
    string oo = string(n-1, '1') + string(1, '0');
    int x = stoll(oo, 0, 0);
    if (inp < x) {
        cout << "NO\n";
        return;
    }
    inp -= x;
    bool ok = true;
    string t = to_string(inp);
    char c = *max_element(all(t));
    if (c > '8' || t.size() > n-1) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
