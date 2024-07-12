// O(n sqrt(n * log n))

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;

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

#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <class T> using Tree = tree<T, null_type, less_equal<T>, 
    rb_tree_tag, tree_order_statistics_node_update>;

const int N = 2e5, K = 105;

void solve() {
    int n; cin >> n;    
    vi a(n), values;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        values.pb(a[i]);
    }
    sort(all(values));
    values.erase(unique(all(values)), values.end());
    vi freq(n);
    for (int& x : a) {
        x = lwb(values, x);
        freq[x]++;
    }

    i64 ans = 0;
    for (int v = 0; v < n; v++) if (freq[v] > K) {
        vi pre(n+1);
        for (int i = 0; i < n; i++) pre[i+1] = a[i] == v ? 1 : -1;
        for (int i = 0; i < n; i++) pre[i+1] += pre[i];
        Tree<int> tr; tr.insert(0);
        for (int i = 1; i <= n; i++) {
            ans += tr.order_of_key(pre[i]);
            tr.insert(pre[i]);
        }
    }

    vi f(n);
    for (int i = 0; i < n; i++) {
        array<int, 2> best {}; // (cnt, val)
        for (int j = i+1; j <= min(i+2*K, n); j++) {
            f[a[j-1]]++;
            ckmax(best, {f[a[j-1]], a[j-1]});
            if (freq[best[1]] <= K) ans += 2*best[0] > j-i;
        }
        for (int j = i+1; j <= min(i+2*K, n); j++) {
            f[a[j-1]]--;
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
