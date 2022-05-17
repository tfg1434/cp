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
    
    ll n, k; while (cin >> n >> k) {
        string s; cin >> s;
        bool c[26] = { 0 };
        for (ll i = 0; i < k; i++) {
            char x; cin >> x;
            c[x - 'a'] = true;
        }

        vector<ll> a(n+1);
        for (ll i = 0; i < n; i++) {
            if (c[s[i] - 'a']) {
                a[i] = 1;
            } else {
                a[i] = 0;
            }
        }

        vector<ll> dp(n + 1, 0);
        dp[0] = 0;
        ll ans = 0;
        for (ll i = 0; i < n; i++) {
            if (a[i] == 0) {
                dp[i+1] = 0;
            } else {
                dp[i + 1] = dp[i] + 1;
            }

            ans += dp[i + 1];
        }

        cout << ans << '\n';
    }        
    
    return 0;
}

