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
    
    ll n; while (cin >> n) {
        vector<vector<ll>> f(n+1, vector<ll>(8, INFF));
        ll ans = INFF;
        f[0][0] = 0;

        for (ll i = 0; i < n; i++) {
            ll cost; string s; cin >> cost >> s;

            int sMask = 0;
            for (int j = 0; j < 3; j++) {
                //C, then B, then A
                char c = 'C' - j;
                bool has = false;
                for (char d : s) {
                    if (d == c) {
                        has = true;
                        break;
                    }
                }
                if (has) {
                    sMask |= (1 << j);
                }
            }

            for (ll mask = 0; mask < (1 << 3); mask++) {
                //dont take
                f[i+1][mask] = min(f[i+1][mask], f[i][mask]);
                //take sMask
                f[i+1][mask | sMask] = min(f[i+1][mask | sMask], f[i][mask] + cost);
            }
        }

        ans = f[n][7];
        if (ans == INFF) {
            cout << -1 << '\n';
        } else {
            cout << ans << '\n';
        }
    }        
    
    return 0;
}

