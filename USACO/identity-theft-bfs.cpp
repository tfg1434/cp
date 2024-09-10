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
#define len(x) (int)((x).size())
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

int n, cost;
struct Node {
    array<int, 2> c;
    int dep;
    bool is_used;
};
V<Node> tr(2);
int cur_node = 1;
bool is_leaf(int u) {
    return !tr[u].c[0] && !tr[u].c[1];
}

void bfs_for_leaf(int u, int k) {
    array<queue<int>, 2> q;
    q[0].push(u);
    auto use_used_leaf = [&]() {
        int used_leaf = q[1].ft; q[1].pop();
        cost += tr[used_leaf].dep-tr[u].dep + 2;
        for (int i = 0; i < 2; i++) {
            tr[used_leaf].c[i] = ++cur_node;
            tr.emplace_back();
            tr[cur_node].is_used = true;
            tr[cur_node].dep = tr[used_leaf].dep+1;
            q[1].push(cur_node);
        }
    };
    while (!q[0].empty()) {
        int v = q[0].ft; q[0].pop();
        while (q[1].size() && tr[q[1].ft].dep+2 <= tr[v].dep) { // if it is <, it is WRONG!!
            use_used_leaf();
            if (!(--k)) return;
        }

        if (is_leaf(v)) {
            if (tr[v].is_used) {
                q[1].push(v);
            } else {
                cost += tr[v].dep - tr[u].dep;
                tr[v].is_used = true;
                q[1].push(v);
                if (!(--k)) return;
            }
        } else {
            for (int i = 0; i < 2; i++) if (tr[v].c[i]) {
                q[0].push(tr[v].c[i]);
            }
        }
    }
    while (k) {
        k--;
        use_used_leaf();
    }
    assert(!k);
}

void solve() {
    cin >> n;
    map<string, int> tmp;
    for (int i = 0; i < n; i++) {
        string s; cin >> s; tmp[s]++;
    }
    V<pair<string, int>> strs(all(tmp));
    sort(all(strs), [&](pair<string, int> a, pair<string, int> b) { return len(a.f) > len(b.f); });
    for (auto [s, k] : strs) {
        int cur = 1;
        for (char c : s) {
            for (int i = 0; i < 2; i++) {
                if (!tr[cur].c[i]) {
                    tr[cur].c[i] = ++cur_node;
                    tr.emplace_back();
                    tr[cur_node].dep = tr[cur].dep+1;
                }
            }
            cur = tr[cur].c[c-'0'];
        }
        bfs_for_leaf(cur, k);
    }
    cout << cost << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

