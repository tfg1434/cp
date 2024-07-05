#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 2e18;

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
struct MinTreapItem {
    int x, y, l, r, siz, mn, buf;
    MinTreapItem() {}
    MinTreapItem(int x) : x(x), y(rand()), l(-1), r(-1), siz(1), mn(x), buf() { }
    friend ostream& operator<<(ostream& out, const MinTreapItem rhs) {
        out << rhs.x << ' ' << rhs.y << ' ' << rhs.siz << ' ' << rhs.mn << ' ' << rhs.buf; 
        return out;
    }
} t[N];
int cur_node;
struct MinTreap {
    int root;
    int siz(int v) { return v == -1 ? 0 : t[v].siz; }
    int mn(int v) { return v == -1 ? inf : t[v].mn; }
    void pull(int v) {
        if (v != -1) {
            t[v].siz = 1+siz(t[v].l)+siz(t[v].r);
            t[v].mn = min({ t[v].x, mn(t[v].l), mn(t[v].r) });
        } 
    }
    void push(int v) {
        if (v != -1 && t[v].buf) {
            t[v].x += t[v].buf;
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
        cout << t[v].x << ' ';
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
        int A, B, C;
        split(root, rq, B, C);
        split(B, lq, A, B);
        auto res = mn(B); 
        merge(root, A, B);
        merge(root, root, C);
        return res;
    }
    void range_add(int lq, int rq, int x) {
        int A, B, C;
        split(root, rq, B, C);
        split(B, lq, A, B);
        t[B].buf += x;
        merge(root, A, B);
        merge(root, root, C);
    }
    MinTreap(const vi& a) {
        int n = a.size();
        root = cur_node++;
        t[root] = MinTreapItem(a[0]);
        for (int i = 1; i < n; i++) {
            int u = cur_node++;
            t[u] = MinTreapItem(a[i]);
            merge(root, root, u);
        }
    }
};

void solve() {
    srand(0);
    int n; cin >> n; 
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    MinTreap tr(a);
    int q; cin >> q;
    string _; getline(cin, _);
    while (q--) {
        // tr.dbg(tr.root);
        string s; getline(cin, s);
        stringstream ss(s);
        vi data(3, inf);
        int k = 0;
        while (ss >> data[k++]) {}
        auto [l, r, v] = tie(data[0], data[1], data[2]);
        if (v == inf) {
            if (l <= r) {
                cout << tr.range_min(l, r+1);
            } else {
                cout << min(tr.range_min(l, n), tr.range_min(0, r+1));
            }
            cout << '\n';

        } else {
            if (l <= r) {
                tr.range_add(l, r+1, v);
            } else {
                tr.range_add(l, n, v);
                tr.range_add(0, r+1, v);
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
