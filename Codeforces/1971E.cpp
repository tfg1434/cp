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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }

int n, k, q;
vi a, b, queries;

void solve() {
    cin >> n >> k >> q;
    a.resize(k); for (int i = 0; i < k; i++) cin >> a[i];
    b.resize(k); for (int i = 0; i < k; i++) cin >> b[i];
    queries.resize(q); for (int i = 0; i < q; i++) cin >> queries[i];

    a.insert(begin(a), 0);
    b.insert(begin(b), 0);
    for (int i = 0; i < q; i++) {
        auto nxt = lwb(a, queries[i]);
        if (a[nxt] == queries[i]) {
            cout << b[nxt] << ' ';
            continue;
        }
        cout << b[nxt-1]+(queries[i]-a[nxt-1])*(b[nxt]-b[nxt-1])/(a[nxt]-a[nxt-1]) << ' ';
    }    
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
