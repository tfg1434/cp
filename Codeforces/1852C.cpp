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
template<class T> using pqg = priority_queue<T, V<T>, greater<T>>;

int n, k;

void solve() {
    cin >> n >> k;    
    vi a(n+2);
    for (int i = 0; i < n; i++) {
        cin >> a[i+1];
        if (a[i+1] == k) a[i+1] -= k;
    }

    int ans = 0;
    pqg<int> q;
    for (int i = 0; i < n+1; i++) {
        if (a[i] == a[i+1]) continue;
        if (a[i] < a[i+1]) {
            q.push({a[i+1]-a[i]});
            ans += q.top(); q.pop();
        } else {
            q.push(k - (a[i]-a[i+1]));
        }
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
