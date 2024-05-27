#include <bits/stdc++.h>
using namespace std;
#define int int64_t

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

int f(array<int, 2> line, int x) { return line[0]*x + line[1]; }
int n, q;
const int max_x = 1e9+1;
int tree_sz = 1;
struct node {
    array<int, 2> line;
    int l, r;
    node() {
        line = {0, 0};
        l = r = -1;
    }
} t[3'000'000];
void extend(int v) {
    if (t[v].l == -1) {
        t[v].l = tree_sz++;
        t[v].r = tree_sz++;
        t[t[v].l] = node();
        t[t[v].r] = node();
    }
}
void add_line(int v, int l, int r, array<int, 2> nw) {
    int m = (l+r)/2;
    bool lef = f(nw, l) > f(t[v].line, l);
    bool mid = f(nw, m) > f(t[v].line, m);
    if (mid) swap(nw, t[v].line);
    if (l < r-1) {
        extend(v);
        if (lef != mid) add_line(t[v].l, l, m, nw);
        else add_line(t[v].r, m, r, nw);
    }
}
int point_max(int v, int l, int r, int x) {
    int cand = f(t[v].line, x);
    if (l == r-1) return cand;
    int m = (l+r)/2;
    extend(v);
    if (x < m) return max(cand, point_max(t[v].l, l, m, x));
    return max(cand, point_max(t[v].r, m, r, x));
}

void solve() {
    cin >> n >> q;
    t[0] = node();
    add_line(0, -max_x, max_x, {0, 0});
    V<array<int, 2>> lines(n, {0, 0});

    while (q--) {
        int tp; cin >> tp;
        if (tp == 1) {
            int x0, ind, spd; cin >> x0 >> ind >> spd; ind--;
            int y0 = f(lines[ind], x0);
            lines[ind] = {spd, y0-spd*x0};
            add_line(0, -max_x, max_x, lines[ind]);

        } else {
            int x; cin >> x;
            cout << point_max(0, -max_x, max_x, x) << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
