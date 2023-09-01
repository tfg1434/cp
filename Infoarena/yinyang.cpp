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
#ifdef I_AM_NOOB
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);
#else
#define gg(...) 777771449
#endif

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;

// Thinking
// Min # swaps of adj elems to sort array and why
// 
// Implementation
// I overcomp'ed impl bc i thought you have to throw exception when you 
// get a contradiction. But this isn't true, you will never get a valid
// array with contradiction, so just verify at the end.
// You need only show that given there exists a solution, the algorithm
// finds it in the minimum operations.
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    freopen("yinyang.in", "r", stdin);
    freopen("yinyang.out", "w", stdout);
    
    ll n, m; while (cin >> n >> m) {
        vector<vi> ma(n, vi(m));
        f0(i, n) {
            f0(j, m) {
                cin >> ma[i][j];
            }
        }
        auto cswap = [&](ll y, ll x) -> ll {
            ll cnt = 0;
            while (x > 0 && ma[y][x] < ma[y][x-1]) {
                f0(i, n) {
                    swap(ma[i][x], ma[i][x-1]);
                }
                cnt++;
                x--;
            }

            return cnt;
        };
        auto rswap = [&](ll y, ll x) -> ll {
            ll cnt = 0;
            gg(ma);
            while (y > 0 && ma[y][x] < ma[y-1][x]) {
                f0(j, m) {
                    swap(ma[y][j], ma[y-1][j]);
                }
                cnt++;
                y--;
            }
            gg(ma);

            return cnt;
        };
        auto solve = [&]() -> ll {
            ll res = 0;
            f0(i, n) {
                f0(j, m) {
                    if (j > 0 && ma[i][j] < ma[i][j-1]) {
                        res += cswap(i, j);
                    }
                }
            }
            f0(j, m) {
                f0(i, n) {
                    if (i > 0 && ma[i][j] < ma[i-1][j]) {
                        res += rswap(i, j);
                    }
                }
            }

            gg(ma);
            f0(i, n) f0(j, m) {
                if (j > 0 && ma[i][j] < ma[i][j-1]) return -1;
                if (i > 0 && ma[i][j] < ma[i-1][j]) return -1;
            }

            return res;
        };

        cout << solve() << endl;
    } 
    
    return 0;
}
