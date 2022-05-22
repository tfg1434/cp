#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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
int dx[] = { 1, 1, 1, 0, 0, -1, -1, -1 };
int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

inline bool valid(int x, int y) {
    return x < 5 && y < 5 && x >= 0 && y >= 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<vector<char>> a(5, vector<char>(5));
    for (auto& x : a) {
        for (auto& y : x) {
            cin >> y;
        }
    }
    // for (auto x : a)  cout << x << endl;

    ll ans = 0;
    string s; while (cin >> s) {
        bool found = false;

        for (ll i = 0; i < 5 && !found; i++) {
            for (ll j = 0; j < 5 && !found; j++) {
                if (a[i][j] != s[0]) continue;

                y_combinator([&](auto rec, ll y, ll x, ll idx) -> void {
                    if (found) return;
                    if (idx >= s.size()-1) {
                        found = true;
                        // cout << s << endl;
                        return;
                    }

                    a[y][x] = '.';
                    for (ll k = 0; k < 8; k++) {
                        ll nx = x + dx[k];
                        ll ny = y + dy[k];
                        if (valid(nx, ny) && a[ny][nx] == s[idx + 1]) {
                            rec(ny, nx, idx + 1);
                        }
                    }
                    a[y][x] = s[idx];

                })(i, j, 0);

                if (found) ans++;
            }
        }
    }

    cout << ans << '\n';
    
    return 0;
}

