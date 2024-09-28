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
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

int n;
vi a, t, buf;
void push(int u, int len) {
    if (buf[u] != inf) {
        t[u] = buf[u]*len + (len-1)*len/2;
        if (len > 1) {
            buf[2*u+1] = buf[u];
            buf[2*u+2] = buf[u]+len/2;
        }
        buf[u] = inf;
    }
}
void range_set(int L, int R, int start, int u=0, int l=0, int r=n) {
    push(u, r-l);
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        buf[u] = start+l-L;
        push(u, r-l);
        return;
    }
    int m = (l+r)/2;
    range_set(L, R, start, 2*u+1, l, m);
    range_set(L, R, start, 2*u+2, m, r);
    t[u] = t[2*u+1]+t[2*u+2];
}
int range_sum(int L, int R, int u=0, int l=0, int r=n) {
    push(u, r-l);
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return t[u];
    int m = (l+r)/2;
    return range_sum(L, R, 2*u+1, l, m)+range_sum(L, R, 2*u+2, m, r);
}
void init_tree() {
    int siz = 1;
    while (siz < 2*n) siz *= 2;
    t.rsz(siz);
    buf.rsz(siz, inf);
    for (int i = 0; i < n; i++) {
        range_set(i, i+1, a[i]);
    }
}

void solve() {
    cin >> n;
    a.resize(n);
    for (int& i : a) cin >> i;
    init_tree();

    int ans = 0;
    int q; cin >> q;
    while (q--) {
        int idx, dest; cin >> idx >> dest; idx--;
        int cost = 0;
        if (range_sum(idx, idx+1) < dest) {
            int lo = idx, hi = n;
            while (hi-lo > 1) {
                int mi = (lo+hi)/2;
                int a_mi = range_sum(mi, mi+1);
                dest+mi-idx-1 < a_mi ? hi = mi : lo = mi;
            }

            int len = hi-idx;
            cost += dest*len + (len-1)*len/2 - range_sum(idx, hi);
            range_set(idx, hi, dest);
        }
        if (range_sum(idx, idx+1) > dest) {
            int lo = -1, hi = idx;
            while (hi-lo > 1) {
                int mi = (lo+hi)/2;
                int a_mi = range_sum(mi, mi+1);
                a_mi <= dest-(mi-lo) ? lo = mi : hi = mi;
            }

            int len = idx-lo;
            cost += range_sum(lo+1, idx+1) - ((dest-len+1)*len + (len-1)*len/2);
            range_set(lo+1, idx+1, dest-len+1);
        }

        ans += cost;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
