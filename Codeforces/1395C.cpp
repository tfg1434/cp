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
constexpr ll MAXA = 1 << 9;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m; while (cin >> n >> m) {
        vector<ll> a(n), b(m);
        for (auto& x : a) cin >> x;
        for (auto& x : b) cin >> x;

        ll ans;
        for (ans = 0; ans < MAXA; ans++) {
            bool broke = false;
            for (ll i = 0; i < n; i++) {
                bool ok = false;
                for (ll j = 0; j < m; j++) {
                    if (((a[i] & b[j]) | ans) == ans) ok = true;
                }

                if (!ok) {
                    broke = true;
                    break;
                }
            }

            if (!broke) break;
        }

        cout << ans << '\n';
    }        
    
    return 0;
}

