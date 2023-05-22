#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define f first
#define s second
using pll = pair<ll, ll>;
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
// struct tll {
//     ll x, y, z;
//     bool operator<(const tll a) {
//         return {{x,y},z} < {{a.x,a.y},a.z};
//     }
// };
using tll = tuple<ll, ll, ll>;
template<class TupType, size_t... I>
void print(const TupType& _tup, std::index_sequence<I...>)
{
    std::cout << "(";
    (..., (std::cout << (I == 0? "" : ", ") << std::get<I>(_tup)));
    std::cout << ")";
}
template<class... T> ostream& operator<<(ostream &os, const std::tuple<T...>& _tup)
{
    print(_tup, std::make_index_sequence<sizeof...(T)>());
}

constexpr ll INFF = 1e18;
constexpr ll P = 1e9+7;
// constexpr ll P = 998244353;
const ll N = 2005;
ll par[N];
ll find(ll x) {
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}
void unite(ll x, ll y) {
    par[find(y)] = find(x);
}

int main() {
    freopen("superbull.in", "r", stdin);
    freopen("superbull.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n; while (cin >> n) {
        memset(par, 0, sizeof par);
        
        vector<ll> a(n+1);
        for (ll i = 1; i <= n; i++) {
            cin >> a[i];
        }
        
        set<tll> es;
        // vector<vector<pll>> adj(n+1);
        for (ll i = 1; i <= n; i++) {
            for (ll j = i+1; j <= n; j++) {
                if (i == j) continue;
                es.insert({-(a[i]^a[j]),i,j});
            }
        }

        for (ll i = 1; i <= n; i++) {
            par[i] = i;
        }
        
        ll ans = 0;
        ll cnt = 0;
        // cout << es << endl;
        for (auto [w, u, v] : es) {
            // for (ll i = 1; i <= n; i++) {
            //     cout << par[i] << ' ';
            // }
            // cout << endl;
            if (find(u) == find(v)) continue;
            unite(u, v);
            // cout << w << ' ' << u << ' ' << v << endl;
            ans -= w;
            
            if (++cnt==n-1) break;
        }
        
        cout << ans << endl;
    } 
    
    return 0;
}
