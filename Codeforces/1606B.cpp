#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        ll n, k; cin >> n >> k;
        ll ans = 0;
        ll total = 1;
        while (total < k) {
            total *= 2;
            ans++;
        }
        //+ k - 1 for ceiling division
        if (total < n) ans += (n - total + k - 1) / k;

        cout << ans << '\n';
    }    
    
    return 0;
}

