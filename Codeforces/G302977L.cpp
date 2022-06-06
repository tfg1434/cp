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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; cin >> n;
    vector<ll> p(n);
    vector<pll> c(n);
    for (ll i = 0; i < n; i++) {
        cin >> c[i].first >> p[i];
        c[i].second = i;
    }
    sort(all(c));
    ll k; cin >> k;
    vector<pll> r(k);
    for (ll i = 0; i < k; i++) {
        cin >> r[i].first;
        r[i].second = i;
    }
    sort(all(r));

    vector<vector<ll>> dp(n+1, vector<ll>(k+1));
    //base states
    for (ll j = 0; j <= k; j++) dp[0][j] = 0;
    for (ll i = 0; i <= n; i++) dp[i][0] = 0;

    for (ll i = 1; i <= n; i++) {
        for (ll j = 1; j <= k; j++) {
            dp[i][j] = dp[i-1][j];

            if (c[i-1].first <= r[j-1].first) {
                dp[i][j] = max(dp[i][j], dp[i-1][j-1] + p[c[i-1].second]);
            }
        }
    }

    vector<pll> ans;
    ll i = n-1, j = k-1;
    while (i >= 0 && j >= 0) {
        if (r[j].first >= c[i].first && dp[i+1][j+1] == dp[i][j] + p[c[i].second]) {
            ans.push_back(make_pair(c[i].second, r[j].second));
            i--; j--;
        } else if (dp[i+1][j+1] == dp[i+1][j]) {
            j--;
        } else if (dp[i+1][j+1] == dp[i][j+1]) {
            i--;
        }
    }

    cout << ans.size() << ' ' << dp[n][k] << '\n';
    for (auto &x : ans) cout << x.first+1 << ' ' << x.second+1 << '\n';
    
    return 0;
}

