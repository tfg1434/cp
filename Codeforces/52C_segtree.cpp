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
int t[4*N], buf[4*N];
void pull(int v) { t[v] = min(t[2*v+1],t[2*v+2]); }
void push(int v, int len) {
    if (!buf[v]) return;
    t[v] += buf[v];
    if (len > 1) {
        buf[2*v+1] += buf[v];
        buf[2*v+2] += buf[v];
    }
    buf[v] = 0;
}

void range_add(int L, int R, int x, int u=0, int l=0, int r=N) {
    push(u, r-l);
    if (r <= L || R <= l) return;
    if (L <= l && r <= R) {
        buf[u] = x;
        push(u, r-l);
        return;
    }
    int m = (l+r)/2;
    range_add(L, R, x, 2*u+1, l, m);
    range_add(L, R, x, 2*u+2, m, r);
    pull(u);
}
int range_min(int L, int R, int u=0, int l=0, int r=N) {
    push(u, r-l);
    if (r <= L || R <= l) return inf;
    if (L <= l && r <= R) return t[u];
    int m = (l+r)/2;
    int res = min(range_min(L, R, 2*u+1, l, m), range_min(L, R, 2*u+2, m, r));
    return res;
}




void solve() {
    srand(0);
    int n; cin >> n; 
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        range_add(i, i+1, a[i]);
    }
    int q; cin >> q;
    string _; getline(cin, _);
    while (q--) {
        string s; getline(cin, s);
        stringstream ss(s);
        vi data(3, inf);
        int k = 0;
        while (ss >> data[k++]) {}
        auto [l, r, v] = tie(data[0], data[1], data[2]);
        if (v == inf) {
            if (l <= r) {
                cout << range_min(l, r+1);
            } else {
                cout << min(range_min(l, n), range_min(0, r+1));
            }
            cout << '\n';

        } else {
            if (l <= r) {
                range_add(l, r+1, v);
            } else {
                range_add(l, n, v);
                range_add(0, r+1, v);
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
