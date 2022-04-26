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
        string s; cin >> s;
        vector<ll> a(n);
        map<ll, vector<ll>> m;
        m[0].push_back(-1); //add a 0 to the front of the prefix sum array
        for (ll i = 0; i < n; i++) a[i] = s[i] - '0' - 1;

        ll sum = 0;
        for (ll i = 0; i < n; i++) {
            sum += a[i];
            m[sum].push_back(i);
        }

        ll ans = 0;
        for (auto [x, y] : m) {
            ll z = y.size();
            ans += z*(z-1)/2;//C(z, 2)
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

