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
#define gg(...) [](const auto&...x){ char c='='; cerr<<#__VA_ARGS__; ((cerr<<exchange(c,',')<<x),...); cerr<<endl; }(__VA_ARGS__);

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a;
        b >>= 1;
        a = a * a;
    }

    return res;
}

ll n;
constexpr ll N = 1e5 + 5;
ll par[N], sv[N], se[N], loop[N];
ll vis[N];
void init() {
    iota(par+1, par+n+1, 1);
    fill(sv+1, sv+n+1, 1);
    fill(se+1, se+n+1, 0);
    fill(loop+1, loop+n+1, 0);
    fill(vis+1, vis+n+1, 0);
}
ll find(ll v) {
    if (v == par[v]) return v;
    return par[v] = find(par[v]);
}
void join(ll u, ll v) {
    u = find(u);
    v = find(v);
    sv[u] += sv[v];
    se[u] += se[v];
    loop[u] |= loop[v];
    par[v] = u;
}


constexpr int MOD = 998244353;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> n;
        vector<ll> a(n), b(n);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;
        init();

        for (ll i = 0; i < n; i++) {
            if (find(a[i]) != find(b[i])) join(a[i], b[i]);
            ll rep = find(a[i]); //dont think b[i] workds too
            se[rep]++;
            if (a[i] == b[i]) loop[rep] = 1;
        }

        ll ans = 1;
        for (ll i = 1; i <= n; i++) {
            ll rep = find(i);
            if (vis[rep]) continue;

            gg(rep, sv[rep], se[rep]);

            if (sv[rep] != se[rep]) ans = 0;
            else ans *= (loop[rep] ? n : 2), ans %= MOD;
            vis[rep] = 1;
        }

        cout << ans << endl;
    } 
    
    return 0;
}
