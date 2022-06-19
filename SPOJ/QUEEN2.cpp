#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(a) (ll)((a).size())
#define IN(A, B, C) assert(B <= A && A <= C)
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
// http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2016/p0200r0.html
template<class Fun> class y_combinator_result {
    Fun fun_;
public:
    template<class T> explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}
    template<class ...Args> decltype(auto) operator()(Args &&...args) { return fun_(std::ref(*this), std::forward<Args>(args)...); }
};
template<class Fun> decltype(auto) y_combinator(Fun &&fun) { return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun)); }

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
ll dx[] = { 0, 1, 1, 1, 0, -1, -1, -1 };
ll dy[] = { -1, -1, 0, 1, 1, 1, 0, -1 };


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n, m; cin >> n >> m;
        auto valid = [&](ll x, ll y) {
            return 0 <= x && x < m && 0 <= y && y < n;
        };
        vector<vector<char>> board(n, vector<char>(m));
        ll starty, startx, endy, endx;
        for (ll i = 0; i < n; i++) {
            for (ll j = 0; j < m; j++) {
                cin >> board[i][j];
                if (board[i][j] == 'S') {
                    starty = i;
                    startx = j;
                }
                if (board[i][j] == 'F') {
                    endy = i;
                    endx = j;
                }
            }
        }
        vector<vector<ll>> cost(n, vector<ll>(m, INFF));
        vector<vector<ll>> flag(n, vector<ll>(m, 0ll));
        // set<pll> vis;
        queue<pll> q;

        // vis.insert({ starty, startx });
        q.push({ starty, startx });
        cost[starty][startx] = 0;
        while (!q.empty() ) {
            ll y = q.front().first, x = q.front().second; q.pop();
            for (ll i = 0; i < 8; i++) {
                ll jump = 1;
                while (true) {
                    ll ny = y + jump * dy[i], nx = x + jump * dx[i];
                    if (!valid(nx, ny) || board[ny][nx] == 'X') break;
                    if (flag[ny][nx] & (1 << i)) break;

                    if (flag[ny][nx] == 0) {
                        q.push({ ny, nx });
                        cost[ny][nx] = cost[y][x] + 1;
                    }
                    flag[ny][nx] |= (1 << i);
                    jump++;
                }
                // ll ny = y + dy[i];
                // ll nx = x + dx[i];
                // if (valid(nx, ny) && board[ny][nx] != 'X') {
                    // // y_combinator([&](auto rec, ll yy, ll xx, ll dir) {
                        // // if (!valid(xx, yy) || board[yy][xx] == 'X') return;
                        // // if (flag[yy][xx] & (1 << dir)) return;
                        // // if (flag[yy][xx] == 0ll) {
                            // // q.push({ yy, xx });
                        // // }
                        // // flag[yy][xx] |= (1 << dir);
                        // // cost[yy][xx] = min(cost[yy][xx], cost[y][x] + 1);
                        // // rec(yy + dy[dir], xx + dx[dir], dir);

                    // // })(ny, nx, i);
                // }
            }
        }
        for (ll i = 0; i < n; i++) {
            // cout << flag[i] << endl;
            // cout << cost[i] << endl;
            // cout << board[i] << endl;
        }

        if (cost[endy][endx] == INFF) {
            cout << -1 << endl;
        } else {
            cout << cost[endy][endx] << '\n';
        }
    }
    
    return 0;
}

