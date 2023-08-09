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
// constexpr ll P = 1e9+7;
constexpr ll P = 998244353;
//
ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % P;
        b >>= 1;
        a = a * a % P;
    }

    return res;
}

struct Dsu {
    ll n;
    vector<ll> par, sz, sz2;//, maxw;
    Dsu(ll _n) : par(_n), sz(_n), sz2(_n) {  }
    ll find(ll v) {
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }
    void unite(ll a, ll b) {
        ll x = find(a), y = find(b);
        if (x != y) {
            par[y] = x;
            sz[x] += sz[y];
            sz2[x] += sz2[y];
            // maxw[a] = max(maxw[a], maxw[b]);
        }
    }
};

//totally didn't spend 15 mins figuring out why it doesn't work 
//b/c i was convinced i was using the right mod from a different
//usaco problem......

int main() {
    cin.tie(0) -> ios::sync_with_stdio(0);
    
    int T; cin >> T; while (T--) {
        ll n, S; cin >> n >> S;
        Dsu uf(n+1);
        vector<pair<ll, pll>> es;
        for (ll i = 0; i < n-1; i++) {
            ll u, v, w; cin >> u >> v >> w;
            es.push_back({ w, {u, v} });
        }
        sort(all(es));
        for (ll i = 1; i <= n; i++) {
            uf.par[i] = i;
            uf.sz[i] = 1;
            uf.sz2[i] = 0;
        }
        ll ans = 1;
        for (auto [w, e] : es) {
            ll a = uf.find(e.f), b = uf.find(e.s);
            gg(S-w+1, uf.sz[a], uf.sz[b]);
            ans=ans*binpow(S-w+1,1ll*uf.sz[a]*uf.sz[b]-1)%P;
            gg(ans);

            uf.unite(e.f, e.s);
            // ll rep = uf.find(e.f);
            // uf.sz2[rep]++;

            // ll rem = uf.sz[rep]*(uf.sz[rep]-1)/2 - uf.sz2[rep];
            // assert(rem >= 0);
            // ans = (ans * binpow(S-w+1, rem)) % P;
            // uf.sz2[rep] += rem;
        }

        cout << ans << endl;
    }
    
    return 0;
}
