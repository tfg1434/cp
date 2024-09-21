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

int n;

vi t;
void init_tree() {
    int siz = 1;
    while (siz < 2*n) siz *= 2;
    t.resize(siz);
}
void pull(int u) { t[u] = t[2*u+1]+t[2*u+2]; }
void point_on(int i, int u=0, int l=0, int r=n) {
    if (l == r-1) {
        t[u] = 1;
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_on(i, 2*u+1, l, m);
    else point_on(i, 2*u+2, m, r);
    pull(u);
}
int search(int u, int l, int r, int L, int R, int& acc, int k) {
    if (r <= L || R <= l) return -1;
    if (L <= l && r <= R && acc + t[u] < k) {
        acc += t[u];
        return -1;
    }
    if (l + 1 == r) return l;

    int m = (l + r) / 2;
    int res = search(u * 2+1, l, m, L, R, acc, k);
    if (res != -1) return res;
    return search(u * 2 + 2, m, r, L, R, acc, k);
}

void solve() {
    cin >> n;    
    init_tree();
    vi a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        if (!a[i]) {
            point_on(i);
        }
    }
    
    int q; cin >> q;
    while (q--) {
        char typ; cin >> typ;
        if (typ == 's') {
            int l, r, k; cin >> l >> r >> k; l--;
            int acc = 0;
            int res = search(0, 0, n, l, r, acc, k);
            if (res != -1) res++;
            cout << res << '\n';
        } else {
            int i, x; cin >> i >> x; i--;
            if (!x) {
                point_on(i);
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
