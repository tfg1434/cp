#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;

bool isHeroWin(ll hc, ll dc, ll hm, ll dm) {
//    return (hm + dc - 1) / dc <= (hc + dm - 1) / dm;
    return ceil( (double) hm / dc ) <= ceil( (double) hc / dm );
}

void solve() {
    ll hc, dc, hm, dm;
    ll k, w, a;
    cin >> hc >> dc >> hm >> dm;
    cin >> k >> w >> a;

    for (int i = 0; i <= k; ++i) {
        ll j = k - i;

        ll newHc = hc + i * a, newDc = dc + j * w;
        
        if (isHeroWin(newHc, newDc, hm, dm)) {
            cout << "YES" << endl;
            return;
        }
    }
    
    cout << "NO" << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        solve(); 
    }

    return 0;
}
