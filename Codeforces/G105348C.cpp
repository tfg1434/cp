#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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
#define len(x) (int)((x).size())
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
#define pct __builtin_popcountll 
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    vector d(26, vi(26, inf));
    for (int i = 0; i < 26; i++) {
        for (int j = 0; j < 26; j++) {
            int last_i = -1, last_j = -1;
            for (int k = 0; k < n; k++) {
                if (s[k]-'a' == i) last_i = k;
                if (s[k]-'a' == j) last_j = k;
                if (last_i != -1 && last_j != -1) {
                    ckmin(d[i][j], abs(last_i-last_j));
                    d[j][i] = d[i][j];
                }
            }
        }
    }

    for (int k = 0; k < 26; k++){
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                ckmin(d[i][j], d[i][k]+d[k][j]);
            }
        }
    }

    while (q--) {
        char u, v; cin >> u >> v;
        int ans = d[u-'a'][v-'a'];
        if (ans == inf) ans = -1;
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
