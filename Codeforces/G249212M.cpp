// Branching M
// 20
// 15 13 38 78 39 2 89 24 63 91 48 65 13 95 98 27 43 100 71 63
// wrong answer contestant(2281) != jury(2266)

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e9;

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
vi a, inp;
int ans = inf;

void rec(int stage, int cost, int sum) {
    if (cost >= ans) return;

    if (stage == 3) {
        bool ran = false;
        for (int i = 0; i < n; i++) if (a[i]&&a[(i+1)%n]&&a[(i+2)%n]) {
            ran = true;
            int new_sum = sum-a[i]-a[(i+1)%n]-a[(i+2)%n];
            a[i] = a[(i+1)%n] = a[(i+2)%n] = 0;
            rec(3, cost+new_sum, new_sum);
            a[i] = inp[i]; a[(i+1)%n] = inp[(i+1)%n]; a[(i+2)%n] = inp[(i+2)%n];
        }
        rec(2, cost, sum);
    } else if (stage == 2) {
        bool ran = false;
        for (int i = 0; i < n-1; i++) if (a[i]&&a[(i+1)%n]) {
            ran = true;
            int new_sum = sum-a[i]-a[(i+1)%n];
            a[i] = a[(i+1)%n] = 0;
            rec(2, cost+new_sum, new_sum);
            a[i] = inp[i]; a[(i+1)%n] = inp[(i+1)%n];
        }
        rec(1, cost, sum);
    } else {
        vi vec; 
        for (int i = 0; i < n; i++) if (a[i]) vec.pb(a[i]);
        sort(all(vec));
        int extra = 0;
        for (int i = 0; i < vec.size(); i++) extra += (vec.size()-i-1)*vec[i];
        ans = min(ans, cost+extra);
    }
}

void solve() {
    cin >> n;
    int sum = 0;
    inp.resize(n); for (int i = 0; i < n; i++) cin >> inp[i], sum += inp[i];
    a = inp;
    rec(3, 0, sum);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
