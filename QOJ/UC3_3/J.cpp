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

// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define pct __builtin_popcount
constexpr int p2(int x) { return (int)1 << x; }
constexpr int msk2(int x) { return p2(x)-1; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 

void solve() {
    int n; cin >> n;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i], a[i]--;
    int cnt = 0;
    V<bool> vis(n);
    int i = 0;
    do {
        vis[i] = true;
        cnt++;
        i = a[i];
    } while (!vis[i]);

    if (cnt < n) {
        cout << n << '\n';
        cout << cnt << '\n';
        for (int i = 0; i < n; i++) if (vis[i]) cout << i+1 << ' ';
        cout << '\n';

    } else {
        cout << n-2 << '\n';
        vi red_path, blue_path;
        int u = 0;
        do {
            red_path.pb(u);
            u = a[u];
        } while (u != 1);
        // do {
            // blue_path.pb(u);
            // u = a[u];
        // } while (u != 0);
        int m = red_path.size();
        cout << m << '\n';
        for (int i = 0; i < m; i++) 
            cout << red_path[i]+1 << " \n"[i==m-1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

