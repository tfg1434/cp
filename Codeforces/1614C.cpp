#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;
constexpr int mod = 1e9 + 7;


ll binpow(ll a, ll b) {
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % mod;
        b >>= 1;
        a = a * a % mod;
    }

    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n, m; cin >> n >> m;
        
        int ans = 0;
        for (int i = 0; i < m; i++) {
            int l, r, x; cin >> l >> r >> x;
            ans |= x;
        }

        cout << (binpow(2, n-1) * ans) % mod << '\n';
    }    
    
    return 0;
}

