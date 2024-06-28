#include <bits/stdc++.h>
using namespace std;
using db = long double;
const db eps = 1e-9;
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
    int k, q; cin >> k >> q;

    while (q--) {
        int inp; cin >> inp;
        db p = 1.L*inp/2000;

        int lo = 0, hi = 1e5;        
        while (hi-lo > 1) {
            int d = (lo+hi)/2;
            db p_succ = 0;
            for (int pc = 0; pc <= k; pc++) {
                int coef = pc%2 == 0 ? 1 : -1;
                p_succ += coef*pow(1.L*(k-pc)/k, d);
            }
            p_succ+eps > p ? hi = d : lo = d;
        }

        cout << hi << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
