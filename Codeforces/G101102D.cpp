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

ll c2(ll x) {
    return x*(x+1)/2;
}

// Thinking
// Straightforward

// Implementation
// Use e array to compress size and parent in one for dsu,
// also make it even more unreadable :)))
// I thought you need a set to access the next one. But you
// already sorted it... think clearly.
//
// If fopen trick
int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n, m; cin >> n >> m;
        vector<vi> ma(n+1, vi(m+1));
        f1(i, n+1) {
            f1(j, m+1) {
                cin >> ma[i][j];
            }
        }

        ll ans = 0;
        vi h(m+1);
        f1(i, n+1) {
            f1(j, m+1) {
                if (ma[i][j] == ma[i-1][j]) h[j]++;
                else h[j] = 1;
            }

            vi e(m+2); 
            ll cnt = 0;
            auto make = [&](ll u) -> void {
                cnt++;
                e[u] = -1;
            };
            auto find = y_combinator([&](auto rec,ll u) -> ll {
                // u is apparently 0 and so e[u] is also 0
                assert(e[u] != 0);
                return e[u] < 0 ? u : e[u] = rec(e[u]);
            });
            auto unite = [&](ll u, ll v) -> void {
                u = find(u);
                v = find(v);
                assert(u != v);
                if (e[u] > e[v]) swap(u, v);
                cnt -= c2(-e[u]);
                cnt -= c2(-e[v]);
                e[u] += e[v];
                cnt += c2(-e[u]);
                e[v] = u;
            };

            vector<pll> b; 
            f1(j, m+1) {
                b.eb(h[j], j);
            }
            sort(rall(b));

            for(ll j=0, mx=i; mx>=1; mx--) {
                while (j < m && b[j].f >= mx) {
                    ll p = b[j].s;
                    make(p);
                    if (e[p-1] != 0 && ma[i][p] == ma[i][p-1]) unite(p-1, p);
                    if (e[p+1] != 0 && ma[i][p+1] == ma[i][p]) unite(p, p+1);
                    ++j;
                }
                ans += cnt;
            }
        }

        cout << ans << endl;
    } 
    
    return 0;
}
