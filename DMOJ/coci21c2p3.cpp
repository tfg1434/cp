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

// const int max_e = 16*p2(15);
int a[17];
vi g[17];

int cur_bit;
void calc_a(int u, int p) {
    for (int v : g[u]) if (v != p) {
        a[v] = a[u]^p2(cur_bit);
        cur_bit++;
        calc_a(v, u);
    }
}

void solve() {
    int n; cin >> n; 
    for (int i = 0; i < n; i++) {
        int u, v; cin >> u >> v;
        g[u].pb(v); g[v].pb(u);
    }
    calc_a(0, -1);

    int even_masks[p2(n-1)], k = 0;
    for (int i = 0; i < p2(n); i++) if (pct(i)%2 == 0) {
        even_masks[k++] = i;
    }

    cout << p2(n-1) << '\n';
    for (int i = 0; i < p2(n-1); i++) {
        for (int j = 0; j <= n; j++) {
            cout << (a[j]^even_masks[i]) << " \n"[j==n];
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

