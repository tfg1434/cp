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
constexpr ll MAX_FACT = 100000;
vector<ll> fact(MAX_FACT+1, 1ll), inv(MAX_FACT+1, 1ll);


ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }

    return res;
}

ll C(ll n, ll k) {
    if (n <= k) return 1;
    ll res = (fact[n] * inv[k]) % MOD;
    return (res * inv[n - k]) % MOD;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    for (ll i = 1; i <= MAX_FACT; i++) {
        fact[i] = (fact[i-1] * i) % MOD;
        inv[i] = binpow(fact[i], MOD-2);
    }
    
    ll n, m; cin >> n >> m;
    ll ans = 0;
    for (ll a_1 = 1; a_1 <= n; a_1++) {
        ll temp = 0;
        ll x = C(a_1 + m - 2, a_1 - 1);
        
        for (ll b_m = a_1; b_m <= n; b_m++) {
            ll y = C(n - b_m + 1 + m - 2, n - b_m);
            temp = (temp + ((x * y) % MOD)) % MOD;
        }

        ans = (ans + temp) % MOD;
    }

    cout << ans << endl;
    
    return 0;
}

