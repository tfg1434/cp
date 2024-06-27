#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int mod = 1e9+7;

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

#define pct __builtin_popcount
constexpr int p2(int x) { return 1LL << x; }
constexpr int msk2(int x) { return p2(x)-1; }
constexpr int bits(int x) { return x == 0 ? 0 : 63-__builtin_clzll(x); } // floor(log2(x)) 

const int K = 60;
struct Info {
    int l, r, ans;
    Info() : l{-1}, r{-1}, ans{-1} {}
    Info(int l, int r, int ans) : l{l}, r{r}, ans{ans} {}
};
Info memo[K][K+1];
Info merge_info(const Info& a, const Info& b, int na, int nb) {
    Info res;
    res.l = a.l + (a.l == na)*b.l;
    res.r = b.r + (b.r == nb)*a.r;
    (res.ans = a.ans + b.ans + (a.r%mod)*(b.l%mod)) %= mod;
    return res;
}

void precalc() {
    for (int m = 0; m < K; m++) {
        for (int k = 0; k <= K; k++) {
            if (!m) {
                memo[m][k] = Info(1, 1, 1);
            } else if (!k) {
                memo[m][k] = Info(1, 0, 1);
            } else {
                memo[m][k] = merge_info(memo[m-1][k], memo[m-1][k-1], p2(m-1), p2(m-1));
            }
        }
    }
}

Info f(int n, int k) {
    if (p2(bits(n)) == n) {
        return memo[bits(n)][k];
    }
    if (!k) {
        return Info(1, 0, 1);
    }
    int m = bits(n-1);
    Info a = f(p2(m), k), b = f(n-p2(m), k-1);
    return merge_info(a, b, p2(m), n-p2(m));
}

void solve() {
    int n, k; cin >> n >> k;
    cout << f(n, k).ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    precalc();
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
