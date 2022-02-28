#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

constexpr int max_nm = 2*1e5+1;
int edges[max_nm];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int dead = 0;
    memset(edges, 0, sizeof edges);
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);

        //u < v
        if (!edges[u]) dead++;
        edges[u]++;
    }

    int q; cin >> q;
    for (int i = 0; i < q; i++) {
        int type; cin >> type;

        if (type == 3) {
            cout << n - dead << '\n';
            continue;
        }

        int u, v; cin >> u >> v;
        if (u > v) swap(u, v);
        //1 = add, 2 = remove
        if (type == 1) {
            if (edges[u] == 0) dead++;
            edges[u]++;
        } else {
            edges[u]--;
            if (edges[u] == 0) dead--;
        }
    }
    
    return 0;
}

