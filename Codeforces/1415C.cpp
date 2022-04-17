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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n, p, k; cin >> n >> p >> k;
        string s; cin >> s;
        ll x, y; cin >> x >> y;
        p--;

        ll ans = INFF;
        vector<ll> dp(n, 0);
        for (ll q = n-1; q >= p; q--) {
            dp[q] = x * (1 - (s[q] - '0'));
            if (q + k < n) dp[q] += dp[q+k];
            ans = min(ans, y*(q-p)+dp[q]);
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

