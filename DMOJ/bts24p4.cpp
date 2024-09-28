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

const int N = 1e5;

void solve() {
    int n, k; cin >> n >> k;    
    vi a(n);
    for (int& i : a) cin >> i, i--;
    V<vi> seq(k, vi(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < k; j++) {
            cin >> seq[j][i]; seq[j][i]--;
        }
    }

    vi factor_order;
    V<bool> used(k), strictly_greater(n);
    for (int i = 0; i < k; i++) { 
        auto check = [&](int j) {
            bool res = true;
            for (int ind = 0; ind+1 < n; ind++) {
                if (strictly_greater[ind]) continue;
                res &= seq[j][a[ind]] >= seq[j][a[ind+1]];
            }
            return res;
        };
        bool found = false;
        for (int j = 0; j < k; j++) if (!used[j]) {
            if (check(j)) {
                used[j] = true;
                factor_order.pb(j);
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "-1\n";
            return;
        }
        for (int ind = 0; ind+1 < n; ind++) {
            if (seq[factor_order.back()][a[ind]] > seq[factor_order.back()][a[ind+1]]) {
                strictly_greater[ind] = true;
            }
        }
    }

    for (int i = 0; i < k; i++) cout << factor_order[i]+1 << " \n"[i==k-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
