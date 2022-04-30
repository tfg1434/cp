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
    
    ll n;
    while (cin >> n) {
        ll pos = 0;
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++) {
            ll x; cin >> x;
            char op; cin >> op;
            ll y;
            if (op == 'R') y = pos + x;
            else if (op == 'L') y = pos - x;
            mp[x]++;
            mp[y]--;
            pos = y;
        }

        ll ans = 0, sum = 0;

        for (auto [x, y] : mp) cout << x << ' ' << y << '\n';

        ll prev = mp.begin()->first;
        for (auto [x, y]: mp) {
            if (sum >= 2) ans += x - prev;
            sum += y;
            prev = x;
        }

        cout << ans << '\n';
    }
    
    return 0;
}

