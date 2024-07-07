// idea is definitely there; implementation, don't know why
// i gave up writing

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

const int N = 4000;
char a[N][N];
int pre[2][N+1][N+1];
int power_bl[N][N], power_tr[N][N], power[N][N];
V<array<int, 2>> diag[2*N-1];

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int pty = 0; pty < 2; pty++) {
                pre[pty][i+1][j+1] = pre[pty][i][j+1] + pre[pty][i+1][j] - pre[pty][i][j] + (a[i][j] == '#' && (i+j)%2 == pty);
            }
        }
    }

    auto try_board = [&](int i, int j, int board_siz) {
        if (!board_siz) return true;
        if (i < 0 || i+board_siz > n) return false;
        if (j < 0 || j+board_siz > n) return false;
        int rune_siz = (board_siz+1)/2;
        int pty = (i+j)%2;
        int expected_blue = rune_siz*rune_siz + (rune_siz-1)*(rune_siz-1);
        return pre[pty][i+board_siz][j+board_siz]-pre[pty][i+board_siz][j]-pre[pty][i][j+board_siz]+pre[pty][i][j] == expected_blue;
    };
    auto next_siz = [](int siz) {
        if (!siz) return 1;
        return siz+2;
    };
    auto prev_siz = [](int siz) {
        if (siz <= 1) return 0;
        return siz-2;
    };
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            while (true) {
                if (try_board(i, j-next_siz(power[i][j]), next_siz(power[i][j])) && try_board(i-next_siz(power[i][j]), j, next_siz(power[i][j]))) {
                    power[i][j] = next_siz(power[i][j]);
                } else {
                    break;
                }
            }
            diag[i-j+n-1].pb({power[i][j], min(i, j)});
        }
    }

    // for (int i = 0; i < n; i++) {
        // power_bl[i][0] = 0;
        // for (int j = 2; j < n; j += 2) {
            // power_bl[i][j] = next_siz(power_bl[i][j-2]);
            // while (!try_board(i, j-power_bl[i][j], power_bl[i][j])) power_bl[i][j] = prev_siz(power_bl[i][j]);
        // }
        // for (int j = 1; j < n; j += 2) {
            // power_bl[i][j] = j == 1 ? 1 : next_siz(power_bl[i][j-2]);
            // while (!try_board(i, j-power_bl[i][j], power_bl[i][j])) power_bl[i][j] = prev_siz(power_bl[i][j]);
        // }

        // for (int j = n-1; j >= 0; j -= 2) {
            // power_tr[i][j] = j == n-1 ? 1 : next_siz(power_tr[i][j+2]);
            // while (!try_board(i-power_tr[i][j], j, power_tr[i][j])) power_tr[i][j] = prev_siz(power_tr[i][j]);
        // }
        // for (int j = n-2; j >= 0; j -= 2) {
            // power_tr[i][j] = j == n-2 ? 1 : next_siz(power_tr[i][j+2]);
            // while (!try_board(i-power_tr[i][j], j, power_tr[i][j])) power_tr[i][j] = prev_siz(power_tr[i][j]);
        // }

        // for (int j = 0; j < n; j++) {
            // power[i][j] = min(power_bl[i][j], power_tr[i][j]);
            // diag[i-j+n-1].pb({power[i][j], min(i, j)});
        // }
    // }

    int max_board = 0;
    for (int d = 0; d < 2*n-1; d++) {
        sort(rall(diag[d]));
        set<int> positions;
        for (auto [pw, pos] : diag[d]) {
            auto rightmost = positions.ub(pos+pw);
            if (rightmost != positions.begin()) {
                rightmost = prev(rightmost);
                ckmax(max_board, *rightmost - pos);
            }

            auto leftmost = positions.lb(pos-pw);
            if (leftmost != positions.end()) {
                ckmax(max_board, pos-*leftmost);
            }

            positions.insert(pos);
        }
    }

    int ans = (max_board+1)/2;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
