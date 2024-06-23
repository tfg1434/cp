// transition order is so subtle and difficult for me!

#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

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

namespace solve_max {
    struct Info {
        int x, y;
        Info() {}
        Info(int x, int y) : x{x}, y{y} {}
    };
    void solve_max() {
        int n, k; cin >> n >> k;
        V<Info> top, bot;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            char b; cin >> b;
            int x, y; cin >> x >> y;
            (b == 'G' ? top : bot).pb({x, y});
            tot += y;
        }

        V<vi> dp(top.size()+1, vi(bot.size()+1));
        for (int i = 1; i <= top.size(); i++) {
            for (int j = 1; j <= bot.size(); j++) {
                ckmax(dp[i][j], max(dp[i-1][j], dp[i][j-1]));
                if (abs(top[i-1].x-bot[j-1].x) <= k) {
                    ckmax(dp[i][j], dp[i-1][j-1]+top[i-1].y+bot[j-1].y);
                }
            }
        }

        cout << tot-dp[top.size()][bot.size()] << '\n';
    }
}

namespace solve_min {
    struct Info {
        int x, y;
        Info() {}
        Info(int x, int y) : x{x}, y{y} {}
    };
    void solve_min() {
        int n, k; cin >> n >> k;
        V<Info> top, bot;
        int tot = 0;
        for (int i = 0; i < n; i++) {
            char b; cin >> b;
            int x, y; cin >> x >> y;
            (b == 'G' ? top : bot).pb({x, y});
            tot += y;
        }
        int A = top.size(), B = bot.size();
        vi nxt_top(A), nxt_bot(B);
        {
            int j = 0;
            for (int i = 0; i < A; i++) {
                while (j < B && bot[j].x-top[i].x <= k) j++;
                nxt_top[i] = j;
            }
        }
        {
            int j = 0;
            for (int i = 0; i < B; i++) {
                while (j < A && top[j].x-bot[i].x <= k) j++;
                nxt_bot[i] = j;
            }
        }

        V<vi> last(A+1, vi(B+1));
        for (int i = A; i >= 0; i--) {
            for (int j = B; j >= 0; j--) {
                if (i < A && j < B && abs(top[i].x-bot[j].x) <= k) {
                    last[i][j] = last[i+1][j+1];
                } else {
                    last[i][j] = i;
                }
            }
        }

        V<V<vi>> dp(A+1, V<vi>(B+1, vi(2, -inf)));
        dp[0][0][0] = dp[0][0][1] = 0;
        for (int i = 0; i <= A; i++) {
            for (int j = 0; j <= B; j++) {
                int J = !i ? j : max(j, nxt_top[i-1]);
                if (last[i][j] >= i+J-j) ckmax(dp[i+J-j][J][1], dp[i][j][0]);

                int I = !j ? i : max(i, nxt_bot[j-1]);
                if (last[i][j] >= I) ckmax(dp[I][j+I-i][0], dp[i][j][1]);


                if (i < A && j < B && abs(top[i].x-bot[j].x) <= k) {
                    ckmax(dp[i+1][j+1][0], dp[i][j][0]);
                    ckmax(dp[i+1][j+1][1], dp[i][j][1]);
                }
                if (i < A) ckmax(dp[i+1][j][0], dp[i][j][0]+top[i].y);
                if (j < B) ckmax(dp[i][j+1][1], dp[i][j][1]+bot[j].y);
            }
        }

        cout << *max_element(all(dp[A][B])) << '\n';
    }
}

void solve() {
    int tp; cin >> tp;
    if (tp == 1) solve_max::solve_max();
    else solve_min::solve_min();
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
