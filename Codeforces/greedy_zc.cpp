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
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int n;
vi a;

void solve() {
    cin >> n;
    a.resize(n); for (int i = 0; i < n; i++) cin >> a[i];

    vb sol(n);
    int ans = 0;
    multiset<array<int, 2>> close;
    for (int i = 0; i < n; i++) {
        close.insert({ a[i], i });
        if (i%2 == 0) {
            auto mx = prev(end(close));
            ans += (*mx)[0];
            sol[(*mx)[1]] = true;
            close.erase(mx);
        }
    }

    for (int i = 0; i < n; i++) cout << (sol[i] ? '(' : ')');
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
