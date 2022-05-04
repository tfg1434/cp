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
constexpr ll M = 2*1e5+5;
ll dp[M];


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (ll i = 0; i <= 8; i++) dp[i] = 2;
    dp[9] = 3;
    for (ll i = 10; i < M; i++) {
        dp[i] = (dp[i-10] + dp[i-9]) % MOD;
    }
    
    int T; cin >> T; while (T--) {
        string s; cin >> s;
        ll n = s.size();
        ll m; cin >> m;

        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            ans += (m + s[i] - '0' < 10) ? 1 : dp[s[i] - '0' + m - 10];
            ans %= MOD;
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

