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


ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<ll> a(n);
    for (auto& x : a) cin >> x;

    vector<ll> nu2(40);
    for (ll i = 0; i < n; i++) {
        ll j = 0;
        while (a[i] % 2 == 0) {
            a[i] /= 2;
            j++;
        }
        nu2[j]++;
    }

    ll ans = 0;
    //#0s
    ans += binpow(2, n) - binpow(2, n - nu2[0]);
    
    ll suff = 0;
    for (ll i = 35; i >= 1; i--) {
        if (nu2[i] != 0) {
            ans += ((binpow(2, nu2[i] - 1) - 1) * binpow(2, suff)) % MOD;
            ans %= MOD;
        }
        suff += nu2[i];
    }

    cout << ans << endl;
    
    return 0;
}

