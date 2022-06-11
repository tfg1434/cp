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

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        vector<vector<ll>> adj(n+1, vector<ll>());
        for (ll i = 0; i < n-1; i++) {
            ll u, v; cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }    

        ll ans = INFF;
        y_combinator([&](auto rec, ll curr, ll prev, ll dist) {
            if (curr == 1) {
                if (len(adj[curr]) == 1) {
                    ans = min(ans, dist+1);
                    return;
                }
            } else {
                if (len(adj[curr]) == 1) {
                    ans = min(ans, dist);
                    return;
                } else if (len(adj[curr]) == 2) {
                    ans = min(ans, dist+1);
                    return;
                }
            }

            for (auto u : adj[curr]) {
                if (u != prev) {
                    rec(u, curr, dist+2);
                }
            }
        })(1, 0, 1);

        cout << n - ans << endl;
    }    
    
    return 0;
}

