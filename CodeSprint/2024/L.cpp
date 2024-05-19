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

int n, m;
vi a;

void solve() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    if (2*m-1 > n) {
        cout << "0\n";
        for (int i = 0; i < n; i++) cout << a[i] << " \n"[i];
        return;
    }

    vi ans, templ;
    for (int i = 0; i < m; i++) templ.pb(2*i);
    for (int i = m-1; i >= 1; i--) templ.pb(2*i-1);

    int off = 0, cnt = 1;
    ans = templ;
    while (ans.size()+templ.size()-1 <= n) {
        cnt++;
        off += templ.size()-1;
        for (int i = 1; i < templ.size(); i++)
            ans.pb(templ[i] + off);
    }
    for (int i = off+templ.size()-1; i < n; i++) ans.pb(i);
    cout << cnt << '\n';
    for (int i = 0; i < n; i++) cout << a[ans[i]] << " \n"[i == n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
