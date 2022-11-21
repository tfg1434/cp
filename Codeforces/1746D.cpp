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
        ll n, k; cin >> n >> k;
        vector<vector<ll>> adj(n+1);
        vector<ll> deg(n+1, 0);
        vector<ll> c(n+1);

        for (ll i = 0; i < n-1; i++) {
            ll x; cin >> x;
            adj[x].push_back(i+2);
            deg[x]++;
        }
        for (ll i = 1; i <= n; i++) cin >> c[i];
        // cout << c << endl;

        // cout << adj << endl;
        pll ans = y_combinator([&](auto rec, ll u, ll m) -> pll {
            if (deg[u] == 0) return { c[u] * m, c[u] };

            ll each = m / deg[u];
            ll rem = m % deg[u];
            ll res = c[u] * m;
            // cout << res << endl;
            vector<ll> mx;
            for (auto& v : adj[u]) {
                pair<ll, ll> V = rec(v, each);
                res += V.first;
                mx.push_back(V.second);
            }
            sort(all(mx));
            while (rem--) res += mx.back(), mx.pop_back();

            // cout << res << endl;
            return { res, mx.back() + c[u] };
        })(1, k); 

        cout << ans.first << endl;
    } 
    
    return 0;
}
