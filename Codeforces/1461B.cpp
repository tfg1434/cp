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
        ll n, m; cin >> n >> m;
        vector<string> grid(n);
        for (auto &s : grid) cin >> s;

        vector<vector<ll>> w(n, vector<ll>(m, INFF));
        for (ll r = 0; r < n; r++) {
            ll cnt = 0;
            for (ll c = 0; c < m; c++) {
                cnt = grid[r][c] == '*' ? cnt + 1 : 0;
                w[r][c] = min(w[r][c], cnt);
            }
            cnt = 0;
            for (ll c = m-1; c >= 0; c--) {
                cnt = grid[r][c] == '*' ? cnt + 1 : 0;
                w[r][c] = min(w[r][c], cnt);
            }
        }

        ll ans = 0;
        for (ll r = 0; r < n; r++) {
            for (ll c = 0; c < m; c++) {
                for (ll rr = r; rr < n; rr++) {
                    if (w[rr][c] <= rr - r) break;

                    ans++;
                }
            }
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

