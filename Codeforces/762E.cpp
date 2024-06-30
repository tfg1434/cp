#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

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

const int X = 1e9+1;

int f_timer;
struct Item {
    array<int, 2> x;
    int y, siz;
    int l, r;
    Item() {}
    Item(int x) : x({x, f_timer++}), y(rand()), siz(1), l(-1), r(-1) {}
} treap[7'000'000];
int treap_node;
int siz(int v) {
    return v == -1 ? 0 : treap[v].siz;
}
void pull(int v) {
    if (v != -1) {
        treap[v].siz = siz(treap[v].l)+siz(treap[v].r)+1;
    }
}
void split(int v, const array<int, 2>& x, int& l, int& r) {
    if (v == -1) return void(l = r = -1);
    ps("split", v, treap[v].l, treap[v].r);
    if (treap[v].x < x) {
        split(treap[v].r, x, treap[v].r, r);
        l = v;
    } else {
        split(treap[v].l, x, l, treap[v].l);
        r = v;
    }
    pull(v);
}
void merge(int& v, int l, int r) {
    if (l == -1) return void(v = r);
    if (r == -1) return void(v = l);
    if (treap[l].y < treap[r].y) {
        merge(treap[l].r, treap[l].r, r);
        v = l;
    } else {
        merge(treap[r].l, l, treap[r].l);
        v = r;
    }
    pull(v);
}

struct Node {
    int v, l, r;
    Node() : v(-1), l(-1), r(-1) {}
} t[7'000'000];
int seg_node = 1;
void extend(int v) {
    if (t[v].l == -1) {
        t[v].l = seg_node++;
        t[v].r = seg_node++;
    }
}

int range_sum(int v, int l, int r, int L, int R, int lf, int rf) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) {
        v = t[v].v;
        if (v == -1) return 0; // ?
        int v1, v2, v3;
        ps("call site", v);
        split(v, { rf, -1 }, v2, v3);
        ps("call site 2", v2);
        split(v2, { lf, -1 }, v1, v2);

        int res = siz(v2);

        merge(v, v1, v2);
        merge(v, v, v3);
        return res;
    }
    int m = (l+r)/2;
    extend(v);
    return range_sum(t[v].l, l, m, L, R, lf, rf) + range_sum(t[v].r, m, r, L, R, lf, rf);
}

void upd(int v) {
    int L = t[v].l, R = t[v].r;
    if (t[L].v != -1 && t[R].v != -1 && treap[t[L].v].x > treap[t[R].v].x) swap(L, R);
    merge(t[v].v, t[L].v, t[R].v);
}

void point_add(int v, int l, int r, int i, int f) {
    if (l == r-1) {
        t[v].v = treap_node;
        v = treap_node++;
        treap[v] = Item(f);
        return;
    }
    int m = (l+r)/2;
    extend(v);
    if (i < m) point_add(t[v].l, l, m, i, f);
    else point_add(t[v].r, m, r, i, f);
    upd(v);
}

void solve() {
    int n, k; cin >> n >> k;
    V<array<int, 3>> a(n);
    for (int i = 0; i < n; i++) {
        int x, r, f; cin >> x >> r >> f;
        a[i] = {r, x, f};
    }
    sort(rall(a));
    i64 ans = 0;
    for (auto [r, x, f] : a) {
        int cnt = range_sum(0, 1, X, x-r, x+r+1, f-k, f+k+1);
        ans += cnt;
        point_add(0, 1, X, x, f);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
