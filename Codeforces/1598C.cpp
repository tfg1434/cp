#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> v(n);
        map<int, int> m;
        for (auto& i : v) {
            cin >> i;
            m[i]++;
        }
        ll sum = accumulate(v.begin(), v.end(), 0ll);
        if (( 2 * sum ) % n != 0) {
            cout << 0 << endl;
            continue;
        }

        ll ans = 0;
        ll need = 2 * sum / n;
        for (int i = 0; i < n; i++) {
            int a = v[i];
            int b = need - a;
            if (m.count(b)) ans += m[b];
            if (a == b) ans--; //don't double count
        }

        cout << ans / 2 << endl;
    }    
    
    return 0;
}

