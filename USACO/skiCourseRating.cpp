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
    
    ll m, n; cin >> m >> n;
    vector<vector<ll>> e(m+1, vector<ll>(n+1));
    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> e[i][j];
        }
    }
    vector<vector<ll>> f(m+1, vector<ll>(n+1));
    for (ll i = 1; i <= m; i++) {
        for (ll j = 1; j <= n; j++) {
            cin >> f[i][j];
        }
    }

    DSU dsu; dsu.init(m*n);

    
    return 0;
}

