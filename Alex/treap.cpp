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

struct Item {
    int x, y, l, r, siz, p;
    Item() {}
    Item(int x) : x(x), y(rand()), l(-1), r(-1), siz(1), p(-1) {}
} t[100'000];
int cur_node;

int siz(int v) { return v == -1 ? 0 : t[v].siz; }
void pull(int v) { 
    if (v != -1) {
        t[v] = 1+siz(t[v].l)+siz(t[v].r);
    }
}
void split(int v, int x, int& l, int& r) {
    if (v == -1) {
        l = r = -1;
        return;
    }
    if (t[v].x < x) {
        split(t[v].r, x, t[v].r, r);
        l = v;
    } else {
        split(t[v].l, x, l, t[v].l);
        r = v;
    }
    pull(v);
}
void merge(int& v, int l, int r) {
    if (l == -1) return (void)(v = r);
    if (r == -1) return (void)(v = l);
    if (t[l].y < t[r].y) {
        merge(t[l].r, t[l].r, r);
        v = l;
    } else {
        merge(t[r].l, l, t[r].l);
        v = r;
    }
    pull(v);
}
// void fast_erase(int v, int x) {
    // if (t[v].x == x) {
        // merge(v, t[v].l, t[v].r);
        // return;
    // }
    // fast_erase(x < t[v].x ? t[v].l : t[v].r, x);
// }
// void fast_insert(int& v, const Item& item) {
    // if (v == -1) {
        // t[v=cur_node] = item;
        // cur_node++;
        // return;
    // }
    // if (t[v].y >= item.y) {
        // Item new_node = item;
        // split(v, new_node.x, new_node.l, new_node.r);
        // t[v] = new_node;
        // return;
    // }
    // fast_insert(item.x < t[v].x ? t[v].l : t[v].r, item);
// }
// int unite(int l, int r) {
    // if (l == -1) return r;
    // if (r == -1) return l;
    // if (t[l].y > t[r].y) swap(l, r);
    // int lt, rt;
    // split(r, t[l].x, lt, rt);
    // t[l].l = unite(t[l].l, lt);
    // t[l].r = unite(t[l].r, rt);
    // return l;
// }

// void heapify(int v) {
    // if (v == -1) return;
    // int mn = v;
    // if (t[v].l != -1 && t[t[v].l].y < t[mn].y) {
        // mn = t[v].l;
    // } 
    // if (t[v].r != -1 && t[t[v].r].y < t[mn].y) {
        // mn = t[v].r;
    // }
    // if (mn != v) {
        // swap(t[v].y, t[mn].y);
        // heapify(mn);
    // }
// }
// int build(int l, int r, const vi& a) {
    // if (l == r) return;
    // int m = (l+r)/2;
    // int v = cur_node++;
    // t[v] = Item(a[m]);
    // t[v].l = build(0, m, a);
    // t[v].r = build(m, r, a);
    // heapify(v);
    // pull(v);
    // return v;
// }

int n;

void connect(bool forward) {
    vi s;
    for (int i = forward ? 0 : n-1; forward ? i < n : i >= 0; forward ? i++ : i--) {
        while (s.size() && t[i].y < t[s.back()].y) {
            s.pop_back();
        }
        if (s.size() && (t[i].p == -1 || t[s.back()].y > t[t[i].p].y)) {
            t[i].p = s.back();
        }
        s.pb(i);
    }
}

void solve() {
    cin >> n;    
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        t[i] = Item(x);
        t[i].y = y;
    }
    connect(true);
    connect(false);
    int no_par = 0;
    for (int i = 0; i < n; i++) {
        if (t[i].p != -1) {
            if (t[t[i].p].x > t[i].x) {
                t[t[i].p].l = i;
            } else {
                t[t[i].p].r = i;
            }
        } else {
            no_par++;
        }
    }
    if (no_par > 1) {
        cout << "NO\n";
        return;
    }

    cout << "YES\n";
    // int root = nodes[min_element(all(a))-a.begin()];
    vi fa(n, -1), lc(n, -1), rc(n, -1);
    for (int i = 0; i < n; i++) {
        fa[i] = t[i].p;
        lc[i] = t[i].l;
        rc[i] = t[i].r;
        cout << fa[i]+1 << ' ' << lc[i]+1 << ' ' << rc[i]+1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
