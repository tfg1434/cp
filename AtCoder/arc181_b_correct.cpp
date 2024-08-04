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
    string s, ta, tb; cin >> s >> ta >> tb;
    int S = s.size(), TA = ta.size(), TB = tb.size();
    int x = count(all(ta), '0'), y = TA-x;
    int X = count(all(tb), '0'), Y = TB-X;
    if (y == Y) {
        if (x == X) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    }
    int T = S*(x-X);
    if (T%(Y-y)) {
        cout << "No\n";
        return;
    }
    T /= (Y-y);
    if (T < 0) {
        cout << "No\n";
        return;
    }

    int period = gcd(S, T);
    bool periodic = true;
    for (int i = 0; i+period < S; i++) periodic &= s[i+period] == s[i];
    cout << (periodic ? "Yes" : "No") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

