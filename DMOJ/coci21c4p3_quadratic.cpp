#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

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

const int N = 2e5, K = 105;

void solve() {
    int n; cin >> n;    
    vi a(n), values;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        values.pb(a[i]);
    }
    sort(all(values));
    values.erase(unique(all(values)), values.end());
    int mx = values.size();
    vi freq(mx);
    for (int& x : a) {
        x = lwb(values, x);
        freq[x]++;
    }

    i64 ans = 0;
    for (int v = 0; v < mx; v++) {
        vi seen(2*n+1);
        seen[0 + n] = 1;
        int s = 0, p = 0;
        for (int i = 1; i <= n; i++) {
            if (a[i-1] == v) {
                p += seen[s + n];
                s++;
            } else {
                s--;
                p -= seen[s + n];
            }
            ans += p;
            seen[s + n]++;
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

