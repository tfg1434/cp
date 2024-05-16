// TLE

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
Tree<int> sub[max_n];
int invs[max_n];
int a[max_n];

void dfs(int u) {
    if (l[u] == -1) {
        sub[u].insert(a[u]);
        return;
    }
    dfs(l[u]); dfs(r[u]);
    if (sub[l[u]].size() > sub[r[u]].size())
        sub[l[u]].swap(sub[r[u]]);
    int cnt_l = 0, cnt_r = 0;
    for (auto v : sub[l[u]]) {
        int cnt = sub[r[u]].order_of_key(v);
        cnt_l += cnt;
        cnt_r += sub[r[u]].size() - cnt;
    }
    for (auto v : sub[l[u]]) sub[r[u]].insert(v); sub[l[u]].clear();
    if (sub[r[u]].size() > sub[u].size()) sub[r[u]].swap(sub[u]);
    for (auto v : sub[r[u]]) sub[u].insert(v);
    invs[u] = min(cnt_l, cnt_r) + invs[l[u]] + invs[r[u]];
}

void solve() {
    memset(l, -1, sizeof l);
    memset(r, -1, sizeof r);
    memset(a, -1, sizeof a);

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

    dfs(0);
    cout << invs[0] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
