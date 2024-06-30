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
    int n, A, B; cin >> n >> A >> B;
    n *= 2;
    vi a(n); 
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(all(a));
    V<array<int, 2>> ans;
    int hold = -1, pure = 0;
    for (int i = 0; i < n; i++) {
        if (i == n-1 || a[i+1]-a[i] > B) {
            if (hold != -1) {
                if (a[i]-a[hold] > A) {
                    cout << "-1\n";
                    return;
                }
                ans.pb({hold, i});
                hold = -1;
            } else {
                hold = i;
            }
        } else {
            if (hold != -1) {
                if (i+2 < n && a[i+2]-a[hold] <= A) {
                    pure++;
                    ans.pb({i, i+1});
                    i++;
                } else {
                    if (a[i]-a[hold] > A) {
                        cout << "-1\n";
                        return;
                    }
                    ans.pb({hold, i});
                    hold = -1;
                }
            } else {
                pure++;
                ans.pb({i, i+1});
                i++;
            }
        }
    }
    cout << pure << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

