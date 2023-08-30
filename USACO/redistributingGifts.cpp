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

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; while (cin >> n) {
        vector<vi> a(n, vi(n));
        f0(i, n) {
            f0(j, n) {
                cin >> a[i][j]; a[i][j]--;
            }
            while (a[i].back() != i) a[i].pop_back();
        }

        gg(a);
        vi ans(n);
        vector<vb> reachable(n, vb(n));
        f0(i, n) {
            y_combinator([&](auto rec, ll u) -> void {
                reachable[i][u] = true;
                for (auto v : a[u]) {
                    if (reachable[i][v]) continue;
                    rec(v);
                }
            })(i);
        }
        f0(i, n) {
            for (auto j : a[i]) {
                if (reachable[j][i]) {
                    cout << j+1 << endl;
                    break;
                }
            }
        }    
    } 
    
    return 0;
}
