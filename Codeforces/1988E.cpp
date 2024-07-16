// how to find PRV in O(n)?

#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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

const int LOG = 19;
// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define pct __builtin_popcount
constexpr int p2(int x) { return (int)1 << x; }
constexpr int msk2(int x) { return p2(x)-1; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 

void solve() {
    int n; cin >> n;
    vi p(n);
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--;

    vi ans(n+1);
    int coef;
    auto range_add = [&](int l, int r, int x) {
        x *= coef;
        ckmax(l, 0LL);
        ckmin(r, n);
        if (l >= r) return;
        ans[l] += x;
        ans[r] -= x;
    };

    V<vi> tab(LOG, vi(n));
    for (int b = 0; b < LOG; b++) {
        for (int i = 0; i < n; i++) {
            if (!b) {
                tab[0][i] = p[i];
            } else {
                tab[b][i] = tab[b-1][i];
                if (i+p2(b-1) < n) ckmin(tab[b][i], tab[b-1][i+p2(b-1)]);
            }
        }
    }
    auto range_min = [&](int l, int r) {
        int mn = n;
        for (int b = LOG-1; b >= 0; b--) if (l+p2(b) <= r) {
            ckmin(mn, tab[b][l]);
            l += p2(b);
        }
        return mn;
    };

    vi prv(n), nxt(n), PRV(n), NXT(n);
    vi stk = {-1};
    for (int i = 0; i < n; i++) {
        while (stk.back() != -1 && p[stk.back()] > p[i]) stk.pop_back();
        prv[i] = end(stk)[-1];

        if (prv[i] == -1 || range_min(0, prv[i]) > p[i]) {
            PRV[i] = -1;
        } else {
            int lo = 0, hi = prv[i];
            while (hi-lo > 1) {
                int mi = (lo+hi)/2; 
                range_min(mi, prv[i]) < p[i] ? lo = mi : hi = mi;
            }
            PRV[i] = lo;
        }
        stk.pb(i);
    }

    stk = {n};
    for (int i = n-1; i >= 0; i--) {
        while (stk.back() != n && p[stk.back()] > p[i]) stk.pop_back();
        nxt[i] = end(stk)[-1];

        if (nxt[i] == n || range_min(nxt[i]+1, n) > p[i]) {
            // ps(i, "set to n", "range_min", nxt[i]+1, n, range_min(nxt[i]+1, n));
            NXT[i] = n;
        } else {
            int lo = nxt[i], hi = n-1;
            while (hi-lo > 1) {
                int mi = (lo+hi)/2;
                range_min(nxt[i]+1, mi+1) < p[i] ? hi = mi : lo = mi;
            }
            NXT[i] = hi;
        }
        stk.pb(i);
    }
    // ps(p);
    // ps(nxt);
    // ps(NXT);

    for (int i = 0; i < n; i++) {
        int a = i-prv[i]-1, b = nxt[i]-i-1;
        coef = p[i]+1; 

        range_add(0, prv[i], (a+1)*(b+1));
        range_add(nxt[i]+1, n, (a+1)*(b+1));

        range_add(prv[i]+1, i, a*(b+1));
        range_add(i+1, nxt[i], (a+1)*b);

        int A = i-PRV[i]-1;
        range_add(prv[i], prv[i]+1, A*(b+1));
        int B = NXT[i]-i-1;
        range_add(nxt[i], nxt[i]+1, (a+1)*B);
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << " \n"[i==n-1];
        ans[i+1] += ans[i];
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
