#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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
    int n, k; cin >> n >> k;    
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    map<int, vi> res_is;
    for (int i = 0; i < n; i++) {
        res_is[a[i]%k].pb(a[i]);
    }
    
    int odd_res = -1;
    for (const auto& [res, vec] : res_is) {
        if (vec.size()%2) {
            if (n % 2 == 0 || odd_res != -1) {
                cout << "-1\n";
                return;
            } else {
                odd_res = res;
            }
        } 
    }

    int cost = 0;
    for (auto& [res, vec] : res_is) {
        sort(all(vec));
        int m = vec.size();
        if (m%2 == 0) {
            for (int i = 0; i < m; i += 2) cost += vec[i+1]-vec[i];
        } else {
            int mn = inf;
            int left = 0, right = 0;
            for (int i = 1; i < m; i += 2) {
                right += vec[i+1]-vec[i];
            }

            for (int skip = 0; skip < m; skip += 2) {
                ckmin(mn, left+right);
                if (skip+2 < m) {
                    left += vec[skip+1]-vec[skip];
                    right -= vec[skip+2]-vec[skip+1];
                }
            }

            left = 0, right = 0;
            for (int i = 3; i < m; i += 2) right += vec[i+1]-vec[i];
            for (int skip = 1; skip < m; skip += 2) {
                ckmin(mn, left+right + vec[skip+1]-vec[skip-1]);
                if (skip+2 < m) {
                    left += vec[skip]-vec[skip-1];
                    right -= vec[skip+3]-vec[skip+2];
                }
            }
            cost += mn;
        }
    }

    cost /= k;
    cout << cost << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while(tc--) solve();
    return 0;
}
