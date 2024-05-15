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
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

const int max_n = 1e5;

struct trie {
    int sons[26];
    bool has_chip;
    int off;
    multiset<int> sol;
    trie() {
        memset(sons, -1, sizeof sons);
        off = 0;
        has_chip = false;
    }
} nodes[2*max_n];
int nodes_sz;
void add(string s) {
    int v = 0;
    for (int i = 0; i < s.size(); i++) {
        if (nodes[v].sons[s[i]-'a'] == -1) {
            nodes[v].sons[s[i]-'a'] = nodes_sz;
            nodes[nodes_sz++] = trie();
        }
        v = nodes[v].sons[s[i]-'a'];
    }
    nodes[v].has_chip = true;
}

int n;

void calc_dp(int u) {
    for (int i = 0; i < 26; i++) {
        int v = nodes[u].sons[i];
        if (v != -1) {
            calc_dp(v);
            if (nodes[v].sol.size() > nodes[u].sol.size()) {
                swap(nodes[u].sol, nodes[v].sol);
                swap(nodes[u].off, nodes[v].off);
            }
            for (int lvl : nodes[v].sol) nodes[u].sol.insert(lvl+nodes[v].off-nodes[u].off);
            nodes[v].sol.clear();
        }
    }

    // ps("old", u, nodes[u].off, nodes[u].sol);
    if (nodes[u].sol.size()) {
        if (!nodes[u].has_chip) {
            int mx = *rbegin(nodes[u].sol);
            nodes[u].sol.erase(nodes[u].sol.find(mx));
            nodes[u].off++;
            nodes[u].sol.insert(-nodes[u].off);
        } else {
            nodes[u].off++;
            nodes[u].sol.insert(-nodes[u].off);
        }
    } else {
        if (nodes[u].has_chip) {
            nodes[u].sol.insert(nodes[u].off);
        }
    }
    // ps("new", u, nodes[u].off, nodes[u].sol);
}

void solve() {
    nodes[nodes_sz++] = trie();
    cin >> n; 
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        add(s);
    }
    
    nodes[0].has_chip = true;
    calc_dp(0);
    int ans = 0;
    for (int lvl : nodes[0].sol) ans += nodes[0].off+lvl;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
