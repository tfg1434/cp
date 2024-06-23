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
template<class T> using pqg = priority_queue<T, V<T>, greater<T>>;

struct Ticket {
    int c, p, a, b;
    bool operator<(const Ticket& rhs) const { return a < rhs.a; }
};
int n, m;
V<Ticket> tickets;

struct SegmentTree {
    vi mx;
    void pull(int v) {
        mx[v] = max(mx[2*v+1], mx[2*v+2]);
    }
    void build(int v, int l, int r) {
        if (l == r-1) {
            mx[v] = tickets[l].b;
            return;
        }
        int m = (l+r)/2;
        build(2*v+1, l, m);
        build(2*v+2, m, r);
        pull(v);
    }
    void remove(int v, int l, int r, int i, vi& removed) {
        if (i < tickets[l].a || mx[v] < i) return;
        if (l == r-1) {
            mx[v] = -1;
            removed.pb(l);
            return;
        }
        int m = (l+r)/2;
        remove(2*v+1, l, m, i, removed);
        remove(2*v+2, m, r, i, removed);
        pull(v);
    }
    SegmentTree() {
        int size = 1;
        while (size < 2*m) size *= 2;
        mx.resize(size, -1);
        build(0, 0, m);
    }
};

void dij(vi& dist) {
    pqg<array<int, 2>> q;
    for (int i = n; i < n+m; i++) {
        ckmin(dist[tickets[i-n].c], dist[i]+tickets[i-n].p);
    }
    for (int i = 0; i < n; i++) if (dist[i] < inf) q.push({dist[i], i});
    SegmentTree tr;
    while (q.size()) {
        auto [d, u] = q.top(); q.pop();
        if (d != dist[u]) continue;
        vi removed; tr.remove(0, 0, m, u, removed);
        for (int t_ind : removed) {
            if (ckmin(dist[t_ind+n], d)) {
                if (ckmin(dist[tickets[t_ind].c], d+tickets[t_ind].p)) {
                    q.push({dist[tickets[t_ind].c], tickets[t_ind].c});
                }
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    tickets.resize(m);
    for (int i = 0; i < m; i++) {
        int c, p, a, b; cin >> c >> p >> a >> b; c--; a--; b--;
        tickets[i] = {c, p, a, b};
    }
    sort(all(tickets));

    V<vi> dist(2, vi(n+m, inf));
    dist[0][0] = 0; dij(dist[0]);
    dist[1][n-1] = 0; dij(dist[1]);
    vi f(n+m);
    for (int i = 0; i < n+m; i++) f[i] = dist[0][i]+dist[1][i];
    dij(f);
    for (int i = 0; i < n; i++) {
        if (f[i] >= inf) f[i] = -1;
        cout << f[i] << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
