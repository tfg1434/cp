// i solved the wrong problem:
// I solved the problem where the MAD is the minimum value which appears
// >= 2 times, so the MAD is not defined for every subarray
//
// I understood the stmt correctly, but messed up my reduction
// I could avoid this mix-up in the future by saying why the original problem
// is equivalent to the reduction in a few words.

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
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define len(x) (int)((x).size())
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

void solve() {
    int n; cin >> n;
    vi a(n);
    map<int, vi> where;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        where[a[i]].pb(i);
    }

    int ans = 0;
    set<int> black;
    for (auto it = rbegin(where); it != rend(where); it++) {
        auto [val, inds] = *it;
        int m = len(inds);
        for (int i = 1; i < m; i++) {
            int prv_black = -1, l_border = -1, nxt_black = n, r_border = n;
            if (i < m-1) r_border = inds[i+1];
            auto tmp = black.lb(inds[i]);
            if (tmp != end(black)) {
                nxt_black = *tmp;
                if (next(tmp) != end(black)) {
                    ckmin(r_border, *next(tmp));
                }
            }
            if (tmp != begin(black)) {
                tmp--;
                prv_black = *tmp;
                if (tmp != begin(black)) {
                    tmp--;
                    l_border = *tmp;
                }
            }

            if (l_border < inds[i-1] && inds[i-1] < prv_black) {
                ans += val*(inds[i-1]-l_border)*(r_border-inds[i]);
            } 
            if (prv_black < inds[i-1]) {
                ans += val*(inds[i-1]-prv_black)*(nxt_black-inds[i]);
                if (prv_black != -1)
                    ans += val*(prv_black-l_border)*(nxt_black-inds[i]);
                if (nxt_black != n)
                    ans += val*(inds[i-1]-prv_black)*(r_border-nxt_black);
            }
            ps(ans);
        }

        for (int ind : inds) black.ins(ind);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
