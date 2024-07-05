#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 2e18;

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
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int q; cin >> q;
    string _; getline(cin, _);
    while (q--) {
        string s; getline(cin, s);
        stringstream ss(s);
        vi data(3, inf);
        int k = 0;
        while (ss >> data[k++]) {}
        auto [l, r, v] = tie(data[0], data[1], data[2]);
        if (v == inf) {
            int mn = inf;
            if (l <= r) {
                for (int i = l; i <= r; i++) ckmin(mn, a[i]);
            } else {
                for (int i = l; i < n; i++) ckmin(mn, a[i]);
                for (int i = 0; i <= r; i++) ckmin(mn, a[i]);
            }
            cout << mn << '\n';

        } else {
            if (l <= r) {
                for (int i = l; i <= r; i++) a[i] += v;
            } else {
                for (int i = l; i < n; i++) a[i] += v;
                for (int i = 0; i <= r; i++) a[i] += v;
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

