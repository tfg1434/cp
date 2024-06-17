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
    map<int, vi> m;
    for (int i = 0; i < n; i++) {
        int a, c; cin >> a >> c;
        points.pb(a);
        m[c].pb(a);
    }
    for (auto& [u, v] : m) {
        sort(all(v));
        // pre..
    }
    int ans = 0;
    for (auto& [u, v] : m) {
        int ind_out = upb(points, -v.back());
        int ind_in = upb(v, -v.back());
        int cnt_out = n - ind_out - (v.size() - ind_in);
        int sum_out = pre[n] - pre[ind_out] - (PRE[v.size()] - PRE[ind_in]);

        int max_out = 
        int cnt_in = v.size() - lwb(v, );
        int sum_in = ;
        ckmax(ans, v.back()*cnt_out + sum_out);
        v.back()*()
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
