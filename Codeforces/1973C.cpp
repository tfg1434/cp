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

int n;
const int max_n = 1e5;
int p[max_n], ans[max_n];

void solve() {
    cin >> n; 
    int n_pos;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        if (p[i] == n) n_pos = i;
    }
    if (n_pos % 2) reverse(p, p+n);

    vi mx;
    for (int i = 0; i < n; i += 2) mx.pb(p[i]);
    sort(all(mx));
    for (int i = 0; i < n; i += 2) ans[i] = n-lwb(mx, p[i]);
    vi mn;
    for (int i = 1; i < n; i += 2) mn.pb(p[i]);
    sort(all(mn));
    for (int i = 1; i < n; i += 2) ans[i] = n/2-lwb(mn, p[i]);

    if (n_pos % 2) reverse(ans, ans+n);
    for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
