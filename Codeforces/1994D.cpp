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

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    V<array<int, 2>> ans(n);
    V<bool> del(n);
    for (int x = n-1; x >= 1; x--) {
        V<vi> where(x);
        for (int i = 0; i < n; i++) if (!del[i]) where[a[i]%x].pb(i);
        for (int r = 0; r < x; r++) {
            if (where[r].size() > 1){
                ans[x] = {where[r][0], where[r][1]};
                del[where[r][0]] = true;
                break;
            } 
        }
    }

    cout << "YES" << '\n';
    for (int x = 1; x <= n-1; x++) {
        cout << ans[x][0]+1 << ' ' << ans[x][1]+1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
