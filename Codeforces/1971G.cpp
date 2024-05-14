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

int n;
vi inp;
map<int, vi> buckets;

void solve() {
    buckets.clear();
    cin >> n;
    inp.resize(n); for (int i = 0; i < n; i++) cin >> inp[i];
    for (int i = 0; i < n; i++) {
        if (inp[i] < 4) buckets[0].pb(inp[i]);
        else buckets[inp[i]>>2].pb(inp[i]);
    } 

    map<int, int> pointer;
    for (auto& [u, v] : buckets) {
        sort(all(v));
        pointer[u] = 0;
    }
    for (int i = 0; i < n; i++) {
        int x;
        if (inp[i] < 4) x = buckets[0][pointer[0]++];
        else x = buckets[inp[i]>>2][pointer[inp[i]>>2]++];
        cout << x << " \n"[i==n-1];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
