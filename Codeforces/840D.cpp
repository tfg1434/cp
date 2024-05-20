// Mo's and it TLEs

#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2")

#include <bits/stdc++.h>
using namespace std;
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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

const int K = 500;
struct query {
    int l, r, k, ind;
    bool operator <(const query& o) const {
        if (l/K == o.l/K) return r < o.r;
        return l/K < o.l/K;
    }
};
const int max_n = 3e5, max_brute = 1000;
int n, q, a[max_n], cnt[max_n+1], ans[max_n];
V<query> queries;

void solve() {
    cin >> n >> q; 
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) {
        int l, r, k; cin >> l >> r >> k; l--;
        if (r-l <= max_brute) {
            int res = inf;
            for (int i = l; i < r; i++) {
                cnt[a[i]]++;
                if (cnt[a[i]]*k > r-l) {
                    res = min(res, a[i]);
                }
            }
            if (res == inf) res = -1;
            ans[i] = res;
            for (int i = l; i < r; i++) cnt[a[i]] = 0;
        } else {
            queries.pb({l, r, k, i});
        }
    } 
    sort(all(queries));

    vi cols;
    for (int i = 0; i < n; i++) {
        cnt[a[i]]++;
        if (cnt[a[i]] == 201) {
            cols.pb(a[i]);
        }
    }
    sort(all(cols));
    memset(cnt, 0, sizeof cnt);

    vb vis(n);
    auto check = [&](int i) {
        if (!vis[i]) {
            cnt[a[i]]++;
        } else {
            cnt[a[i]]--;
        }
        vis[i] = !vis[i];
    };

    int l = 0, r = 0;
    for (auto [L, R, K, IND] : queries) {
        while (r < R) check(r++);
        while (l > L) check(--l);
        while (l < L) check(l++);
        while (r > R) check(--r);

        int res = inf;
        for (int col : cols) if (cnt[col]*K > R-L) {
            res = col;
            break;
        }
        if (res == inf) res = -1;
        ans[IND] = res;
    }
    
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
