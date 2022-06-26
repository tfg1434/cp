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
constexpr ll INFF = 1e17;


inline ll mul(ll a, ll b) {
    return (INFF / a > b ? a * b : INFF);
}
inline ll add(ll a, ll b) {
    return (a+b >= INFF ? INFF : a+b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n; while (cin >> n) {
        vector<ll> a(n);
        for (auto& x : a) cin >> x;
        sort(all(a));

        if (n <= 2) {
            cout << a[0] - 1 << endl;
            continue;
        }

        ll ans = accumulate(all(a), 0ll) - n;
        for (ll x = 1; ; x++) {
            ll currPow = 1, cost = 0;
            for (ll i = 0; i < n; i++) {
                cost = add(cost, abs(a[i] - currPow));
                currPow = mul(currPow, x);
            }

            if (currPow == INFF || currPow / x > ans + a[n-1]) break;
            ans = min(ans, cost);
        }

        cout << ans << endl;
    }
    
    return 0;
}

