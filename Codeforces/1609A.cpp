#include <bits/stdc++.h>
using namespace std;

int T;


#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;

        vector<ll> a(n);
        for (ll &i : a) cin >> i;

        ll k = 0;
        for (int i = 0; i < n; i++) {
            while (a[i] % 2 == 0) {
                a[i] /= 2;
                k += 1;
            }
        }
        
        ll max = *max_element(a.begin(), a.end());
        ll ans = accumulate(a.begin(), a.end(), 0ll) - max + (max << k);

        cout << ans << endl;
    }    
    
    return 0;
}

