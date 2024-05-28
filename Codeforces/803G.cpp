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

int n, k, q, N, K;
vi b;

struct node {
    int l, r, mn, buf;
    node() {
        l = r = buf = -1;
        mn = inf;
    }
} t[6'000'000];
int tree_sz = 1;

int next_p2(int x) {
    int res = 1;
    while (res < x) res *= 2;
    return res;
}

int get_l(int v) {
    if (t[v].l != -1) t[tree_sz] = t[t[v].l];
    t[v].l = tree_sz++;
    return t[v].l;
}
int get_r(int v) {
    if (t[v].r != -1) t[tree_sz] = t[t[v].r];
    t[v].r = tree_sz++;
    return t[v].r;
}
void pd(int v) {
    if (t[v].buf != -1) {
        t[v].mn = t[v].buf;
        t[get_l(v)].buf = t[v].buf;
        t[get_r(v)].buf = t[v].buf;
        t[v].buf = -1;
    }
}
int range_min(int v, int l, int r, int L, int R) {
    pd(v);
    if (r <= L || R <= l) return inf;
    if (L <= l && r <= R) return t[v].mn;
    int m = (l+r)/2;
    return min(range_min(t[v].l, l, m, L, R),
            range_min(t[v].r, m, r, L, R));
}
void range_set(int v, int l, int r, int L, int R, int x) {
    pd(v);
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        t[v].buf = x;
        pd(v);
        return;
    }
    int m = (l+r)/2;
    range_set(get_l(v), l, m, L, R, x);
    range_set(get_r(v), m, r, L, R, x);
    t[v].mn = min(t[t[v].r].mn, t[t[v].l].mn);
}

void build_small(int v, int l, int r) {
    if (l == r-1) {
        t[v].mn = b[l];
        return;
    }
    int m = (l+r)/2;
    t[v].l = tree_sz++;
    t[v].r = tree_sz++;
    build_small(t[v].l, l, m);
    build_small(t[v].r, m, r);
    t[v].mn = min(t[t[v].l].mn, t[t[v].r].mn);
}

void build_large(int v, int l, int r) {
    if (r-l == N) {
        t[v] = t[0];
        return;
    }
    int m = (l+r)/2;
    t[v].l = tree_sz++;
    t[v].r = tree_sz++;
    build_large(t[v].l, l, m);
    build_large(t[v].r, m, r);
}


void solve() {
    cin >> n >> k;    
    N = next_p2(n), K = next_p2(k);
    b.resize(N, inf);
    for (int i = 0; i < n; i++) cin >> b[i];
    build_small(0, 0, N);
    int root = tree_sz++;
    build_large(root, 0, N*K);

    cin >> q;
    for (int i = 0; i < q; i++) {
        int tp, l, r; cin >> tp >> l >> r; l--;
        int L = l/n*N + (l%n);
        int R = r/n*N + (r%n);
        if (tp == 1) {
            int nv; cin >> nv;
            range_set(root, 0, N*K, L, R, nv);
        } else {
            cout << range_min(root, 0, N*K, L, R) << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

