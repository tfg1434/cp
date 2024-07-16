// how to find PRV in O(n)?

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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

const int N = 5e5, LOG = 19;
struct Node {
    int y, l, r, siz, sms;
    Node() {}
    Node(int y) : y(y), l(-1), r(-1), siz(1), sms(y) {}
} t[N+LOG*N];
int tree_siz;

struct Treap {
    int root;
    int siz(int v) { return v == -1 ? 0 : t[v].siz; }
    int sms(int v) { return v == -1 ? 0 : t[v].sms; }
    void pull(int v) {
        if (v != -1) {
            t[v].siz = 1+siz(t[v].l)+siz(t[v].r);
            t[v].sms = t[v].y*(siz(t[v].l)+1)*(siz(t[v].r)+1) + sms(t[v].l) + sms(t[v].r);
        } 
    }
    void print(int v) {
        if (v == -1) return;
        print(t[v].l);
        cout << t[v].y << ' ';
        print(t[v].r);
    }
    void dbg(int v, int add=0) {
        if (v == -1) return;
        dbg(t[v].l, add);
        dbg(t[v].r, add+siz(t[v].l)+1);
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
        if (siz(t[v].l) < X) {
            split(t[v].r, X-siz(t[v].l)-1, t[v].r, r);
            l = v;
        } else {
            split(t[v].l, X, l, t[v].l);
            r = v;
        }
        pull(v);
    }
void fast_erase(int& v, int x) {
    int A, B, C;
    split(v, x, A, B);
    split(B, 1, B, C);
    // print(A); ps();
    // print(B); ps();
    merge(v, A, C);
}
void fast_insert(int& v, int x, int y) {
    int A, B;
    split(v, x, A, B);
    int u = tree_siz++;
    t[u] = Node(y);
    merge(A, A, u);
    merge(v, A, B);
}
    Treap(const vi& a) {
        int n = a.size();
        root = tree_siz++;
        t[root] = Node(a[0]);
        for (int i = 1; i < n; i++) {
            int u = tree_siz++;
            t[u] = Node(a[i]);
            merge(root, root, u);
        }
    }
};

void solve() {
    int n; cin >> n;
    vi p(n);
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;

    Treap tr(p);

    // 3 1 0 4 2
    vi ans(n);
    for (int i = 0; i < n; i++) {
        tr.print(tr.root); ps();
        // ps("erase", i);
        tr.fast_erase(tr.root, i);
        tr.print(tr.root); ps();
        ans[i] = tr.sms(tr.root);
        // ps("replace", i);
        tr.fast_insert(tr.root, i, p[i]);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i==n-1];
    }

    while (tree_siz > 0) {
        tree_siz--;
        t[tree_siz] = Node(); // necessary?
    }
}

signed main() {
    srand(0);
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

