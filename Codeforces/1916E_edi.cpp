    // LUOGU_RID: 141562818
    #include <bits/stdc++.h>
    using namespace std;
    using LL = long long;
    const int INF = 0x3f3f3f3f;
    const LL mod = 1e9 + 7;
    const int N = 300005;
     
    int val[N << 2], tag[N << 2];
    void build(int u, int l, int r) {
        val[u] = tag[u] = 0;
        if (l == r) return;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    }
    void push_up(int u) {
        val[u] = max(val[u << 1], val[u << 1 | 1]);
    }
    void push_down(int u) {
        if (tag[u]) {
            val[u << 1] += tag[u], val[u << 1 | 1] += tag[u];
            tag[u << 1] += tag[u], tag[u << 1 | 1] += tag[u];
            tag[u] = 0;
        }
    }
    void update(int u, int l, int r, int x, int y, int v) {
        if (x <= l && r <= y) {
            val[u] += v, tag[u] += v;
            return;
        }
        push_down(u);
        int mid = l + r >> 1;
        if (x <= mid) update(u << 1, l, mid, x, y, v);
        if (y > mid) update(u << 1 | 1, mid + 1, r, x, y, v);
        push_up(u);
    }
    int query(int u, int l, int r, int x, int y) {
        if (x <= l && r <= y) return val[u];
        push_down(u);
        int mid = l + r >> 1, res = 0;
        if (x <= mid) res = max(res, query(u << 1, l, mid, x, y));
        if (y > mid) res = max(res, query(u << 1 | 1, mid + 1, r, x, y));
        return res;
    }
     
    vector<int> G[N];
    vector<int> e[N];  // 下方最近的同色点
    int a[N], n;
    LL ans;
    int b[N];
    int dfn[N], out[N], ck;
    void dfs(int u) {
        dfn[u] = ++ck;
        if (b[a[u]]) e[b[a[u]]].push_back(u);
        int tmp = b[a[u]];
        b[a[u]] = u;
        for (auto v : G[u]) {
            dfs(v);
        }
        out[u] = ck;
        b[a[u]] = tmp;
        update(1, 1, n, dfn[u], out[u], 1);
        for (auto v : e[u]) update(1, 1, n, dfn[v], out[v], -1);
        int mx = 1;
        for (auto v : G[u]) {
            int t = query(1, 1, n, dfn[v], out[v]);
            ans = max(ans, (LL)t * mx);
            mx = max(mx, t);
        }
    }
    int main() {
        int _;
        scanf("%d", &_);
        while (_--) {
            scanf("%d", &n);
            for (int i = 1; i <= n; i++) G[i].clear(), e[i].clear();
            for (int i = 2, u; i <= n; i++) {
                scanf("%d", &u);
                G[u].push_back(i);
            }
            for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
            build(1, 1, n);
            ans = 1, ck = 0, dfs(1);
            for (int i = 1; i <= n; i++) {
                // for(auto v: e[i]) cout << v << ' '; cout << endl;
                cout << dfn[i] << ' ' << out[i] << endl;
            }
            printf("%lld\n", ans);
        }
        return 0;
    }
