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
constexpr ll SZ = 1e5 + 5;
ll par[SZ], sze[SZ];

void makeSet(ll v) {
    par[v] = v;
    sze[v] = 1;
}
ll findSet(ll v) {
    if (v == par[v]) return v;
    return par[v] = findSet(par[v]);
}
void unionSets(ll a, ll b) {
    a = findSet(a);
    b = findSet(b);

    if (a != b) {
        if (sze[a] < sze[b]) swap(a, b);
        par[b] = a;
        sze[a] += sze[b];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, q; cin >> n >> q;
    string s; cin >> s;
    //H=0, G=1
    vector<ll> b(n+1);
    for (ll i = 0; i < n; i++)
        b[i+1] = s[i] == 'G' ? 1 : 0;

    vector<vector<ll>> adj(n+1, vector<ll>());
    for (ll i = 0; i < n-1; i++) {
        ll u, v; cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<ll> comp(n+1, 0);
    ll num = 0;
    for (ll i = 1; i <= n; i++) {
        if (comp[i]) continue;

        num++;
        y_combinator([&](auto rec, ll x) -> void {
            if (comp[x]) return;
            comp[x] = num;
            for (auto& y : adj[x]) {
                if (b[y] == b[x]) {
                    rec(y);
                }
            }
        })(i);
    }

    for (ll i = 0; i < q; i++) {
        ll u, v; cin >> u >> v;
        char t; cin >> t;

        if (b[u] == (t == 'G') || comp[u] != comp[v]) cout << 1;
        else cout << 0;
    }
    cout << endl;
    
    return 0;
}

