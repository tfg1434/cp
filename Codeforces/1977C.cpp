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

void solve() {
    cin >> n;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));

    int lc = 0;
    for (int i = 0; i < n; i++) {
        if (!lc) lc = a[i];
        else lc = lcm(lc, a[i]);

        if (lc > a[n-1]) {
            cout << n << '\n';
            return;
        }
    }

    vi divs;
    {
        for (int i = 1; i*i <= lc; i++) if (lc % i == 0) {
            if (i*i != lc) divs.pb(i);
            divs.pb(lc/i);
        }
    }

    int ans = 0;
    for (int d : divs) {
        int LC = 0, cnt = 0;
        bool ok = true;
        for (int i = 0; i < n; i++) if (a[i] == d) {
            ok = false; break;
        }
        if (!ok) continue;
        for (int i = 0; i < n; i++) if (d%a[i]==0) {
            if (!LC) LC = a[i];
            else LC = lcm(LC, a[i]);
            cnt++;
        }
        if (LC == d) ckmax(ans, cnt);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
