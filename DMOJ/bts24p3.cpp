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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int n;
V<array<int, 2>> t;
array<int, 2> merge(array<int, 2> a, array<int, 2> b) {
    return {max(a[0], b[0]), a[1]+b[1]+(a[0]-b[0])*(a[0]-b[0])};
}
void pull(int u) {
    t[u] = merge(t[2*u+1], t[2*u+2]);
}
void init_tree() {
    int siz = 1;
    while (siz < 2*n) siz *= 2;
    t.resize(siz);
}
void point_set(int pos, int val, int u=0, int l=0, int r=n) {
    if (l == r-1) {
        t[u] = {val, 0};
        return;
    }
    int m = (l+r)/2;
    if (pos < m) point_set(pos, val, 2*u+1, l, m);
    else point_set(pos, val, 2*u+2, m, r);
    pull(u);
}

void solve() {
    cin >> n;
    V<bool> seen(n);
    vi a(n-1);
    for (int &i : a) {
        cin >> i, i--;
        seen[i] = true;
    }
    int missing = 0;
    for (; missing < n; missing++) if (!seen[missing]) break;
    a.insert(a.begin(), missing);
    init_tree();
    for (int i = 0; i < n; i++) {
        point_set(i, a[i]);
    }
    cout << t[0][1] << ' ';
    for (int i = 0; i+1 < n; i++) {
        point_set(i+1, a[i]);
        point_set(i, a[i+1]);
        swap(a[i], a[i+1]);
        cout << t[0][1] << " \n"[i+1==n-1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
