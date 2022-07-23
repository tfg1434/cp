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
    freopen("wormsort.in", "r", stdin);
    freopen("wormsort.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m; cin >> n >> m;
    vector<ll> p(n+1);
    for (ll i = 1; i <= n; i++) {
        cin >> p[i];
    }
    vector<vector<ll>> ws(m, vector<ll>(3));
    for (ll i = 0; i < m; i++) cin >> ws[i][0] >> ws[i][1] >> ws[i][2];

    sort(all(ws), [](const vector<ll>& a, const vector<ll>& b) {
        return a[2] > b[2];
    });

    auto check = [&](ll x) {
        DSU dsu; dsu.init(n);
        for (ll i = 0; i < m; i++) {
            if (ws[i][2] >= x) dsu.unite(ws[i][0], ws[i][1]);
        }

        for (ll i = 1; i <= n; i++) {
            if (!dsu.sameSet(p[i], i))return false; 
        }
        return true;
    };

    ll lo = 0, hi = INFF;
    ll ans = -1;
    while (lo < hi) {
        // cout << lo << " " << hi << endl;
        ll mid = (lo + hi) / 2;

        if (check(mid)){
            ans = max(ans, mid);
            lo = mid+1;
        }
        else hi=mid;
    }

    cout << (ans == INFF ? -1 : ans) << endl;
    
    return 0;
}

