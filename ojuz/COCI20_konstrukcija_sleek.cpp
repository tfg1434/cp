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

const int LOG = 64;

void solve() {
    int k; cin >> k; 
    if (!k) {
        printf("3 2\n");
        printf("1 2\n");
        printf("2 3\n");
        return;
    }
    bool neg = false;
    if (k < 0) {
        neg = true;
        k = -k;
    }
    
    int n = 3;
    V<array<int, 2>> edges;

    vi lst = {2, 3};
    edges.pb({1, 2});
    edges.pb({1, 3});
    auto append = [&](int k) {
        vi nw(k);
        iota(all(nw), n+1);
        for (int i = 0; i < len(lst); i++) {
            for (int j = 0; j < len(nw); j++) {
                edges.pb({lst[i], nw[j]});
            }
        }
        swap(nw, lst);
        n += k;
    };

    vi events;
    while (k > 1) {
        if (k%2) events.pb(1);
        events.pb(2);
        k /= 2;
    }
    reverse(all(events));
    for (int event : events) {
        if (event == 1) {
            // add 1
            edges.pb({1, ++n});
            lst.pb(n);
        } else {
            // multiply by 2
            append(3);
            append(2);
        }
    }
    if (neg) append(2);

    n++;
    for (int u : lst) edges.pb({u, n});
    int m = len(edges);
    cout << n << ' ' << m << '\n';
    for (auto [u, v] : edges) cout << u << ' ' << v << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
