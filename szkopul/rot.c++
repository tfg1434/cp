// I thought this would work, but then realised you can't easily write a segtree
// that supports find-by-order with only values on a tin-tout segment

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t

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

int n;
const int max_n = 4e5;
int l[max_n], r[max_n];
int nodes_sz;
set<int> sub[max_n];
int invs[max_n];
int a[max_n];

vi t;
void point_add(int v, int l, int r, int i) {

}
void order_of_key(int v, int l, int r, int L)
void init_tree() {
    int size = 1;
    while (size < 2*max_n) size *= 2;
    t.resize(size);
}

int timer;
int tin[max_n], tout[max_n];
void precalc_dfs(int u) {
    tin[u] = timer++;
    if (l[u] == -1) {
        point_add(a[u]);
        return;
    }
    precalc_dfs(l[u]);
    precalc_dfs(r[u]);
    tout[u] = timer;
}

void sets_dfs(int u) {
    if (l[u] == -1) {
        sub[u].insert(a[u]);
        return;
    }
    for (int v : {l[u], r[u]}) {
        sets_dfs(v);
        if (sub[v].size() > sub[u].size()) swap(sub[u], sub[v]);
        for (int w : sub[v]) sub[u].insert(w);
    }
}

void dfs(int u) {
    int L = l[u], R = r[u];
    if (L == -1) {
        sub[u].insert(a[u]);
        return;
    }

    dfs(L); dfs(R);
    if (sub[L].size() > sub[R].size()) swap(L, R);

    int cnt_l = 0, cnt_r = 0;
    for (auto v : sub[L]) {
        // int cnt = sub[R].order_of_key(v);
        int cnt = range_sum(tin[R], tout[R], v);
        cnt_l += cnt;
        cnt_r += sub[r[u]].size() - cnt;
    }
    invs[u] = min(cnt_l, cnt_r) + invs[L] + invs[R];
}

void read() {
    cin >> n;
    vi s; s.pb(0);
    for (int i = 0; i < 2*n-1; i++) {
        int data; cin >> data; 
        if (data == 0) {
            l[s.back()] = nodes_sz+1;
            r[s.back()] = nodes_sz+2;
            s.pop_back();
            s.pb(nodes_sz+2);
            s.pb(nodes_sz+1);
            nodes_sz += 2;
        } else {
            data--;
            a[s.back()] = data; 
            s.pop_back(); 
        }
    }
}

void solve() {
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    memset(a, -1, sizeof a);
    read();

    precalc_dfs(0);
    dfs(0);
    cout << invs[0] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
