#include <bits/stdc++.h>
using namespace std;

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

const int N = 2e5;
struct Treap {
    struct Item {
        char x;
        int y, siz;
        int l, r;
        Item() {}
        Item(char x) : x(x), y(rand()), l(-1), r(-1), siz(1){ }
    } t[N];
    int root, cur_node;
    int z(int v) { return v == -1 ? 0 : t[v].siz; }
    void pull(int v) {
        if (v != -1) t[v].siz = 1+z(t[v].l)+z(t[v].r);
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
    void split(int v, int X, int& l, int& r) {
        if (v == -1) return void(l=r=-1);
        if (z(t[v].l) < X) {
            split(t[v].r, X-z(t[v].l)-1, t[v].r, r);
            l = v;
        } else {
            split(t[v].l, X, l, t[v].l);
            r = v;
        }
        pull(v);
    }
    void cut_paste(int l, int r) {
        int A, B, C;
        split(root, r, B, C);
        split(B, l, A, B);
        merge(root, A, C);
        merge(root, root, B);
    }
    void print(int v) {
        if (v == -1) return;
        print(t[v].l);
        cout << t[v].x;
        print(t[v].r);
    }
    Treap(const string& a) {
        int n = a.size();
        root = 0;
        t[0] = Item(a[0]);
        cur_node = 1;
        for (int i = 1; i < n; i++) {
            int u = cur_node++;
            t[u] = Item(a[i]);
            merge(root, root, u);
        }
    }
};

void solve() {
    int n, q; cin >> n >> q;
    string s; cin >> s;
    Treap treap(s);
    while (q--) {
        int l, r; cin >> l >> r; l--;
        treap.cut_paste(l, r);
    }
    treap.print(treap.root);
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}


