#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> e(n); for (auto& x : e) {
        cin >> x;
        x--;
    }
    ll lg = s.find('G'), rg = s.rfind('G'), lh = s.find('H'), rh = s.rfind('H');
    vector<ll> isOG(n, 0), isOH(n, 0);
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'G') {
            if (i <= lg && e[i] >= rg) {
                isOG[i] = 1;
            }
        } else {
            if (i <= lh && e[i] >= rh) {
                isOH[i] = 1;
            }
        }
    }
    vector<ll> preOG(n+1), preOH(n+1);
    for (ll i = 0; i < n; i++) {
        preOG[i+1] = preOG[i] + isOG[i];
        preOH[i+1] = preOH[i] + isOH[i];
    }

    //(O.G., O.G.)
    ll ans = preOG[n] * preOH[n];
    //(listing, O.G.)
    for (ll i = 0; i < n; i++) {
        if (isOG[i] || isOH[i]) continue;

        if (s[i] == 'G') {
            ans += preOH[e[i]+1] - preOH[i+1];
        } else{
            ans += preOG[e[i]+1] - preOG[i+1];
        }
    }

    cout << ans << endl;
    
    return 0;
}
