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

int n;
V<array<int, 2>> t;
void init_tree() {
    int siz = 1;
    while (siz < 2*n) siz *= 2;
    t.clear();
    t.resize(siz);
}
array<int, 2> merge(array<int, 2> a, array<int, 2> b) {
    return {a[0]+b[0], a[1]+b[1]};
}
array<int, 2> range_sum(int L, int R, int u=0, int l=0, int r=n) {
    if (r <= L || R <= l) return {0, 0};
    if (L <= l && r <= R) return t[u];
    int m = (l+r)/2;
    return merge(range_sum(L, R, 2*u+1, l, m), range_sum(L, R, 2*u+2, m, r));
}
void point_add(int i, int x, int u=0, int l=0, int r=n) {
    if (l == r-1) {
        t[u] = {1, x};
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_add(i, x, 2*u+1, l, m);
    else point_add(i, x, 2*u+2, m, r);
    t[u] = merge(t[2*u+1], t[2*u+2]);
}

void solve() {
    cin >> n;
    vi p(n);
    for (int& i : p) cin >> i, i--;
    init_tree();

    int ans = 0;
    for (int i = 0; i < n; i++) {
        auto [cnt, sum_less] = range_sum(0, p[i]);
        sum_less += cnt + i+1;
        ans += sum_less;
        point_add(p[i], i);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
