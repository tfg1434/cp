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
        ll n, m; cin >> n >> m;
        vector<ll> a(n+1);
        for (ll i = 1; i <= n; i++) cin >> a[i];
        vector<vector<ll>> fs(n+1);
        ll ans = INFF;
        for (ll i = 0; i < m; i++) {
            ll x, y; cin >> x >> y;
            fs[x].push_back(y);
            fs[y].push_back(x);
            ans = min(ans, a[x] + a[y]);
        }

        if (m % 2 == 0) {
            cout << 0 << endl;
            continue;
        }

        for (ll i = 1; i <= n; i++) {
            if (fs[i].size() % 2 == 1) {
                ans = min(ans, a[i]);
            }
        }

        if (ans == INFF) throw runtime_error("wtf");
        cout << ans << endl;
    }    
    
    return 0;
}

