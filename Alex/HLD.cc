#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define int int64_t

const int inf = 2e9;

int n;
vector<vector<pair<int, int>>> g;
vector<int> sz;
vector<int> hr;
vector<int> in, out;
vector<int> euler;
vector<int> par;
vector<int> par_edge_ind;
vector<int> vertex_by_edge;
vector<int> w;
int cur_timer = 0;

struct node_info {
    int mx;
    node_info() {
        mx = -inf;
    }
    node_info(int a) {
        mx = a;
    }
};

node_info my_merge(const node_info& a, const node_info& b) {
    return node_info(max(a.mx, b.mx));
}

vector<node_info> t;

void upd(int v) {
    t[v] = my_merge(t[2 * v + 1], t[2 * v + 2]);
}

void build_tree(int v, int l, int r) {
    if (l == r - 1) {
        t[v] = node_info(w[par_edge_ind[euler[l]]]);
        return;
    }
    int mid = (l + r) / 2;
    build_tree(2 * v + 1, l, mid);
    build_tree(2 * v + 2, mid, r);
    upd(v);
}

node_info seg_query(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) {
        return node_info();
    }
    if (L <= l && r <= R) {
        return t[v];
    }
    int mid = (l + r) / 2;
    return my_merge(seg_query(2 * v + 1, l, mid, L, R),
                    seg_query(2 * v + 2, mid, r, L, R));
}

void set_elem(int v, int l, int r, int i, int x) {
    if (l == r - 1) {
        t[v] = node_info(x);
        return;
    }
    int mid = (l + r) / 2;
    if (i < mid) {
        set_elem(2 * v + 1, l, mid, i, x);
    } else {
        set_elem(2 * v + 2, mid, r, i, x);
    }
    upd(v);
}

void find_sz(int v, int p) {
    for (auto to_ind: g[v]) {
        int to = to_ind.first, ind = to_ind.second;
        if (to == p) {
            continue;
        }
        find_sz(to, v);
        sz[v] += sz[to];
    }
}

void init_hld(int v, int p) {
    euler[cur_timer] = v;
    in[v] = cur_timer++;
    int heavy = -1;
    for (auto to_ind: g[v]) {
        int to = to_ind.first, ind = to_ind.second;
        if (to == p) {
            continue;
        }
        par[to] = v;
        par_edge_ind[to] = ind;
        vertex_by_edge[ind] = to;
        if (sz[to] * 2 >= sz[v] && v != 0) {
            heavy = to;
            hr[to] = hr[v];
            init_hld(to, v);
        }
    }
    for (auto to_ind: g[v]) {
        int to = to_ind.first, ind = to_ind.second;
        if (to == p) {
            continue;
        }
        if (to != heavy) {
            hr[to] = to;
            init_hld(to, v);
        }
    }
    out[v] = cur_timer;
}

bool is_above(int a, int b) {
    return in[a] <= in[b] && out[b] <= out[a];
}

node_info vertical_path_query(int a, int b) {
    node_info res;
    while (a != b && a != 0) {
        if (is_above(hr[a], b)) {
            res = my_merge(res, seg_query(0, 1, n, in[b] + 1, in[a] + 1));
            break;
        }
        res = my_merge(res, seg_query(0, 1, n, in[hr[a]], in[a] + 1));
        a = par[hr[a]];
    }
    return res;
}

node_info reverse_info(const node_info& a) {
    return node_info(a.mx);
}

node_info path_query(int a, int b) {
    int lca1 = a;
    while (!is_above(lca1, b)) {
        lca1 = par[hr[lca1]];
    }
    int lca2 = b;
    while (!is_above(lca2, a)) {
        lca2 = par[hr[lca2]];
    }
    int lca = lca1;
    if (is_above(lca1, lca2)) {
        lca = lca2;
    }
    return my_merge(vertical_path_query(a, lca), reverse_info(vertical_path_query(b, lca)));
}

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> n;
    n++;
    g.resize(n);
    g[0].push_back({1, 0});
    g[1].push_back({0, 0});
    w.assign(n - 1, -inf);
    for (int i = 1; i < n - 1; i++) {
        int a, b;
        cin >> a >> b >> w[i];
        g[a].push_back({b, i});
        g[b].push_back({a, i});
    }
    sz.assign(n, 1);
    hr.assign(n, 0);
    in.resize(n);
    out.resize(n);
    euler.resize(n);
    par.assign(n, -1);
    par_edge_ind.assign(n, -1);
    vertex_by_edge.assign(n - 1, -1);
    find_sz(0, -1);
    init_hld(0, -1);

    int tree_sz = 1;
    while (tree_sz < 2 * n) {
        tree_sz *= 2;
    }
    t.resize(tree_sz);
    build_tree(0, 1, n);

    int q;
    cin >> q;
    while (q--) {
        int tp;
        cin >> tp;
        if (tp == 2) { // change
            int ind, x;
            cin >> ind >> x;
            w[ind] = x;
            set_elem(0, 1, n, in[vertex_by_edge[ind]], x);
        } else {
            int a, b;
            cin >> a >> b;
            cout << path_query(a, b).mx << '\n';
            cout.flush();
        }
    }
}

