// WA on test 4

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
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int n, m;
vi h;

struct info {
    int pre, suf, mid;
    bool all;
    info() {
        pre=suf=mid=0;
        all = false;
    }
    info(int pre, int suf, int mid, bool all) {
        this->pre = pre; this->suf = suf;
        this->mid = mid; this->all = all;
    }
};
info merge_info(const info& a, const info& b) {
    auto res = info(a.pre+b.pre*a.all, b.suf+a.suf*b.all, 69, a.all && b.all);
    res.mid = max({ res.pre, res.suf, a.mid, b.mid, a.suf+b.pre });
    return res;
}
struct node {
    int l, r;
    info i;
    node() {
        l = r = -1;
        i = info();
    }
} t[2'000'000];
int tree_sz = 1;
void build(int v, int l, int r) {
    if (l == r-1) {
        return;
    }
    int m = (l+r)/2;
    t[v].l = tree_sz++;
    t[v].r = tree_sz++;
    build(t[v].l, l, m);
    build(t[v].r, m, r);
}
info longest_segment(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return info();
    if (L <= l && r <= R) return t[v].i;
    int m = (l+r)/2;
    return merge_info(longest_segment(t[v].l, l, m, L, R),
                      longest_segment(t[v].r, m, r, L, R));
}
int get_l(int v) {
    t[tree_sz] = t[t[v].l];
    t[v].l = tree_sz++;
    return t[v].l;
}
int get_r(int v) {
    t[tree_sz] = t[t[v].r];
    t[v].r = tree_sz++;
    return t[v].r;
}
void put_x(int v, int l, int r, int i) {
    if (l == r-1) {
        t[v].i = info(1, 1, 1, true);
        return;
    }
    int m = (l+r)/2;
    if (i < m) put_x(get_l(v), l, m, i);
    else put_x(get_r(v), m, r, i);
    t[v].i = merge_info(t[t[v].l].i, t[t[v].r].i); 
}

void solve() {
    cin >> n;    
    h.resize(n);
    map<int, vi> WHERE;
    for (int i = 0; i < n; i++) {
        cin >> h[i];
        WHERE[h[i]].pb(i);
    }
    V<pair<int, vi>> where;
    for (auto it = rbegin(WHERE); it != rend(WHERE); it++)
        where.pb({ it->f, it->s });

    build(0, 0, n);
    vi roots(where.size()+1);
    for (int i = 0; i < where.size(); i++) {
        auto [height, positions] = where[i];
        roots[i+1] = tree_sz++;
        t[roots[i+1]] = t[roots[i]];
        for (int pos : positions) {
            put_x(roots[i+1], 0, n, pos);
        }
    }

    cin >> m;
    while (m--) {
        int l, r, w; cin >> l >> r >> w; l--;
        int lo = 0, hi = where.size();
        while (hi-lo > 1) {
            int mid = (lo+hi)/2;
            bool res = longest_segment(roots[mid], 0, n, 0, n).mid < w;
            res ? lo = mid : hi = mid;
        }
        cout << where[lo].f << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
