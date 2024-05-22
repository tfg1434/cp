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

int n;
vi a, b;

void solve() {
    cin >> n; 
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i]; reverse(all(a));
    b.resize(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    int ans = 0;
    pqg<int> q;
    for (int i = 0; i < n; i++) {
        ans += a[i]; q.push(a[i]);
        ans += b[i]; q.push(b[i]);
        ans -= q.top(); q.pop();
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
