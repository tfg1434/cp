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

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr ll MAXN = 4*1e4+5;
constexpr ll CPAL = 498+5;
//dp[i][j] is # ways to partition i using only first j palindromes
//dp[i][j] = dp[i][j-1] + dp[i-p_m][j]
ll dp[MAXN][CPAL]; 


ll reverse(ll x) {
    ll res = 0;
    while (x > 0) {
        res = res*10 + x % 10;
        x /= 10;
    }
    return res;
}
bool isPal(ll x) {
    return reverse(x) == x;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<ll> pals {0};
    for (ll i = 1; i < 2*MAXN; i++) {
        if (isPal(i)) pals.push_back(i);
    }
    for (ll i = 1; i < CPAL; i++) dp[0][i] = 1;
    for (ll i = 1; i < MAXN; i++) {
        dp[i][0] = 0;
        for (ll j = 1; j < CPAL; j++) {
            if (pals[j] <= i)
                dp[i][j] = (dp[i][j-1] + dp[i-pals[j]][j]) % MOD;
            else 
                dp[i][j] = dp[i][j-1];
        }
    }
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;
        cout << dp[n][CPAL-1] << '\n';
    }    
    
    return 0;
}

