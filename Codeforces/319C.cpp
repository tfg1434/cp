#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 2e18;

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
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int cdiv(int a, int b) {
    if (b < 0) a = -a, b = -b;
    if (a >= 0) return (a+b-1)/b;
    return -((-a+b-1)/b);
}

int n;
vi a, b, dp;
V<array<int, 2>> ch;

int when(int i, int j) {
    return cdiv(dp[i]-dp[j], b[j]-b[i]);
}
void add(int i) {
    while (ch.size() && when(ch.back()[1], i) <= ch.back()[0]) ch.pop_back();
    if (ch.size()) ch.pb({when(ch.back()[1], i), i});
    else ch.pb({0, i});
}
int get(int x) {
    return (*(--lb(all(ch), array<int, 2>{x, inf})))[1];
}

void solve() {
    cin >> n;
    a.resize(n); b.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    dp.assign(n, -inf); dp[0] = 0;
    add(0);

    for (int j, x, i = 1; i < n; i++) {
        j = get(a[i]);
        dp[i] = dp[j] + b[j]*a[i];
        add(i);
    }

    cout << dp[n-1] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
