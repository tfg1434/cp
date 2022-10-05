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
constexpr ll MAXW = 105;
char board[MAXW][MAXW];
constexpr ll L = 0, R = 1, D = 2, NA = 3;

ll f(char c) {
    if (c == '\\') return R;
    if (c == '/') return L;
    if (c == '.') return D;
    return NA;
}

ll toDy(ll dir) {
    if (dir == D) return 1;
    return 0;
}

ll toDx(ll dir) {
    if (dir == R) return 1;
    if (dir == L) return -1;
    return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll w, h; cin >> w >> h;
        for (ll i = 0; i < h; i++) {
            for (ll j = 0; j < w; j++) {
                char c; cin >> c;
                board[i][j] = c;
                cout << c ;
            }
            cout << endl;
        }

        ll ans = 0;


        for (ll i = 1; i < w; i++) {
            y_combinator([&](auto rec, ll x, ll y, ll dir) -> void {
                // cout << x  << ' '<< y << endl;
                if (y == h-1) {
                    cout << "HELLO" << endl;
                    ans = max(ans, (ll)(board[h-1][x] - '0'));
                    return;
                }
                if (board[y][x] == '|' || (board[y][x] == '_' && (dir == D || dir == NA))) {
                    return;
                }

                y += toDy(dir);
                x += toDx(dir);
                ll newDir;
                if (board[y][x] == '\\') newDir = 'R';
                if (board[y][x] == '/') newDir = 'L';
                rec(x, y, newDir);

            })(i, 0, f(board[0][i]));
        }

        cout << ans << endl;
    }    

    
    return 0;
}

