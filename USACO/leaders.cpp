#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll INFF = 1e18;

int main() {
    ll n; cin >> n;
    string s; cin >> s;
    vector<ll> e(n); for (auto& x : e) {
        cin >> x;
        x--;
    }
    vector<ll> kh, kg;
    ll lh = s.find('H'), rh=s.rfind('H'), lg=s.find('G'), rg=s.rfind('G');
    vector<ll> isKg(n+1, 0), isKh(n+1, 0);
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'G') {
            if (i <= lg && e[i] >= rg) {
                kg.push_back(i);
                isKg[i] = 1;
            }
        }
        if (s[i] == 'H') {
            if (i <= lh && e[i] >= rh) {
                kh.push_back(i);
                isKh[i] = 1;
            }
        }
    }

    ll ans = 0;
    for (ll i = 0; i < n; i++) {
        if (s[i] == 'G') {
            if (isKg[i]) {
                for (ll j = 0; j < kh.size(); j++) {
                    if (kh[j] > i) ans++;
                }
            } else {
                for (ll j = i; j <= e[i]; j++) {
                    if (isKh[j]) ans++;
                }
            }
        } else {
            if (isKh[i]) {
                for (ll j = 0; j < kg.size(); j++) {
                    if (kg[j] > i) ans++;
                }
            } else {
                for (ll j = i; j <= e[i]; j++) {
                    if (isKg[j]) ans++;
                }
            }
        }        
    }

    cout << ans << endl;
    
    return 0;
}
