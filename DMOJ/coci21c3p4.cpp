#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

void solve() {
    int n; cin >> n;
    string s; cin >> s;
    vi freq(26), FREQ(26);
    for (char c : s) freq[c-'a']++;
    vi p, q;
    int ans = 0;
    for (int i = 0; i < 2*n; i++) {
        char c = s[i];
        if (2*FREQ[c-'a'] >= freq[c-'a']) {
            q.pb(c-'a');
        } else {
            ans += i-p.size();
            p.pb(c-'a');
        }
        FREQ[c-'a']++;
        
    }

    vi v(n);
    vi last_pos(26);
    for (int i = 0; i < n; i++) { 
        int x = q[i];
        q[i] = find(last_pos[x]+all(p), x) - p.begin();
        last_pos[x] = q[i]+1;
        // cout << q[i] << " \n"[i==n-1];
    }

    Tree<int> tr;
    for (int i = n-1; i >= 0; i--) {
        ans += tr.order_of_key(q[i]);
        tr.insert(q[i]);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

