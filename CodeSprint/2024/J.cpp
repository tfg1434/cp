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
vi a;

void solve() {
    cin >> n >> k;
    vi s(4), mx(4);
    a.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        s[a[i]%4] += a[i];
        mx[a[i]%4] = max(mx[a[i]%4], a[i]);
    }
    
    int ans;
    if (k%4 == 0) ans = s[0];
    if (k%4 == 2) {
        if (mx[2]) ans = mx[2]+s[0];
        else ans = 0;
    }
    if (k%4 == 1) {
        if (mx[1] && mx[2]) ans = mx[1]+mx[2]+s[0];
        else if (mx[1]) ans = mx[1];
        else ans = 0;
    }
    if (k%4 == 3) {
        if (mx[3] && mx[2]) ans = mx[3]+mx[2]+s[0];
        else if (mx[3]) ans = mx[3];
        else ans = 0;
    }

    cout << k+ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
