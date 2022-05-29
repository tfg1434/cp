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
constexpr int MAX_SIEVE = 1e4+5;

inline ll gcd(ll a, ll b) { return (b == 0) ? a : gcd(b, a % b); }

inline ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

// ll Landau = -INFF;
// void findLCM(vector<ll> &arr) {
    // ll nth_lcm = arr[0];
    // for (ll i = 1; i < arr.size(); i++)
        // nth_lcm = lcm(nth_lcm, arr[i]);
    // Landau = max(Landau, nth_lcm);
// }
// void findWays(vector<ll> &arr, ll i, ll n) {
    // if (n == 0) findLCM(arr);
    // for (ll j = i; j <= n; j++) {
        // arr.push_back(j);
        // findWays(arr, j, n - j);
        // arr.pop_back();
    // }
// }
// ll Landau_function(ll n) {
    // vector<ll> arr;
    // findWays(arr, 1, n);
    // return Landau;
// }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<bool> isPrime(MAX_SIEVE, true);
    for (ll i = 2; i*i <= MAX_SIEVE; i++) {
        if (isPrime[i])         
            for (ll j = i*i; j <= MAX_SIEVE; j += i)
                isPrime[j] = false;
    }
    
    ll n, m; cin >> n >> m;
    vector<ll> dp(n+1, 0);
    dp[0] = 1;
    for (ll i = 2; i <= n; i++) {
        if (!isPrime[i]) continue;
        vector<ll> temp(n+1, 0);

        for (ll j = 1; pow(i, j) <= n; j++) {
            ll po = pow(i, j);
            // cout << po << endl;
            
            for (ll k = 0; k <= n - po; k++) {
                temp[k+po] += (dp[k] * po) % m;
            }
        }

        for (ll i = 0; i <= n; i++) {
            dp[i] += temp[i];
            dp[i] %= m;
        }
    }

    ll ans = 0;
    for (ll i = 0; i <= n; i++) {
        ans += dp[i];
        ans %= m;
    }
    cout << ans << '\n';
    
    return 0;
}

