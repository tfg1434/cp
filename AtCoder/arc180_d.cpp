#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

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

V<array<int, 3>> queries;
int q;

const int N = 5e5;

namespace MaxTreap {
struct Item {
    int y, l, r, siz, val, mx;
    Item() {}
    Item(int val) : y(rand()), l(-1), r(-1), siz(1), val(val), mx(val){}
} t[N];
int cur_node;
struct Treap {
    int root;
    int siz(int v) { return v == -1 ? 0 : t[v].siz; }
    int mx(int v) { return v == -1 ? 0 : t[v].mx; }
    void pull(int v) {
        if (v != -1) {
            t[v].siz = 1+siz(t[v].l)+siz(t[v].r);
            t[v].mx = max({ t[v].val, mx(t[v].l), mx(t[v].r) });
        } 
    }
    void merge(int& v, int l, int r) { 
        if (l == -1) return void(v=r);
        if (r == -1) return void(v=l);
        if (t[l].y < t[r].y) {
            merge(t[l].r, t[l].r, r);
            v = l;
        } else {
            merge(t[r].l, l, t[r].l);
            v = r;
        }
        pull(v);
    }
    void split(int v, int x, int& l, int& r) {
        if (v == -1) return void(l=r=-1);
        if (siz(t[v].l) < x) {
            split(t[v].r, x-1-siz(t[v].l), t[v].r, r);
            l = v;
        } else {
            split(t[v].l, x, l, t[v].l);
            r = v;
        }
        pull(v);
    }
    int range_max(int lq, int rq) {
        int A, B, C;
        split(root, rq, B, C);
        split(B, lq, A, B);
        auto res = mx(B); 
        merge(root, A, B);
        merge(root, root, C);
        return res;
    }
    Treap(const vi& a) {
        int n = a.size();
        root = cur_node++;
        t[root] = Item(a[0]);
        for (int i = 1; i < n; i++) {
            int u = cur_node++;
            t[u] = Item(a[i]);
            merge(root, root, u);
        }
    }
};
}

namespace MinTreap {
struct Item {
    int y, l, r, siz, val, mn, buf;
    Item() {}
    Item(int val) : y(rand()), l(-1), r(-1), siz(1), val(val), mn(val), buf() { }
    friend ostream& operator<<(ostream& out, const Item rhs) {
        out << rhs.val << ' ' << rhs.y << ' ' << rhs.siz << ' ' << rhs.mn << ' ' << rhs.buf; 
        return out;
    }
} t[N];
int cur_node;
struct Treap {
    int root;
    int siz(int v) { return v == -1 ? 0 : t[v].siz; }
    int mn(int v) { return v == -1 ? inf : t[v].mn; }
    void pull(int v) {
        if (v != -1) {
            t[v].siz = 1+siz(t[v].l)+siz(t[v].r);
            t[v].mn = min({ t[v].val, mn(t[v].l), mn(t[v].r) });
        } 
    }
    void push(int v) {
        if (v != -1 && t[v].buf) {
            t[v].val += t[v].buf;
            t[v].mn += t[v].buf;
            if (t[v].l != -1) t[t[v].l].buf += t[v].buf;
            if (t[v].r != -1) t[t[v].r].buf += t[v].buf;
            t[v].buf = 0;
        }
    }
    void print(int v) {
        if (v == -1) return;
        push(v);
        print(t[v].l);
        cout << t[v].val << ' ';
        print(t[v].r);
    }
    void dbg(int v, int add=0) {
        if (v == -1) return;
        dbg(t[v].l, add);
        dbg(t[v].r, add+siz(t[v].l)+1);
    }
    void merge(int& v, int l, int r) { 
        push(l);
        push(r);
        if (l == -1) return void(v=r);
        if (r == -1) return void(v=l);
        if (t[l].y < t[r].y) {
            merge(t[l].r, t[l].r, r);
            push(t[l].l);
            v = l;
        } else {
            merge(t[r].l, l, t[r].l);
            push(t[r].r);
            v = r;
        }
        pull(v);
    }
    void split(int v, int X, int& l, int& r) {
        if (v == -1) return void(l=r=-1);
        push(v);
        if (siz(t[v].l) < X) {
            split(t[v].r, X-siz(t[v].l)-1, t[v].r, r);
            push(t[v].l);
            l = v;
        } else {
            split(t[v].l, X, l, t[v].l);
            push(t[v].r);
            r = v;
        }
        pull(v);
    }
    int range_min(int lq, int rq) {
        if (lq >= rq) return inf;
        int A, B, C;
        split(root, rq, B, C);
        split(B, lq, A, B);
        auto res = mn(B); 
        merge(root, A, B);
        merge(root, root, C);
        return res;
    }
    void range_add(int lq, int rq, int d) {
        if (lq >= rq) return;
        int A, B, C;
        split(root, rq, B, C);
        split(B, lq, A, B);
        t[B].buf += d;
        merge(root, A, B);
        merge(root, root, C);
    }
    Treap(const vi& a) {
        int n = a.size();
        root = cur_node++;
        t[root] = Item(a[0]);
        for (int i = 1; i < n; i++) {
            int u = cur_node++;
            t[u] = Item(a[i]);
            merge(root, root, u);
        }
    }
};
};

vi solve_for(const vi& a) {
    int n = a.size();
    vi ans(q, inf);
    vi stk;
    for (int i = queries[0][0]-1; i >= 0; i--) {
        if (!stk.size() || a[i] > a[stk.back()]) stk.pb(i);
    }
    reverse(all(stk));

    auto mod = MinTreap::Treap(a);
    auto nop = MaxTreap::Treap(a);
    int prv = 0;
    for (int pos_mx : stk) {
        mod.range_add(prv, pos_mx, a[pos_mx]);
        prv = pos_mx;
    }

    for (int i = 0; i < q; i++) {
        auto [r, l, q_ind] = queries[i];

        // Case 1. Y contains the maximum value
        ckmin(ans[q_ind], a[l] + nop.range_max(l+1, r-1) + a[r-1]);
        // Case 2. Y doesn't contain max, Y is either sandwiched by max or on one side of all maxes
        // either way, we can do it. WLOG max is in X
        int mx = nop.range_max(l, r);
        ckmin(ans[q_ind], mx + mod.range_min(l+1, r-1));

        if (i+1 < q) {
            for (int j = r; j < queries[i+1][0]; j++) {
                while (stk.size() && a[stk.back()] <= a[j]) {
                    int pos_of_smaller = stk.back();
                    stk.pop_back();
                    mod.range_add(stk.size() ? stk.back() : 0, pos_of_smaller, -a[pos_of_smaller]);
                }
                mod.range_add(stk.size() ? stk.back() : 0, j, a[j]);
                stk.pb(j);
            }
        }
    }
    return ans;
}

void solve() {
    int n; cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    queries.resize(q);
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; l--;
        queries[i] = { r, l, i };
    }
    sort(all(queries));
    auto ans0 = solve_for(a);
    reverse(all(a));
    for (auto& [r, l, q_ind] : queries) {
        l = n-1-l;
        r--;
        r = n-1-r;
        swap(l, r);
        r++;
    }
    sort(all(queries));
    auto ans1 = solve_for(a);
    for (int i = 0; i < q; i++) 
        // cout << ans0[i] << ' ' << ans1[i] << ' ' << min(ans0[i], ans1[i]) << '\n';
        cout << min(ans0[i], ans1[i]) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
