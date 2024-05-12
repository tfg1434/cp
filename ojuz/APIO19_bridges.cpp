// WA and slow but I got the idea at least

#include <bits/stdc++.h>
using namespace std;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

struct dsu {
    vector<pair<int&, int>> undo;
    vector<int> par, siz;
    dsu(int n) : par(n), siz(n, 1) {
        iota(all(par), 0);
    }
    int find(int u) {
        return par[u] == u ? u : find(par[u]);
    }
    void unite(int u, int v) {
        if ((u=find(u)) != (v=find(v))) {
            if (siz[u] < siz[v]) swap(u, v);
            undo.push_back({siz[u], siz[u]});
            undo.push_back({par[v], par[v]});
            siz[u] += siz[v];
            par[v] = u;
        }
    }
    int snapshot() {
        return undo.size();
    }
    void rollback(int until) {
        while (undo.size() > until) {
            undo.back().first = undo.back().second;
            undo.pop_back();
        }
    }
};
const int K = 300;
int n, m, q;
vector<array<int, 3>> edges;
vector<int> cur_edge_w;
vector<int> sorted;

void solve() {
    cin >> n >> m;
    cur_edge_w.resize(m);
    for (int i = 0; i < m; i++) {
        int u, v, w; cin >> u >> v >> w; u--; v--;
        cur_edge_w[i] = w;
        edges.push_back({w, u, v});
    }
    sorted.resize(m); iota(all(sorted), 0);

    map<int, int> original_w;
    vector<array<int, 3>> events;
    auto answer_block = [&]() {
        vector<array<int, 3>> extra;
        for (auto [edge_ind, w] : original_w) if (w > edges[edge_ind][0]) {
            extra.push_back({1, edge_ind, w});
        }
        events.insert(begin(events), all(extra));

        sort(all(sorted), [&](int i, int j) {return edges[i] > edges[j];});
        dsu uf(n);
        // for (int i = 0; i < m; i++) cerr << edges[sorted[i]][0] << ' ' << edges[sorted[i]][1] <<' ' << edges[sorted[i]][2] << endl;

        vector<array<int, 4>> tp2_events; // thres, u, ind, local ind in tp2
        for (int i = 0; i < events.size(); i++) {
            auto [tp, p1, p2] = events[i];
            if (tp == 2) {
                tp2_events.push_back({p2, p1, i, (int)tp2_events.size()});
            }
        }
        sort(all(tp2_events));
        vector<int> ans(tp2_events.size());
        for (int i = 0; i <= m; i++) {
            int snap = uf.snapshot();
            while (tp2_events.size() && (i == m || tp2_events.back()[0] > edges[sorted[i]][0])) {
                auto [THRES, U, IND, TP2_IND] = tp2_events.back(); tp2_events.pop_back();
                set<int> new_edges;
                for (int j = 0; j < IND; j++) {
                    auto [tp, p1, p2] = events[j];
                    if (tp == 2) continue;
                    if (p2 >= THRES) new_edges.insert(p1);
                    else if (p2 < THRES && new_edges.count(p1)) new_edges.erase(p1);
                }
                for (auto edge_ind : new_edges) uf.unite(edges[edge_ind][1], edges[edge_ind][2]);

                ans[TP2_IND] = uf.siz[uf.find(U)];
            }
            uf.rollback(snap);

            // if (i < m) cerr << "unite " << edges[sorted[i]][1] << ' ' << edges[sorted[i]][2] << endl;
            if (i < m) uf.unite(edges[sorted[i]][1], edges[sorted[i]][2]);
        }

        for (int i = 0; i < ans.size(); i++) cout << ans[i] << '\n';
        events.clear();
        for (int i = 0; i < m; i++) edges[i][0] = cur_edge_w[i];
        original_w.clear();
    };

    cin >> q;
    for (int i = 0; i < q; i++) {
        if (i > 0 && i % K == 0) answer_block();
        int tp; cin >> tp;
        if (tp == 1) {
            int i, w; cin >> i >> w; i--;
            if (!original_w.count(i))
                original_w[i] = edges[i][0];
            edges[i][0] = min(edges[i][0], w);
            cur_edge_w[i] = w;
            events.push_back({1, i, w});
        } else {
            int u, w; cin >> u >> w; u--;
            events.push_back({2, u, w});
        }
    }
    answer_block();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
}
