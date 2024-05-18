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

int n;
const int max_bit = 20;
int f[max_bit];

void solve() {
    cin >> n; 
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    auto check = [&](int m) {
        memset(f, 0, sizeof f);
        for (int i = 0; i < m; i++) for (int j = 0; j < max_bit; j++)
            if (a[i] & (1 << j)) f[j]++;
        for (int i = m; i < n; i++) {
            for (int j = 0; j < max_bit; j++) if (a[i] & (1 << j)) {
                if (!f[j]) return false;
                f[j]++;
            }
            for (int j = 0; j < max_bit; j++) if (a[i-m] & (1 << j)) {
                f[j]--;
                if (!f[j]) return false;
            }
        }
        return true;
    };
    int lo = 1, hi = n+1;
    while (lo < hi) {
        int m = (lo+hi)/2;
        !check(m) ? lo = m+1 : hi = m;
    }
    cout << hi << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
