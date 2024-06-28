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

const int LOG = 15;
// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define pct __builtin_popcount
constexpr int p2(int x) { return (int)1 << x; }
constexpr int msk2(int x) { return p2(x)-1; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 

void solve() {
    int n; cin >> n;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    vi b(n); for (int i = 0; i < n; i++) cin >> b[i];

    auto change(int i, int j) {

    };
    auto solve(int i, int y, int j) {
        for (; j < LOG; j++) {
            if ((a[i]&p2(j)) != (y&p2(j))) {
                if (pos[a[i]|p2(j)] == -1) {
                    change(i, j);
                } else {

                }
            }
        }
    };

    for (int i = 0; i < n; i++) {
        pos[a[i]] = i;
        ok[b[i]] = true;
    }
    for (int i = 0; i < n; i++) if (!ok[a[i]])
        s.insert(i);
    for (int i = 0; i < n; i++) if (pos[b[i]] == -1)
        solve(*s.begin(), b[i]);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
