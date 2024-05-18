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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

const int max_n = 1e5;
const int max_k = 30;
int k, n, m;
int nodes_sz;
const int tree_size = max_n*max_k*2;
struct node {
    int l, r, a;
    set<int> S;
    node() {
        a = 0;
        l = r = -1;
    }
} nodes[tree_size];

void extend(int v) {
    if (nodes[v].l == -1) {
        nodes[v].l = nodes_sz++; nodes[nodes[v].l] = node();
        nodes[v].r = nodes_sz++; nodes[nodes[v].r] = node();
    }
}
void paint(int v, int l, int r, int L, int R, int col) {
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        nodes[v].S.insert(col);
        return;
    }
    extend(v);
    int m = (l+r)/2;
    paint(2*v+1, l, m, L, R, col);
    paint(2*v+2, m, r, L, R, col);
}

void calc_dp(int v) {
    if (nodes[v].l != -1) {
        calc_dp(2*v+1); calc_dp(2*v+2);
        if (nodes[2*v+1].S.size() < nodes[2*v+2].S.size())
            swap(nodes[2*v+1].S, nodes[2*v+2].S);
        bool inter = !nodes[2*v+2].S.size();
        for (int col : nodes[2*v+2].S) 
            inter |= nodes[2*v+1].S.count(col);
        if (inter) {
            for (int col : nodes[2*v+2].S) if (nodes[2*v+1].S.count(col))
                nodes[v].S.insert(col);
            nodes[v].a = nodes[2*v+1].a + nodes[2*v+2].a;
        } else {
            for (int col : nodes[2*v+2].S) nodes[2*v+1].S.insert(col);
            swap(nodes[2*v+1].S, nodes[v].S);
            nodes[v].a = nodes[2*v+1].a + nodes[2*v+2].a + 1;
        }
    }
}

void solve() {
    cin >> k >> n >> m; 
    nodes[nodes_sz++] = node();
    int l = 0;
    for (int i = 0; i < n; i++) {
        int len, col; cin >> len >> col;
        paint(0, 0, tree_size, l, l+len, col);
        l += len;
    }
    calc_dp(0);
    cout << nodes[0].a+1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
