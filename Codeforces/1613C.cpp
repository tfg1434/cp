#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, N;
ll H;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N >> H;
        vector<ll> a(N);
        for (auto &item:a) cin >> item;
        ll l = 1, r = 1e18;
        
        while (l <= r) {
            ll mid = (l + r) / 2; //mid == k
            ll total = mid; //account for last hit
            for (int i = 0; i < N - 1; i++) {
                total += min(a[i+1] - a[i], mid);
            }
            
            if (total < H) l = mid + 1;
            else r = mid - 1;
        }
        
        cout << r+1 << '\n';
    }

    return 0;
}
