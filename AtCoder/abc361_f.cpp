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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

const int LOG = 60;
// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define pct __builtin_popcountll
constexpr int p2(int x) { return (int)1 << x; }

void solve() {
    int n; cin >> n;
    vi primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59};

    int ans = 0;
    for (int msk = 1; msk < p2(17); msk++) {
        int exp = 1;
        int sign = pct(msk)%2 ? 1 : -1;
        for (int bit = 0; bit < 17; bit++) if (msk&p2(bit)) {
            exp *= primes[bit];
            if (exp >= LOG) break;
        }
        if (exp >= LOG) {
            ans += sign;
            continue;
        }

        int lo = 0, hi = 1e9+1;
        while (hi-lo > 1) {
            int mi = lo+(hi-lo)/2;

            bool bad = false;
            int a = mi;
            for (int i = 0; i < exp-1; i++) {
                if ((__int128)a*mi > n) {
                    bad = true;
                    break;
                }
                a *= mi;
            }

            bad ? hi = mi : lo = mi;
        }

        ans += sign*lo;
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
