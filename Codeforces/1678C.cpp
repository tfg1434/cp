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
        ll n; cin >> n;
        vector<ll> p(n+1);
        for (ll i = 1; i <= n; i++) cin >> p[i];
        vector<ll> f(n+1, 0);
        for (ll b = 1; b <= n; b++) {
            for (ll d = b+1; d <= n; d++) {
                if (p[b] > p[d]) f[b]++;
            }
        }

        ll ans = 0;
        for (ll c = 1; c <= n; c++) {
            for (ll b = 1; b < c; b++) {
                if (p[b] > p[c]) f[b]--;
            }

            vector<ll> pre(n+1, 0);
            for (ll k = 1; k <= c; k++) pre[k] = pre[k-1] + f[k];
            for (ll a = 1; a < c; a++) {
                if (p[a] < p[c]) ans += pre[c-1] - pre[a];
            }
        }

        cout << ans << '\n';

        // ll ans = 0;
        // for (ll b = 2; b < n-1; b++) {
            // for (ll c = b+1; c < n; c++) {
                // ll ca = 0, cd = 0;
                // for (ll a = b-1; a >= 1; a--) {
                    // if (p[a] < p[c]) ca++;
                // }
                // for (ll d = c+1; d <= n; d++) {
                    // if (p[d] < p[b]) cd++;
                // }
                
                // ans += ca*cd;
            // }
        // }

        // cout << ans << '\n';
    }    
    
    return 0;
}

