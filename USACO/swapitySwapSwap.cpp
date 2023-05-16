#include <bits/stdc++.h>
using namespace std;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
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
    freopen("swap.in", "r", stdin);
    freopen("swap.out", "w", stdout);
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, m, k; while (cin >> n >> m >> k) {
        vector<ll> p(n+1);
        for (ll i = 1; i <= n; i++) p[i] = i;
        for (ll i = 0; i < m; i++) {
            ll l, r; cin >> l >> r;
            reverse(p.begin()+l, p.begin()+r+1);
        }

        vector<ll> ans(n+1, -1);
        for (ll i = 1; i <= n; i++) {
            if (ans[i] != -1) continue;
            vector<ll> off(n+1);
            vector<pll> a;
            a.pb({0, i});
            off[0] = i;
            ll x = p[i], cnt = 0;
            while (x != i) {
                off[++cnt] = x;
                a.pb({cnt, x});
                x = p[x];
            }
            cnt++;
            for (auto [o, y] : a) {
                //p^k = p^(k mod cnt) where p^0(x)=x
                //o=1 implies p[i]=y
                //p^k(y)=p^(k mod cnt=m)(y)=p^(m+o)(i)
                
                ll m = (k+o)%cnt;
                // cout << o << ' ' << y << ' ' << m<< endl;
                ans[y] = off[m];
            }
        }

        for (ll i = 1; i <= n; i++) {
            cout << ans[i] << endl;
        }
    } 
    
    return 0;
}
