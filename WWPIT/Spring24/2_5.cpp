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

// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define pct __builtin_popcount
constexpr int p2(int x) { return (int)1 << x; }
constexpr int msk2(int x) { return p2(x)-1; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 

const int B = 300;
const int max_n = 1e5;
int sm[(max_n-1)/B+1][p2(17)];

void solve() {
    int n, q; cin >> n >> q;
    vi a(n); for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) sm[i/B][a[i]]++;
    for (int b = 0; b <= (n-1)/B; b++) {
        for (int i = 0; i < 17; i++) {
            for (int j = 0; j < p2(17); j++) {
                if (!(j & p2(i))) sm[b][j] += sm[b][j|p2(i)];
            }
        }
    }

    while (q--) {
        int l, r, k; cin >> l >> r >> k; l--;
        int L = l/B, R = r/B;
        int cur = 0;
        for (int i = 16; i >= 0; i--) {
            cur ^= p2(i);
            int cnt = 0;
            for (int j = l; j < min(r, (L+1)*B); j++) cnt += (a[j] & cur) == cur;
            for (int b = L+1; b < R; b++) cnt += sm[b][cur];
            if (L < R) {
                for (int j = R*B; j < r; j++) cnt += (a[j] & cur) == cur;
            }
            if (cnt < k) cur ^= p2(i);
        }
        cout << cur << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
