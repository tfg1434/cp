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

constexpr int MOD = 998244353;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr ll N = 2e5+5;
constexpr ll M = 700;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    ll n, k; while (cin >> n >> k) {
        vector<ll> dp(n+1), ans(n+1);
        //dp[i](x) \in [1,n]
        dp[0] = 1;
        
        for (ll l = 0; l+k <= n; l += k++) {
            vector<ll> sum(k);
            for (ll i = l; i <= n; i++) {
                ll curr = dp[i];
                dp[i] = sum[i%k];
                sum[i%k] += curr;
                sum[i%k] %= MOD;
                ans[i] += dp[i];
                ans[i] %= MOD;
            }
        }

        for (ll i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << '\n';
    }        
    
    return 0;
}

