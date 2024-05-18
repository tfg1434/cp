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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

int n, k;

int ask(int l, int x) {
    cout << "? " << l+1 << ' ' << x << endl;
    int res; cin >> res;
    return res;
}
void answer(int ans) {
    cout << "! " << ans << endl;
    int trash; cin >> trash;
}

void solve() {
    cin >> n >> k; 
    int mx;
    for (mx = 1; mx <= n; mx++) {
        if (ask(0, n*mx) == n) break;
    }

    for (int i = n/k; i >= 1; i--) {
        int l = 0, cnt = 0;
        while (l < n) {
            int res = ask(l, mx*i);
            l = res;
            cnt++;
            if (cnt == k) break;
        }
        if (cnt == k && l == n) {
            answer(mx*i);
            return;
        }
    }
    answer(-1);
}

signed main() {
    int t; cin >> t; while (t--) solve();
    return 0;
}
