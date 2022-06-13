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
    
    int T; cin >> T; while (T--) {
        ll n, k; cin >> n >> k;
        string s; cin >> s;
        ll a = 0, b = 0, c = 0;
        for (char x : s) {
            if (x == 'A') a++;
            else if (x == 'B') b++;
            else c++;
        }

        ll ans = 0;
        for (ll l = 0; l <= a; l++) {
            // for (ll r = 0; r < c; r++) {
                // if ((a - l)*b*(c-r) <= k) {
                    // break;
                // }
                // ans++;
            // }

            ll lo = 0, hi = c;
            while (lo <= hi) {
                ll mid = (lo + hi) / 2;
                if ((a - l)*b*mid <= k) {
                    lo = mid + 1;
                } else {
                    hi = mid - 1;
                }
            }
            ans += c - hi;
            // ll tot = (a-l)*b*c;
            // if (tot <= k) break;
            // ans += (tot - k) / (b*c);
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

