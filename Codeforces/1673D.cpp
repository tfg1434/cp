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


inline int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll b, q, y; cin >> b >> q >> y;
        ll c, r, z; cin >> c >> r >> z;
        ll e = b + q*(y-1);
        ll f = c + r*(z-1);

        if (c < b || e < f || f < b || e < c || r%q != 0 || (c-b)%q != 0) {
            cout << 0 << endl;
            continue;

        } else if (b > c - r || e < f + r) {
            cout << -1 << endl;
            continue;
        }

        ll ans = 0;
        for (ll p = 1; p*p <= r; p++) {
            if (r%p != 0) continue;

            if (lcm(p, q) == r) {
                ll x = ((r/p)*(r/p)) % MOD;
                ans = (ans + x) % MOD;
            }
            if (p*p != r && lcm(r/p, q) == r) {
                ll x = (p*p) % MOD;
                ans = (ans + x) % MOD;
            }
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

