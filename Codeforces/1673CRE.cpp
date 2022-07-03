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
constexpr ll N = 4e4+5;
constexpr ll M = 498+5;


//log(n)
ll isPal(ll x) {
    ll res = 0;
    for (ll i = x; i > 0; i /= 10) {
        res = res*10 + i%10;
    }
    return x == res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<vector<ll>> dp(N, vector<ll>(M));
    for (ll i = 1; i < N; i++) dp[i][0] = 0;
    for (ll i = 1; i < M; i++) dp[0][i] = 1;

    vector<ll> pals;
    pals.push_back(-1);
    for (ll i = 1; i <= 4e4; i++) {
        if (isPal(i)) pals.push_back(i);
    }

    for (ll i = 1; i < N; i++) {
        for (ll j = 1; j < M; j++) {
            if (pals[j] <= i) {
                dp[i][j] = (dp[i][j-1] + dp[i-pals[j]][j]) % MOD;
            } else {
                dp[i][j] = dp[i][j-1];
            }
        }
    }
    
    int T; cin >> T; while (T--) {
        ll n; cin >> n;

        cout << dp[n][M-1] << endl;
    }    
    
    return 0;
}

