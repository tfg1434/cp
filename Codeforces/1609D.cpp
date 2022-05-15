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

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, d; while (cin >> n >> d) {
        for (ll i = 1; i <= n; i++) makeSet(i);
        
        ll post = 0;
        for (ll i = 0; i < d; i++) {
            ll x, y; cin >> x >> y;

            if (findSet(x) == findSet(y)) {
                post++;
            } else {
                unionSets(x, y);
            }

            vector<ll> h(n+1, 0);
            for (ll j = 1; j <= n; j++) {
                findSet(j);
                h[par[j]]++;
            }
            sort(all(h));

            ll ans = 0;
            for (ll j = n; j >= n - post; j--) {
                ans += h[j];
            }
            cout << ans-1 << '\n';
        }

        cout << '\n';
    }
    
    return 0;
}

