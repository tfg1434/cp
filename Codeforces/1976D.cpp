#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

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
int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) or index of msb

void solve() {
    string s; cin >> s;
    int n = s.size();
    vi bal(n+1);
    for (int i = 0; i < n; i++) bal[i+1] = bal[i]+(s[i] == '(' ? 1 : -1);
    V<vi> st(18, vi(n+1));
    st[0] = bal;
    for (int i = 1; i < 18; i++) {
        for (int j = 0; j+(1 << i) <= n; j++) {
            st[i][j] = max(st[i-1][j], st[i-1][j+(1 << (i-1))]);
        }
    }
    auto range_max = [&](int l, int r) {
        if (r-l == 0) return 0;
        int po = bits(r-l);
        return max(st[po][l], st[po][r-(1 << po)]);
    };
    V<vi> where(n+1);
    for (int i = 0; i <= n; i++) where[bal[i]].pb(i);
    vi pos(n+1);

    long long ans = 0;
    for (int l = 0; l < n; l++) {
        int lo = l, hi = n+1;
        while (hi-lo > 1) {
            int mi = (lo+hi)/2;
            range_max(l+1, mi+1) > 2*bal[l] ? hi = mi : lo = mi;
        }
        auto cnt = ub(where[bal[l]].begin()+pos[bal[l]]+1, where[bal[l]].end(), lo) - where[bal[l]].begin();
        cnt -= pos[bal[l]]+1;
        pos[bal[l]]++;

        ans += cnt;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
