// WA on samples
// unnecessarily complex but honestly I think it should work...

#include "secret.h"
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
 
const int max_n = 1000, max_bit = 10;
int dat[max_bit][max_n+1];
int mask[max_n];
int n, a[max_n];
void precalc(int l, int r, int lvl) {
    if (l == r-1) return;
    int m = (l+r)/2;
    dat[lvl][m-1] = a[m-1];
    dat[lvl][m+1] = a[m];
    for (int i = m-2; i >= l; i--) dat[lvl][i] = Secret(a[i], dat[lvl][i+1]);
    for (int i = m+2; i < r; i++) dat[lvl][i] = Secret(dat[lvl][i-1], a[i-1]);
    for (int i = m; i < r; i++) mask[i] |= 1<<lvl;
    precalc(l, m, lvl+1);
    precalc(m, r, lvl+1);
}
 
void Init(int N, int A[]) {
    n = N;
    memset(dat, -1, sizeof dat);
    for (int i = 0; i < N; i++) a[i] = A[i];
    precalc(0, n, 0);
}
 
int Query(int L, int R) {
    R++;
    if (L == R-1) return a[L];
    if (R == n) {
        int tz = __builtin_ctz(~mask[L]);
        return Secret(dat[tz][L], dat[tz][n]);
    }
    int tz = __builtin_ctz(mask[L]^mask[R]);
    int ans = dat[tz][L];
    if (dat[tz][R] != -1) ans = Secret(ans, dat[tz][R]);
    return ans;
}
