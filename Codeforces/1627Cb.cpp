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


constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        // gg(n);
        vector<vector<pll>> adj(n+1);
        vector<ll> deg(n+1, 0);
        deg[0] = INFF;
        bool ok = true;
        for (ll i = 0; i < n-1; i++) {
            ll u, v; cin >> u >> v;
            // gg(u, v);
            adj[u].push_back({ v, i });
            adj[v].push_back({ u, i });
            if (++deg[u] > 2) ok = false;
            if (++deg[v] > 2) ok = false;
        }

        if (!ok) {
            cout << "-1\n";
            continue;
        }

        vector<ll> ans(n-1);
        y_combinator([&](auto rec, ll u, ll par, ll p) -> void {
            // gg(u, adj);
            for (auto [v, idx] : adj[u]) {
                if (v == par) continue;
                ans[idx] = p;
                // gg(p);
                rec(v, u, p ^ 1);
            }

        })(min_element(all(deg)) - deg.begin(), -1, 2);

        for (auto x : ans) cout << x << ' ';
        cout << endl;
    }
    
    return 0;
}
