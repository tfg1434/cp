#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INFF = 1e18;

int main() {
    int T; cin >> T; while (T--) {
        string s; cin >> s; ll n = s.size();
        ll ans = INFF;
        for (ll i = 0; i < n-2; i++) {
            if (s[i+1] != 'O') continue;
            ans = min(ans, (ll)(s[i]!='M') + (s[i+2]!='O'));
        }

        if (ans == INFF) {
            cout << -1 << endl;
            continue;
        }
        cout << ans + n-3 << endl;
    } 
    
    return 0;
}
