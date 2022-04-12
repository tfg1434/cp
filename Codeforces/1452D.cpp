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

constexpr int MOD = 998244353;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr int MAXN = 2*1e5+1;
ll F[MAXN];


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
    
    F[1] = 1;
    for (ll i = 2; i < MAXN; i++) F[i] = (F[i-1] + F[i-2]) % MOD;

    ll n; cin >> n;
    ll x = F[n], y = binpow(2, n);
    ll inv = binpow(y, MOD-2);
    cout << (x * inv) % MOD << '\n';
    
    return 0;
}

