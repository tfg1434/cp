#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

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

int n;

V<array<int, 2>> t;
const array<int, 2> default_info = {inf, -inf};
array<int, 2> merge_info(const array<int, 2>& a, const array<int, 2>& b) {
    return { min(a[0], b[0]), max(a[1], b[1]) };
}
void init_tree() {
    int size = 1;
    while (size < 2*n) size *= 2;
    t.resize(size, default_info);
}
void point_set(int v, int l, int r, int i, const array<int, 2>& x) {
    if (l == r-1) {
        t[v] = x;
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_set(2*v+1, l, m, i, x);
    else point_set(2*v+2, m, r, i, x);
    t[v] = merge_info(t[2*v+1], t[2*v+2]);
}
array<int, 2> range_mm(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return default_info;
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return merge_info(range_mm(2*v+1, l, m, L, R), range_mm(2*v+2, m, r, L, R));
}

void solve() {
    cin >> n;
    init_tree();
    vi a(n);
    set<int> s;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (i && a[i] < a[i-1]) s.insert(i);
        point_set(0, 0, n, i, {a[i], a[i]});
    }

    int q; cin >> q;
    V<array<int, 2>> queries(q+1);
    queries[0] = {0, a[0]};
    for (int i = 1; i <= q; i++) {
        int pos, val; cin >> pos >> val; pos--;
        queries[i] = {pos, val};
    }
    for (auto [pos, val] : queries) {
        point_set(0, 0, n, pos, { val, val });
        s.erase(pos); s.erase(pos+1);
        a[pos] = val;
        if (pos && a[pos] < a[pos-1]) s.insert(pos);
        if (pos+1 < n && a[pos+1] < a[pos]) s.insert(pos+1);

        if (s.empty()) {
            cout << "-1 -1\n";
            continue;
        }

        int L = (*s.begin())-1, R = (*s.rbegin()) + 1; // we at least have to sort [L, R)
        auto [mn, mx] = range_mm(0, 0, n, L, R);

        int l, r;
        {
            int lo = -1, hi = L;
            while (hi-lo > 1) {
                int mi = (lo+hi)/2;
                a[mi] > mn ? hi = mi : lo = mi;
            }
            l = hi; 
        }

        {
            int lo = R-1, hi = n;
            while (hi-lo > 1) {
                int mi = (lo+hi)/2;
                a[mi] < mx ? lo = mi : hi = mi;
            }
            r = lo;
        }

        cout << l+1 << ' ' << r+1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
