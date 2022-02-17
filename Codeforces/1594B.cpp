#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


ll binpow(ll a, ll b) {
    ll res = 1;
    while (b > 0) {
        if (b & 1) {
            res = res * a;
            res %= 1000000007ll;
        }
        a = a * a;
        a %= 1000000007ll;
        b >>= 1;
    }
    return res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        ll po = 1, ans = 0;
        //10^9 fits in 32 bits
        for (ll i = 0; i < 31; i++) {
            //pow each time the binary representation of the idx
            //of the number has a 1.
            if (k & (1 << i)) ans = (ans + po) % 1000000007ll;

            po *= n;
            po %= 1000000007ll;
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

