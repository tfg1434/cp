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

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
struct DSU {
	vector<ll> e;
	void init (ll n) { e = vector<ll> (n, -1); }
	ll get (ll x) { return (e[x] < 0 ? x : e[x] = get(e[x])); }
	bool sameSet (ll x, ll y) { return get(x) == get(y); }
	ll size (ll x) { return -e[get(x)]; }
	bool unite (ll x, ll y) {
		x = get(x), y = get(y);
		if (x == y) return 0;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y];
		e[y] = x;
		return 1;
	}
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, q; cin >> n >> q;
    vector<vector<ll>> adj(n+1, vector<ll>(3));
    for (ll i = 0; i < n-1; i++) {
        ll a, b; cin >> a >> b;
        adj[i][0] = a, adj[i][1] = b;
        ll r; cin >> r;
        adj[i][2] = r;
    }

    vector<pll> qs;
    for (ll i = 0; i < q; i++) {
        ll k, v; cin >> k >> v;
        qs.push_back({k, v});
    }
    sort(all(adj)) ;
    reverse(all(adj));
    sort(all(qs));
    reverse(all(qs));
    DSU dsu;
    dsu.init(n+1);
    for (ll i = 0; i <= n; i++) {
        dsu.e[i] = i;
    }

    ll e_idx = 0, q_idx = 0;
    while (q_idx < q) {
        if (e_idx == n-1 || adj[e_idx][2] < qs[q_idx].first) {
            //take query
            cout << dsu.size(qs[q_idx].second)-1 << endl;
            q_idx++;

        } else {
            //look at an edge
            dsu.unite(adj[e_idx][0], adj[e_idx][1]);
            e_idx++;
        }
    }

    
    return 0;
}

