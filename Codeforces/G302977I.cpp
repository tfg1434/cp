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
    
    ll n, m, q; while (cin >> n >> m >> q) {
        vector<vector<ll>> a(n+1, vector<ll>(m+1));
        for (ll i = 1; i <= n; i++) {
            for (ll j = 1; j <= m; j++) {
                cin >> a[i][j];
            }
        }
        vector<ll> b(n+1, 0); //longest

        auto solveRow = [&](ll i) {
            vector<ll> dp(m+1);
            dp[0] = 0;
            ll res = 0;

            for (ll j = 1; j <= m; j++) {
                if (a[i][j] == 0) dp[j] = 0;
                else dp[j] = dp[j-1] + 1;
                res = max(res, dp[j]);
            }

            b[i] = res;
        };

        for (ll i = 1; i <= n; i++) solveRow(i);

        for (ll i = 0; i < q; i++) {
            ll r, c; cin >> r >> c;

            a[r][c] ^= 1;
            solveRow(r);

            ll ans = *max_element(all(b));

            cout << ans << '\n';
        }
    }        
    
    return 0;
}

