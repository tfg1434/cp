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
        int n; cin >> n;
        map<int, int> m;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            x -= i;
            ans += m[x];
            m[x]++;
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

