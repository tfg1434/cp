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

const int MAX_NODES = 5e5;

int e[MAX_NODES];
void make_set(int u, int siz) {
    e[u] = -siz;
}
int find(int u) {
    return e[u] < 0 ? u : e[u]=find(e[u]);
};
void unite(int u, int v) {
    if ((u=find(u)) != (v=find(v))) {
        e[u] += e[v];
        e[v] = u;
    }
}

const int MAX = 2e5+1;
vi at[MAX+1];
V<array<int, 3>> nodes[MAX+2];


void solve() {
    memset(e, -1, sizeof e);

    int n; cin >> n;   
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y; y++;
        at[y].pb(x);
    }

    int cur_node = 0;
    make_set(cur_node, MAX+3);
    nodes[MAX+1].pb({-1, MAX+2, cur_node++});
    for (int y = MAX; y >= 0; y--) {
        int m = at[y].size();
        if (!m) {
            make_set(cur_node, MAX+3);
            nodes[y].pb({-1, MAX+2, cur_node++});
            continue;
        }
        sort(all(at[y]));
        make_set(cur_node, at[y][0]+1);
        nodes[y].pb({ -1, at[y][0], cur_node++ });

        int cur_x = at[y][0];
        int i = 0;
        while (i < m) {
            while (i < m && at[y][i] == cur_x) {
                cur_x++;
                i++;
            }
            int next_black_x = i < m ? at[y][i] : MAX+2;
            make_set(cur_node, next_black_x-cur_x);
            nodes[y].pb({cur_x, next_black_x, cur_node++});
            cur_x = next_black_x;
        }
    }

    for (int y = MAX; y >= 0; y--) {
        V<array<int, 4>> events; // x, typ, node ind, above=1 or below=0
        for (auto [l, r, ind] : nodes[y]) {
            events.pb({l, 1, ind, 0});
            events.pb({r, 0, ind, 0});
        }
        for (auto [l, r, ind] : nodes[y+1]) {
            events.pb({l, 1, ind, 1});
            events.pb({r, 0, ind, 1});
        }
        sort(all(events));

        vi cur_node(2, -1); // cur_node[1] = current upper node
        for (auto [x, typ, ind, is_above] : events) {
            if (typ == 1) {
                if (cur_node[!is_above] != -1) {
                    unite(cur_node[!is_above], ind);
                }
                cur_node[is_above] = ind;
            }
            if (typ == 0) {
                cur_node[is_above] = -1;
            }
        }
    }

    int ans = 0;
    for (int i = 1; i < cur_node; i++) if (find(i) == i && find(i) != find(0)) {
        ans += -e[i];
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
