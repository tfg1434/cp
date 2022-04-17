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
        vector<ll> f(n+1, 0), last(n+1, 0), a(n+1), ans(n+1, -1);
        for (ll i = 1; i <= n; i++) cin >> a[i];

        for (ll i = 1; i <= n; i++) {
            ll x = a[i];
            f[x] = max(f[x], i - last[x]);
            last[x] = i;
        }
        for (ll x = 1; x <= n; x++) {
            //lemma: k >= p_1 and k >= n - p_m + 1
            f[x] = max(f[x], n - last[x] + 1);

            for (ll j = f[x]; j <= n && ans[j] == -1; j++) 
                ans[j] = x;
        }

        for (ll i = 1; i <= n; i++) cout << ans[i] << ' ';
        cout << '\n';
    }    
    
    return 0;
}

