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

constexpr int p2(int x) { return (int)1 << x; }

const int LOGX = 30, MAX_N = 2e5, MAX_NODES = 1e6;

struct Node {
    Node* sons[2];
    set<int> tins;
    Node() {
        sons[0] = sons[1] = NULL;
        tins = {};
    }
} *root = new Node();
int trie_siz = 1;

void add_str(int str, int time) {
    Node* u = root;
    for (int i = LOGX-1; i >= 0; i--) {
        u->tins.insert(time);
        bool nxt = str&p2(i);
        Node* c = u->sons[nxt];
        if (c != NULL) {
            u = c;
        } else {
            u->sons[nxt] = new Node();
            u = u->sons[nxt];
        }
    }
    u->tins.insert(time);
}

int best_match(int pattern, int l, int r) {
    int match = 0;
    Node* u = root;
    for (int i = LOGX-1; i >= 0; i--) {
        bool nxt = !(pattern & p2(i));
        Node* c = u->sons[nxt];
        if (c != NULL && c->tins.lb(l) != c->tins.end() && *c->tins.lb(l) < r) {
            u = u->sons[nxt];
            match += p2(i)*nxt;
        } else {
            u = u->sons[1-nxt];
            match += p2(i)*(1-nxt);
        }
    }
    return match;
}

int timer;
vi tin, tout, x;
V<V<array<int, 2>>> sons;
void dfs(int u) {
    tin[u] = timer++;
    for (auto [v, w] : sons[u]) {
        x[v] = x[u]^w;
        dfs(v);
    }
    tout[u] = timer;
}

void solve() {
    int q; cin >> q;
    int n = 1;

    V<array<int, 3>> queries;
    for (int i = 0; i < q; i++) {
        string typ; cin >> typ;
        if (typ == "Add") {
            int u, w; cin >> u >> w; u--;
            queries.pb({0, n, -1});
            sons.resize(n+1);
            sons[u].pb({n++, w});

        } else {
            int a, b; cin >> a >> b; a--; b--;
            queries.pb({1, a, b});
        }
    }

    tin.resize(n);
    tout.resize(n);
    x.resize(n);
    dfs(0);

    add_str(0, 0);
    for (int i = 0; i < q; i++) {
        if (queries[i][0] == 0) {
            auto [_, u, __] = queries[i];
            add_str(x[u], tin[u]);
        } else {
            auto [_, a, b] = queries[i];
            cout << (x[a]^best_match(x[a], tin[b], tout[b])) << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
