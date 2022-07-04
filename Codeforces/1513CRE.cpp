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
constexpr ll MAXN = 200005;
ll dp[MAXN];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (ll i = 0; i <= 8; i++) dp[i] = 2;
    dp[9] = 3; 
    for (ll i = 10; i < MAXN; i++) dp[i] = (dp[i-9]+dp[i-10])%MOD;

    int T; cin >> T; while (T--) {
        ll n, m; cin >> n >> m;

        ll ans = 0;
        while (n > 0) {
            ll x = n%10;
            if (m + x < 10) ans += 1;
            else ans += dp[m +x-10];

            ans %= MOD;
            n/= 10;
        }

        cout << ans << endl;
    }    
    
    return 0;
}

