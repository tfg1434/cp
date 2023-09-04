#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define vi vector<ll>
#define vb vector<bool>
#define f0(i,a) for(ll i=0;i<(a);i++)
#define f1(i,a) for(ll i=1;i<(a);i++)
#define rep(i,a,b) for(int i=(a);i<=(b);++i)
#define per(i,a,b) for(int i=(a);i>=(b);--i)
#define f first
#define s second
#ifdef I_AM_NOOB
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
#endif
#ifdef I_AM_NOOB
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);
#else
#define gg(...) 777771449
#endif

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;

vector<pll> drc = { { -1, 0 }, { 0, 1 }, { 1, 0 }, { 0, -1 } };

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    if (fopen("garbagerobot.in", "r")) {
        freopen("garbagerobot.in", "r", stdin);
        freopen("garbagerobot.out", "w", stdout);
    } 

    ll n, k; while (cin >> n >> k) {
        ll r1, c1; cin >> r1 >> c1; r1--; c1--;
        vector<vi> walls(n, vi(n));
        f0(i, k) {
            ll r, c; cin >> r >> c;
            r--; c--;
            walls[r][c] = 1;
        }
        auto valid = [&](ll r, ll c) -> bool {
            return r < n && c < n && r >= 0 && c >= 0;
        };
        vector<vector<vi>> dist(n, vector<vi>(n, vi(4, INFF)));
        f0(i, 4) dist[0][0][i] = (i == 1 ? 0 : 1);

        //NESW
        f0(t, 4*n*n) {
            f0(i, n) f0(j, n) f0(dir, 4) {
                ll dd = 0;
                f0(_, 4) {
                    ll dr = drc[_].f, dc = drc[_].s;
                    if (valid(i + dr, j + dc) && !walls[i + dr][j + dc]) {
                        dist[i+dr][j+dc][dir] = min(dist[i+dr][j+dc][dir],
                                dist[i][j][dd] + (dd == dir ? 0 : 1));
                    }
                    ++dd;
                }
            }
        }
        vector<vector<vi>> dist2(n, vector<vi>(n, vi(4, INFF)));
        f0(i, 4) dist2[r1][c1][i] = dist[r1][c1][i];
        f0(t, 4*n*n) {
            f0(i, n) f0(j, n) f0(dir, 4) {
                ll dd = 0;
                f0(_, 4) {
                    ll dr = drc[_].f, dc = drc[_].s;
                    if (valid(i + dr, j + dc) && !walls[i + dr][j + dc]) {
                        dist2[i+dr][j+dc][dir] = min(dist2[i+dr][j+dc][dir],
                                dist2[i][j][dd] + (dd == dir ? 0 : 1));
                    }
                    ++dd;
                }
            }
        }

        gg(dist[r1][c1]);
        ll x = *min_element(all(dist2[n-1][n-1]));
        cout << (x == INFF ? -1 : x) << endl;
    }

    
    return 0;
}
