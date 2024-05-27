// WA

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9+1;

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

struct segtree {
    int n;
    vi t, buf;
    segtree(vi a) {
        n = a.size();
        int size = 1;
        while (size < 2*n) size *= 2;
        t.resize(size);
        buf.assign(size, -1);
        build(0, 0, n, a);
    }
    void build(int v, int l, int r, const vi& a) {
        if (l == r-1) {
            t[v] = a[l];
            return;
        }
        int m = (l+r)/2;
        build(2*v+1, l, m, a);
        build(2*v+2, m, r, a);
        t[v] = min(t[2*v+1], t[2*v+2]);
    }
    void push(int v, int l, int r) {
        if (buf[v] != -1) {
            t[v] = buf[v];
            if (l != r - 1) {
                buf[2 * v + 1] = buf[v];
                buf[2 * v + 2] = buf[v];
            }
            buf[v] = -1;
        }
    }
    int range_min(int v, int l, int r, int L, int R) {
        push(v, l, r);
        if (l >= R || r <= L) return inf;
        if (l >= L && r <= R) return t[v];
        int m = (l + r) / 2;
        return min(range_min(2 * v + 1, l, m, L, R), range_min(2 * v + 2, m, r, L, R));
    }
    void range_set(int v, int l, int r, int L, int R, int x) {
        push(v, l, r);
        if (l >= R || r <= L) return;
        if (l >= L && r <= R) {
            buf[v] = x;
            push(v, l, r);
            return;
        }
        int m = (l + r) / 2;
        range_set(2 * v + 1, l, m, L, R, x);
        range_set(2 * v + 2, m, r, L, R, x);
        t[v] = min(t[2 * v + 1], t[2 * v + 2]);
    }
    int range_min(int L, int R) {
        return range_min(0, 0, n, L, R);
    }
    void range_set(int L, int R, int x) {
        range_set(0, 0, n, L, R, x);
    }
};

int n, k, q;
vi b;

void solve() {
    cin >> n >> k;    
    b.resize(n);
    for (int i = 0; i < n; i++) cin >> b[i];
    segtree B(b);

    vi xs;
    V<array<int, 4>> queries;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int tp, l, r; cin >> tp >> l >> r; l--;
        xs.pb(l); xs.pb(r);
        if (tp == 1) {
            int x; cin >> x;
            queries.pb({1, l, r, x});
        } else {
            queries.pb({2, l, r, -1});
        }
    }
    sort(all(xs));
    xs.erase(unique(all(xs)), end(xs));
    vi c(xs.size()-1);
    for (int i = 0; i < xs.size()-1; i++) {
        if (xs[i]/k == xs[i+1]/k) {
            c[i] = B.range_min(xs[i]%n, xs[i]%n + xs[i+1]-xs[i]);
        } else {
            c[i] = min(
                    B.range_min(xs[i]%n, n),
                    B.range_min(0, xs[i+1]-xs[i+1]/k*k)
                    );
        }
    }
    segtree C(c);

    for (auto [TP, L, R, INFO] : queries) {
        int l = lwb(xs, L), r = lwb(xs, R);
        if (TP == 1) {
            C.range_set(l, r, INFO);
        } else {
            cout << C.range_min(l, r) << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
