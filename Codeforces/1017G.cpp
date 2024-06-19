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

const int N = 1e5, B = 300;
int push[N];
bool used[N], is_black[N], old_is_black[N], clear[N];
V<array<int, 3>> SONS[N];
vi sons[N];


void dfs1(int u, int prv, int white, int dist) {
    if (used[u]) {
        if (prv != -1) {
            SONS[prv].pb({u, white, dist});
        }
        for (int v : sons[u]) {
            dfs1(v, u, 0, 0);
        }
    } else {
        for (int v : sons[u]) {
            dfs1(v, prv, white+!is_black[u], dist+1);
        }
    }
}
void black_op(int u) {
    if (!is_black[u]) {
        is_black[u] = true;
    } else {
        push[u]++;
        for (auto [v, white, dist] : SONS[u]) {
            if (push[u] >= white+1) {
                black_op(v);
            }
        }
    }
}
void white_op(int u) {
    is_black[u] = false;
    clear[u] = true;
    push[u] = 0;
    for (auto& [v, white, dist] : SONS[u]) {
        white = dist;
        white_op(v);
    }
}
void dfs2(int u, int b, bool cl) {
    if (used[u]) {
        b = push[u];
        cl |= clear[u];
    } else {
        is_black[u] = old_is_black[u];
        if (cl) {
            is_black[u] = false;
        }
        if (!is_black[u] && b > 0) {
            is_black[u] = true;
            b--;
        }
    }
    for (int v : sons[u]) {
        dfs2(v, b, cl);
    }
}

void solve() {
    int n, q; cin >> n >> q;
    for (int i = 0; i < n-1; i++) {
        int p; cin >> p; p--;
        sons[p].pb(i+1);
    }
    vi tp(q), v(q);
    for (int i = 0; i < q; i++) cin >> tp[i] >> v[i], v[i]--;

    for (int i = 0; i < q; i += B) {
        fill(all(push), 0);
        fill(all(used), false);
        fill(all(clear), false);
        for (int j = 0; j < n; j++) {
            old_is_black[j] = is_black[j];
            SONS[j].clear();
        }

        for (int j = i; j < min(i+B, q); j++) {
            used[v[j]] = true;
        }
        dfs1(0, -1, 0, 0);

        for (int j = i; j < min(i+B, q); j++) {
            if (tp[j] == 1) {
                black_op(v[j]);
            } else if (tp[j] == 2) {
                white_op(v[j]);
            } else {
                cout << (is_black[v[j]] ? "black" : "white") << '\n';
            }
        }
        dfs2(0, 0, false);
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
