#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

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
    int x, y, i, l, r, p;
    Item() {}
    Item(int x, int y, int i) : x(x), y(y), i(i), l(-1), r(-1), p(-1) {}
} t[100'000];

void solve() {
    int n; cin >> n;    
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        t[i] = Item(x, y, i);
    } 
    n++;
    t[n-1] = Item(69, -inf, n-1);
    sort(t, t+n-1, [&](const Item& a, const Item& b) { return a.x < b.x; });
    vi stk = {n-1};
    for (int i = 0; i < n-1; i++) {
        while (t[stk.back()].y > t[i].y) stk.pop_back();

        t[i].l = t[stk.back()].r;
        if (t[stk.back()].r != -1) t[t[stk.back()].r].p = i;

        t[stk.back()].r = i;
        t[i].p = stk.back();

        stk.pb(i);
    }

    cout << "YES\n";
    V<array<int, 3>> ans(n-1);
    for (int i = 0; i < n-1; i++) {
        int fa = t[i].p == -1 || t[i].p == n-1 ? -1 : t[t[i].p].i;
        int lc = t[i].l == -1 ? -1 : t[t[i].l].i;
        int rc = t[i].r == -1 ? -1 : t[t[i].r].i;
        ans[t[i].i] = {fa, lc, rc};
    }
    for (auto [fa, lc, rc] : ans) {
        cout << fa+1 << ' ' << lc+1 << ' ' << rc+1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
