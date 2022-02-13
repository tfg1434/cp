#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n, k; cin >> n >> k;
        k++;
        vector<int> a(n); 
        for (auto& i : a) {
            cin >> i;
            i = pow(10, i);
        } 

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int val = k;
            if (i != n-1) val = min(val, a[i+1] / a[i] - 1);
            ans += a[i] * 1ll * val;
            k -= val;
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

