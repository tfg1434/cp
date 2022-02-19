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

        int c0 = 0, c1 = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x == 0) c0++;
            if (x == 1) c1++;
        }

        cout << (1ll << c0) * (1ll * c1) << '\n';
    }    
    
    return 0;
}

