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
        vector<pair<ll, string> > a(n+1);
        f1(i, n+1) cin >> a[i].s;
        f1(i, n+1) {
            ll x; cin >> x;
            a[x].f = i;
        }
        vector<vi> g(26);
        sort(1+all(a));

        bool ok = true;
        f1(i, n+1) for (ll j = i+1; j < n+1; j++) {
            //x < y
            string x = a[i].s, y = a[j].s;
            assert(x != y);
            //check if y is a prefix of x. if so x cannot be < y
            //and we have a contradiction
            if (y.size() < x.size() && mismatch(all(y), x.begin()).first == y.end()) {
                ok = false;
                continue;
            } 

            for (ll k = 0; k < min(x.size(), y.size()); k++) {
                if (x[k] == y[k]) continue;
                g[x[k]-'a'].pb(y[k]-'a');
            }
        }

        vb black(26), grey(26);
        vi topo;
        auto dfs = y_combinator([&](auto rec, ll u) -> void {
            if (black[u]) return;
            if (grey[u]) {
                ok = false;
                return;
            }

            grey[u] = true;
            for (auto v : g[u]) {
                rec(v);    
            }

            topo.pb(u);
            grey[u] = false;
            black[u] = true;
        });
        f0(i, 26) {
            if (black[i]) continue;
            dfs(i);
        }
        reverse(all(topo));

        if (!ok) {
            cout << "NE" << endl;
            continue;
        }
        vi p(26); 
        f0(i, 26) {
            p[topo[i]] = i;
        }

        cout << "DA\n";
        f0(i, 26) cout << (char)('a'+p[i]);
        cout << endl;
    } 
    
    return 0;
}
