#include <bits/stdc++.h>
using namespace std;

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

int n, q;
vi a, pre;
map<int, vi> where;

void solve() {
    where.clear();
    cin >> n >> q;
    a.resize(n); for (int i = 0; i < n; i++) cin >> a[i];
    pre.resize(n+1); for (int i = 0; i < n; i++) pre[i+1] = pre[i]^a[i];
    for (int i = 0; i <= n; i++) where[pre[i]].pb(i);
    while (q--) {
        int l, r; cin >> l >> r; l--;
        if ((pre[r]^pre[l]) == 0) {
            cout << (r-l > 1 ? "YES" : "NO") << '\n';
        } else {
            bool good = false;
            int k = pre[r]^pre[l];
            auto nxt = ub(all(where[pre[l]^k]), l);
            if (nxt != end(where[pre[l]^k]) && *nxt < r) {
                auto nxt2 = ub(all(where[pre[l]]), *nxt);
                good |= nxt2 != end(where[pre[l]]) && *nxt2 < r;
            }
            cout << (good ? "YES" : "NO") << '\n';
        }
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
