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
    
    ll n; cin >> n;
    vector<vector<ll>> adj(n+1, vector<ll>());
    for (ll i = 0; i < n-1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    ll q; cin >> q;
    for (ll i = 0; i < q; i++) {
        ll k; cin >> k;

        vector<ll> level(n+1);
        y_combinator([&](auto rec, ll u, ll p) -> void {
            if (p != 0) level[u] = level[p] + 1;
            for (ll v : adj[u]) {
                if (v == p) continue;
                rec(v, u);
            }
        })(1, -1);

        vector<bool> in(n+1);
        ll mx = 0;
        for (ll i = 0; i < k; i++) {
            ll p; cin >> p;
            if (level[p] > level[mx]) mx = p;
            in[p] = true;
        }

        ll ans = y_combinator([&](auto rec, ll u, ll p) -> ll {
            ll res = 0;
            bool more = false;
            for (ll v : adj[u]) {
                if (v == p) continue;
                res += rec(v, u);
                more = more || in[v];
            }

            in[u] = in[u] || more;
            if (in[u] && !more) res = 1;

            return res;
        })(mx, -1);

        cout << (ans==1? "YES" : "NO") << endl;
    }

    
    return 0;
}

