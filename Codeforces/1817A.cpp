#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9+1;

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

int max_len(int n) {
    return min(2, n);
}

void solve() {
    int n, q; cin >> n >> q;
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    V<array<int, 2>> blocks;
    for (int i = 0; i < n; ) {
        int j = i+1;
        while (j < n && a[j-1] >= a[j]) j++;
        blocks.pb({i, j});
        i = j;
    }
    int m = blocks.size();
    vi pre(m+1);
    for (int i = 0; i < m; i++) pre[i+1] = pre[i]+max_len(blocks[i][1]-blocks[i][0]);

    while (q--) {
        int l, r; cin >> l >> r; l--;
        int L = upb(blocks, {l, inf})-1;
        int R = upb(blocks, {r, -inf})-1;
        if (L == R) {
            cout << max_len(r-l) << '\n';;
            continue;
        }
        int ans = 0;
        if (R-L > 1) {
            ans += pre[R]-pre[L+1];
        }
        ans += max_len(blocks[L][1]-l);
        ans += max_len(r-blocks[R][0]);
        cout << ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
