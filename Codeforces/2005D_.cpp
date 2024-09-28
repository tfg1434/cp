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
    array<vi, 2> a;
    for (int i = 0; i < 2; i++) {
        a[i].resize(n);
        for (int& j : a[i]) cin >> j;
    }
    vi divs;
    {
        for (int x : {a[0][0], a[1][0]}) {
            for (int i = 1; i*i <= x; i++) {
                if (x%i == 0) {
                    divs.pb(i);
                    divs.pb(x/i);
                }
            }
        }
        sort(all(divs));
        divs.erase(unique(all(divs)), end(divs));
    }
    int m = len(divs);

    vector need(2, V<array<int, 2>>(m)), can(2, V<array<int, 2>>(m));
    for (int j = 0; j < m; j++) {
        int d = divs[j];

        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[0][i]%d && a[1][i]%d) {
                for (int side = 0; side < 2; side++) {
                    need[side][j] = can[side][j] = {n, 0};
                }
                ok = false;
                break;
            }
        }
        if (!ok) continue;

        vi code(n);
        auto work = [&](int side) {
            if (!count(all(code), 1)) {
                need[side][j] = {n, 0};
                can[side][j] = {0, n};
                return;
            }
            int l=0, r=n-1;
            for (; code[l] != 1; l++);
            for (; code[r] != 1; r--);
            need[side][j] = {l, r};
            while (l > 0 && code[l-1] == -1) l--;
            while (r+1 < n && code[r+1] == -1) r++;
            can[side][j] = {l, r};
        };

        for (int side = 0; side < 2; side++) {
            for (int i = 0; i < n; i++) {
                int r0 = a[side][i]%d, r1 = a[1-side][i]%d;
                if (!r0 && !r1) code[i] = -1;
                code[i] = !r0 ? 0 : 1;
            }
            work(side);
        }
    }

    int ans = 0, ways = 0;
    for (int i = 0; i < m; i++) {
        ps(divs[i], need[0][i], can[0][i]);
        for (int j = 0; j < m; j++) {
            if (can[0][i][0] > can[0][i][1] || can[1][j][0] > can[1][j][1]) continue;

            if (need[1][j][0] > need[1][j][1]) {
                if (ckmax(ans, divs[i]+divs[j])) ways = 0;
                if (divs[i]+divs[j] >= ans) {
                    ways += n*(n+1)/2;
                }
            } else if (can[0][i][0] <= need[1][j][0] && need[1][j][1] <= can[0][i][1]) {
                if (ckmax(ans, divs[i]+divs[j])) ways = 0;
                if (divs[i]+divs[j] >= ans) {
                    ways += (need[1][j][0]-can[0][i][0]+1)*(can[0][i][1]-need[1][j][1]+1);
                }
            }
        }
    }

    cout << ans << ' ' << ways << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
