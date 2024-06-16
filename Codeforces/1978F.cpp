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

const int MAX = 1e6;
int sp[MAX+1];
int where[MAX+1];
void sieve() {
    for (int i = 2; i <= MAX; i += 2) sp[i] = 2;
    for (int i = 3; i <= MAX; i += 2) if (!sp[i]) {
        for (int j = i; j <= MAX; j += i) sp[j] = i;
    }
}
vi pfs(int a) {
    vi res;
    while (a > 1) {
        res.pb(sp[a]);
        a /= sp[a];
    }
    return res;
}

struct Dsu {
    int n, ccs;
    vi e;
    Dsu() {}
    Dsu(int n) : n{n}, ccs{n}, e(n, -1) {}
    int find(int u) {
        return e[u] < 0 ? u : e[u]=find(e[u]);
    }
    void unite(int u, int v) {
        if ((u=find(u)) != (v=find(v))) {
            if (e[u] > e[v]) swap(u, v);
            e[u] += e[v];
            e[v] = u;
            ccs--;
        }
    }
};

void solve() {
    int n, k; cin >> n >> k;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    a.insert(a.begin(), a.begin()+1, a.end()); n += n-1;
    for (int i = 0; i < n; i++) for (int p : pfs(a[i])) where[p] = -1;

    Dsu dsu(n);
    for (int i = 0; i < n; i++) {
        for (int p : pfs(a[i])) {
            if (where[p] != -1) dsu.unite(i, where[p]);
            where[p] = i;
        }

        if (i >= k) {
            for (int p : pfs(a[i-k])) {
                if (where[p] == i-k) where[p] = -1;
            }
        }
    }

    int64_t ans = dsu.ccs;
    for (int i = 0; i < n; i++) {
        int sz = min(i+1, n-i);
        if (a[i] == 1) ans += sz-1;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    sieve();
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

