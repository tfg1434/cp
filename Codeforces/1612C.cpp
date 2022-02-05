#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, K;
ll X;

ll sum(int x) {
    return static_cast<ll>(x) * (x + 1) / 2;    
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> K >> X;
        ll l = 1, r = 2 * K - 1;
        
        ll ans = 2*K - 1;
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll count;
            
            if (mid < K) {
                count = sum(mid); 
            } else {
                count = sum(K) + sum(K - 1) - sum(2 * K - 1 - mid);
            }
            
            if (count >= X) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        cout << ans << endl;
    }

    return 0;
}
