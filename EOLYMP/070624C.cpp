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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

// namespace SegmentTree {
    // struct Tree {
        // int n;
        // vi t, buf;

        // void pull(int v) {
            // t[v] = min(t[2*v+1], t[2*v+2]);
        // }
        // void push(int v) {
            // if (buf[v]) {
                // if (2*v+2 < buf.size()) {
                    // buf[2*v+1] += buf[v];
                    // buf[2*v+2] += buf[v];
                // }
                // t[v] += buf[v];
                // buf[v] = 0;
            // }
        // }

        // void range_add(int v, int l, int r, int L, int R, int x) {
            // push(v);
            // if (r <= L || R <= l) return;
            // if (L <= l && r <= R) {
                // buf[v] = x;
                // push(v);
                // return;
            // }
            // int m = (l+r)/2;
            // range_add(2*v+1, l, m, L, R, x);
            // range_add(2*v+2, m, r, L, R, x);
            // pull(v);
        // }
        // void range_add(int L, int R, int x) { range_add(0, 0, n, L, R, x); }

        // int range_min(int v, int l, int r, int L, int R){
            // if (r <= L || R <= l) return inf;
            // if (L <= l && r <= R) return t[v];
            // int m = (l+r)/2;
            // return min(range_min(2*v+1, l, m, L, R), range_min(2*v+2, m, r, L, R));
        // }
        // int range_min(int L, int R) { return range_min(0, 0, n, L, R); }

        // Tree(const vi& a) {
            // n = a.size();
            // int siz = 1;
            // while (siz < 2*n) siz *= 2;
            // t.resize(siz);
            // buf.resize(siz);
            // for (int i = 0; i < n; i++) {
                // range_add(i, i+1, a[i]);
            // }
        // }
    // };
// }

void solve() {
    int n; cin >> n;
    vi a(n), t(n);
    for (int i = 0; i < n; i++) cin >> t[i];
    for (int i = 0; i < n; i++) cin >> a[i];
    V<array<int, 2>> rt;
    for (int i = 0; i < n; i++) {
        rt.pb({i+a[i], t[i]});
    }
    sort(all(rt));

    int ans = 0;
    multiset<int> available_t;
    for (int i = n-1; i >= 0; i--) {
        while (rt.size() && rt.back()[0] == i) {
            available_t.insert(rt.back()[1]);
            rt.pop_back();
        }
        ans += (n-i)*(*rbegin(available_t));
        available_t.erase(prev(end(available_t)));
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
