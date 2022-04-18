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


ll sum(ll n) {
    ll res = 0;
    while (n > 0) {
        res += n % 10;
        n /= 10;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        ll n, s; cin >> n >> s;
        ll ans = 0;

        //corner case
        if (sum(n) <= s) {
            cout << 0 << '\n';
            continue;
        }

        ll pw = 1;
        for (ll i = 0; i < 18; i++) {
            ll x = (n / pw) % 10;
            ll cost = pw * ((10 - x) % 10);
            n += cost;
            ans += cost;
            if (sum(n) <= s) {
                cout << ans << '\n';
                break;
            }
            pw *= 10;
        }
    }    
    
    return 0;
}

