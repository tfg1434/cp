// some WA

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

int n, m;
queue<array<int, 2>> to_merge;
const int max_n = 1e5;
int e[max_n], ans;
set<int> C[max_n], g[max_n], gr[max_n];

int dsu_size(int A) { return C[A].size() + g[A].size() + gr[A].size(); }
int find(int u) { return e[u] < 0 ? u : e[u]=find(e[u]); }
void weak_connect(int A, int B) {
    // if (A == B) return;
    g[A].insert(B); gr[B].insert(A);
    if (g[B].count(A)) to_merge.push({A, B});
}
void onion(int A, int B) {
    if (A == B) return;
    if (dsu_size(A) < dsu_size(B)) swap(A, B);
    ans += -e[A]*C[B].size() + -e[B]*C[A].size();
    e[A] += e[B];
    e[B] = A;
    for (int b : C[B]) {
        if (C[A].count(b)) ans += e[A];
        else C[A].insert(b);
    }
    g[A].erase(B), gr[B].erase(A);
    g[B].erase(A), gr[A].erase(B);
    for (int b : g[B]) {
        gr[b].erase(B);
        weak_connect(A, b);
    }
    for (int b : gr[B]) {
        g[b].erase(B);
        weak_connect(b, A);
    }
}

void solve() {
    cin >> n >> m; 
    memset(e, -1, sizeof e);
    for (int i = 0; i < n; i++) C[i].insert(i);
    while (m--) {
        int u, v; cin >> u >> v; u--; v--;
        if (find(u) != find(v) && !C[find(v)].count(u)) {
            C[find(v)].insert(u);
            ans -= e[find(v)];
            weak_connect(find(u), find(v));
            while (to_merge.size()) {
                onion(find(to_merge.front()[0]), find(to_merge.front()[1]));
                to_merge.pop();
            }
        }
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
