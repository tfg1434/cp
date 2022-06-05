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

struct Room {
    bool on = false;
    vector<pll> ss;
};
constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr int MAXN = 105;
Room grid[MAXN+1][MAXN+1];
bool vis[MAXN+1][MAXN+1];
ll dx[] = { 0, 0, 1, -1 };
ll dy[] = { 1, -1, 0, 0 };
ll n, m;
ll ans = 1;


//valid with 0-based indexing
bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < n;
}

bool isConnected(ll x, ll y) {
    for (ll i = 0; i < 4; i++) {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        if (!valid(nx, ny)) continue;
        if (vis[nx][ny]) return true;
    }
    return false;
}

void floodFill(ll x, ll y) {
    if (!valid(x, y) || !grid[x][y].on || vis[x][y]) return;
    if (!isConnected(x, y) && !(x==0&&y==0)) return;

    vis[x][y] = true;
    for (ll i = 0; i < 4; i++) {
        ll nx = x + dx[i];
        ll ny = y + dy[i];
        floodFill(nx, ny);
    }

    for (auto [a, b] : grid[x][y].ss) {
        if (!grid[a][b].on) ans++;

        grid[a][b].on = true;
        floodFill(a, b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;
    for (ll i = 0; i < m; i++) {
        ll x, y, a, b; cin >> x >> y >> a >> b;
        x--; y--; a--; b--;
        grid[x][y].ss.emplace_back(a, b);
    }

    grid[0][0].on = true;
    floodFill(0, 0);
    // y_combinator([&](auto rec, ll x, ll y) -> void {
        // for (auto [a, b] : grid[x][y].ss) {
            // if (grid[a][b].on) continue;

            // grid[a][b].on = true;
            // ans++;
            // // cout << a << ' ' << b << endl;
            // if ((valid(a+1, b) && grid[a+1][b].on)
                    // || (valid(a-1, b) && grid[a-1][b].on)
                    // || (valid(a, b+1) && grid[a][b+1].on)
                    // || (valid(a, b-1) && grid[a][b-1].on)) {
                // rec(a, b);
            // }
        // }
    // })(1, 1);

    cout << ans << endl;
    
    return 0;
}

