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
    
    ll n; while (cin >> n) {
        vector<ll> a(n);
        for (auto& x : a) cin >> x;

        //pre[0] = gcd(a[1], a[2], ..., a[n-1]);
        //pre[1] = gcd(a[2], a[3], ..., a[n-1]);
        vector<ll> preGcd(n, 0);
        preGcd[n-2] = a[n-1];
        for (ll i = n-3; i >= 0; i--) 
            preGcd[i] = gcd(preGcd[i+1], a[i+1]);
        
        for (ll i = 0; i < n-1; i++) 
            preGcd[i] = lcm(a[i], preGcd[i]);

        ll ans = 0;
        for (ll i = 0; i < n; i++) 
            ans = gcd(ans, preGcd[i]);

        cout << ans << '\n';
    }
    
    return 0;
}

