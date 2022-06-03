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

constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr ll MAX_FACT = 300000;
vector<ll> fact(MAX_FACT+1, 1ll), inv(MAX_FACT+1, 1ll);


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    ll n, m; while (cin >> n >> m) {
        for (ll i = 1; i <= MAX_FACT; i++) {
            fact[i] = (fact[i-1] * i) % m;
        }

        ll ans = 0;
        for (ll l = 1; l <= n; l++) {
            ll x = (fact[l] * fact[n-l+1]) % m;
            x = (x * (n-l+1)) % m;
            ans = (ans + x) % m;
        }

        cout << ans << '\n';
    }        
    
    return 0;
}

