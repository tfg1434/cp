#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int h, p; cin >> h >> p;

        ll k = ceil(log2(p));
        //every level of the tree can be completed in one minute
        if (k >= h) {
            cout << h << '\n';
            continue;
        }

        ll b = (1ll << k) - 1ll;
        ll c = (1ll << h) - 1ll;
        //total nodes - in one step == c - b
        ll ans = ceil((c-b) * 1.0 / p) + k;
        cout << ans << '\n';
    }    
    
    return 0;
}

