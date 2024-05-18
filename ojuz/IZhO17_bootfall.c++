// Ahh TLE

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
const int max_n = 500;
const int max_c = 500;
const int max_bit = max_n*max_c;
bitset<max_bit+1> dp;
vi ans;
int sum, a[max_n];

void dnc(int l, int r) {
    if (l == r-1) {
        vi cand;
        for (int i = 0; i <= max_bit; i++) if (dp.test(i)) {
            if (i < sum-a[l]-i) {
                cand.pb(sum-a[l]-i - i);
            }
            if (i > sum-a[l]-i) {
                cand.pb(i - (sum-a[l]-i));
            }
        }
        sort(all(cand));
        // ps(cand);
        auto ANS = ans; ans.clear();
        set_intersection(all(cand), all(ANS), back_inserter(ans));
        return;
    }

    auto DP = dp;
    int m = (l+r)/2;
    for (int i = m; i < r; i++) dp |= (dp << a[i]);
    dnc(l, m);
    dp = DP;
    for (int i = l; i < m; i++) dp |= (dp << a[i]);
    dnc(m, r);
}

void solve() {

    cin >> n;
    for (int i = 1; i <= max_bit; i++) ans.pb(i);
    dp.set(0);
    for (int i = 0; i < n; i++) cin >> a[i], sum += a[i];
    // check that Tima may sit out
    {
        dp.set(0);
        for (int i = 0; i < n; i++) dp |= dp << a[i];
        if (sum % 2 || !dp.test(sum/2)) {
            cout << 0 << '\n';
            return;
        }
        dp.reset();
    }
    dp.set(0);
    dnc(0, n);

    cout << ans.size() << '\n';
    for (int skill : ans) cout << skill << ' ';
    if (ans.size()) cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
