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
using tp = tuple<ll, ll, ll>;
const ll N = 3005;
ll W[N][N];
ll dist[N][N], pre[N][N];

int main() {
    memset(W, 0, sizeof W);
    for(ll i = 0; i < N; i++) for (ll j = 0; j < N; j++) dist[i][j] = INFF, pre[i][j] = -1;

    cin.tie(0) -> ios::sync_with_stdio(0);
    
    ll n, m, k; cin >> n >> m >> k; 
    vector<pll> e;
    for (ll i = 0; i < m; i++) {
        ll u, v; cin >> u >> v;
        if (u > v) swap(u,v);
        W[u][v] = W[v][u] = 1; 
        e.pb({u, v});
    }
    map<tp, ll> bad;
    for (ll i = 0; i < k; i++) {
        ll a,b,c; cin >> a >> b >> c;
        bad[{a,b,c}] = 1;
    }
    auto cmp = [&](tp a, tp b) {
        auto [w1,x1,y1] = a;
        auto [w2,x2,y2] = b;
        pair<ll, pll> p1 = {w1, {x1, y1}};
        pair<ll, pll> p2 = {w2, {x2, y2}};
        return p1 > p2;
    };
    //actually not dijkstra's because >
    //just dfs since not weighted
    //it helps to think as dijkstra tho
    priority_queue<tp, vector<tp>, decltype(cmp)> pq(cmp);
    ll ans = INFF, px, py;
    for (pq.emplace(0, 1, 1); !pq.empty();) {
        auto [w,x,y] = pq.top(); pq.pop();
        gg(w,x,y);
        if (y == n) {
            if (ans > w) {
                ans = w;
                px = x, py = y;
            }
            continue;
        }

        for (ll i = 1; i <= n; i++) if (W[y][i]) {
            tp me(x, y, i);
            if (bad.count(me)) continue;
            me = tp(w+1, y, i);
            if (dist[y][i] > w+1) {
                dist[y][i] = w+1;
                pre[y][i] = x;
                pq.push(me);
            }
        }
    }
    cout << (ans == INFF ? -1 : ans) << endl;
    if (ans != INFF) {
        vector<ll> path;
        while (pre[px][py] != -1) {
            path.pb(py);
            ll pz = pre[px][py];
            py = px, px = pz;
        }
        path.pb(1);
        for (ll i = path.size()-1; i >= 0; i--) {
            cout << path[i] << ' ';
        }
        cout << endl;
    }

    return 0;
}
