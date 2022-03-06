#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<ll> fact(17, 1);
    for (ll i = 1; i <= 16; i++) fact[i] = fact[i - 1] * i;

    cin >> T;
    while (T--) {
        ll n; cin >> n;
        int ans = __builtin_popcountll(n);

        for (int mask = 0; mask < (1 << 16); mask++) {
            ll sum = 0;
            int cnt = 0;

            for (int i = 0; i < 16; i++)
                if (mask & (1 << i)) {
                    sum += fact[i+1];
                    cnt++;
                }

            if (sum > n) continue;

            ll rem = n - sum;
            //rem can't have 0th bit set if 0! added
            //rem can't have 1th bit set if 1! added
            if (((mask & 1) && (rem & 1)) || ((mask & 2) && (rem & 2))) continue;

            //# of 2! needed to make a power of 2 = popcount
            ans = min(ans, __builtin_popcountll(rem) + __builtin_popcount(mask));
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

