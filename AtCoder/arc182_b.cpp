#include <bits/stdc++.h>
using namespace std;

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

constexpr int p2(int x) { return (int)1 << x; }

void solve() {
    int n, k; cin >> n >> k;    
    vi ans(n, p2(k-1));
    auto answer = [&]() {
        for (int i = 0; i < n; i++) cout << ans[i] << " \n"[i==n-1];
    };
    int ans_ind = 1;
    if (n == 1) {
        answer();
        return;
    }
    for (int pos = 1; pos < k; pos++) {
        for (int i = 0; i < p2(pos-1); i++) {
            ans[ans_ind++] += p2(k-1-pos)+p2(k-pos)*i;
            if (ans_ind == n) {
                answer();
                return;
            }
        }
    }
    answer();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
