#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr ll MOD = 2000000011;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
ll n;

ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % MOD;
        b >>= 1;
        a = a * a % MOD;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T;
    for (int i = 1; i <= T; ++i) {
        cin >> n;
        ll ans;
        if (n == 1) ans = 1;
        else ans = binpow(n, n - 2);
        cout << "Case #" << i << ": " << ans << '\n';
    }    
    
    return 0;
}

