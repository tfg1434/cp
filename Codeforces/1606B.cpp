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
        int ans = 0;
        ll total = 1;
        while (total < n) {
            ans++;
            total += min(k, total);
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

