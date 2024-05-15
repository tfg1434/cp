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

vi p3 = {1};

int n, m, k;
V<string> inp;
V<vi> delta;

void solve() {
    cin >> n >> m >> k;    
    inp.resize(n); for (int i = 0; i < n; i++) cin >> inp[i];
    V<vi> power(n, vi(m, 0));
    for (int i = 0; i < k; i++) {
        int r, c, p; cin >> r >> c >> p; r--; c--;
        power[r][c] = p;
    }
    V<vi> cells_in_range;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (power[i][j]) {
            cells_in_range.pb(vi(11));
            for (int I = 0; I < n; I++) for (int J = 0; J < m; J++) if (inp[I][J] == '#'){
                int dist = abs(I-i)*abs(I-i) + abs(J-j)*abs(J-j);
                for (int r = 10; r*r >= dist; r--) {
                    cells_in_range.back()[r]++;
                }
            }
        }
    }

    int ind = 0;
    vi dp(1<<10);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) if (power[i][j]) {
            auto DP = dp;
            for (int msk = 0; msk < (1 << 10); msk++) {
                for (int r = 1; r <= 10; r++) if (!(msk & (1 << (r-1)))) {
                    int delta = power[i][j]*cells_in_range[ind][r] - p3[r];
                    dp[msk | (1 << (r-1))] = max(dp[msk | (1 << (r-1))], DP[msk]+delta);
                }
            }
            ind++;
        }
    }

    cout << *max_element(all(dp)) << '\n';
}

signed main() {
    for (int i = 0; i < 10; i++) p3.pb(p3.back()*3);

    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
