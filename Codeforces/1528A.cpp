#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using pll = pair<long long, long long>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
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

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<ll> l(n+1), r(n+1);
        for (ll i = 1; i <= n; i++) cin >> l[i] >> r[i];
        vector<vector<ll>> adj(n+1, vector<ll>());
        for (ll i = 1; i < n; i++) {
            ll u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<vector<ll>> dp(2, vector<ll>(n+1, 0));

        y_combinator([&](auto rec, ll u, ll p = -1) -> void {
            dp[0][u] = dp[1][u] = 0;

            for (auto v : adj[u]) {
                if (v == p) continue;

                rec(v, u);
                dp[0][u] += max(dp[1][v] + abs(l[u] - r[v]), dp[0][v] + abs(l[u] - l[v]));
                dp[1][u] += max(dp[1][v] + abs(r[u] - r[v]), dp[0][v] + abs(r[u] - l[v]));
            }

        })(1);

        cout << max(dp[0][1], dp[1][1]) << '\n';
    }    
    
    return 0;
}

