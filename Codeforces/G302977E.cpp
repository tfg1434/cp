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
    
    ll n, k, p; while (cin >> n >> k >> p) {
        vector<ll> a(n), b(k);
        for (auto &x : a) cin >> x;
        sort(all(a));
        for (auto &x : b) cin >> x;
        sort(all(b));

        //[0, n], [0, k]. 0 is a "nonexistent" position
        //basically coordinate compression
        vector<vector<ll>> dp(k+1, vector<ll>(n+1, INFF));
        dp[0][0] = 0;

        for (ll i = 0; i < k; i++) {
            for (ll j = 0; j <= n; j++) {
                dp[i+1][j] = min(dp[i+1][j], dp[i][j]);

                //take. cannot take more than n people
                if (j < n)
                    dp[i+1][j+1] = min(dp[i+1][j+1], max(dp[i][j], abs(a[j] - b[i]) + abs(b[i] - p)));
            }
        }

        cout << dp[k][n] << '\n';
    }        
    
    return 0;
}

