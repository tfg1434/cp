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
    int n, T; cin >> n >> T;
    string s; cin >> s;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    int ans = 0;
    int j = -1, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            while (j+1 < n && a[j+1]-a[i] <= 2*T) {
                cnt += s[j+1] == '0';
                j++;
            }
            ans += cnt;
        } else {
            cnt--;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
