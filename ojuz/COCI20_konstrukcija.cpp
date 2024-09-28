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
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

const int LOG = 5, N = 4*LOG+2;

void solve() {
    int k; cin >> k; 
    V<array<int, 2>> edges;
    for (int i = 0; i < LOG; i++) {
        for (int j = 0; j < 4; j++) {
            int u = 1+4*i+j;
            if (j < 4) {
                if (i+1 < LOG) {
                    for (int k = 0; k < 3; k++) {
                        edges.pb({u, 4*(i+1)+1+k});
                    }
                } else {
                    edges.pb({u, N-1});
                }
            } else {
                edges.pb({u, u-1});
                edges.pb({u, u-2});
            }
        }
    }

    if (k >= 0) {
        for (int i = 0; i < LOG; i++) if (k & p2(i)) {
            edges.pb({0, 4*i+1});
            if (i%2 == 0) {
                edges.pb({0, 4*i+2});
            } else {
                edges.pb({0, 4*i+4});
            }
        }
    } else {
        for (int i = 0; i < LOG; i++) if (k & p2(i)) {
            edges.pb({0, 4*i+1});
            if (i%2 == 1) {
                edges.pb({0, 4*i+2});
            } else {
                edges.pb({0, 4*i+4});
            }
        }
    }

    cout << N << ' ' << len(edges) << '\n';
    for (auto [u, v] : edges) {
        cout << u+1 << ' ' << v+1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
