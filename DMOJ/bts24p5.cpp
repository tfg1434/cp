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
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 
const int K = 50, LOG = 19;

void solve() {
    int n, q; cin >> n >> q; 
    vi a(n);
    for (int& i : a) cin >> i, i--;
    array<V<array<int, 3>>, K> queries;
    vi ans(q);
    for (int i = 0; i < q; i++) {
        int l, r, k; cin >> l >> r >> k; k--; l--;
        queries[k].pb({l, r, i});
    }

    for (int k = 0; k < K; k++) {
        array<vi, LOG> t;
        for (int i = 0; i < LOG; i++) t[i].resize(n, n);

        V<vi> where(n);
        vi pos(n);
        for (int i = 0; i < n; i++) {
            where[a[i]].pb(i);
            if (where[a[i]].size()-pos[a[i]] == k+1) {
                t[0][where[a[i]][pos[a[i]]]] = i;
                pos[a[i]]++;
            }
        }

        for (int stp = 1; stp < LOG; stp++) {
            for (int i = 0; i < n; i++) {
                t[stp][i] = t[stp-1][i];
                if (i+p2(stp-1) < n) {
                    ckmin(t[stp][i], t[stp-1][i+p2(stp-1)]);
                }
            }
        }

        for (auto [l, r, ind] : queries[k]) {
            int power = bits(r-l);
            int mn = min(t[power][l], t[power][l+(r-(l+p2(power)))]);
            if (mn < r) {
                ans[ind] = a[mn];
            } else {
                ans[ind] = -1;
            }
        }
    }

    for (int i = 0; i < q; i++) {
        if (ans[i] != -1) ans[i]++;
        cout << ans[i] << '\n';
    }


}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
