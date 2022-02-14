#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;


void solve() {
    int n; cin >> n;

    bool ok = true;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;

        bool found = false;
        for (int j = 2; j <= i+1; j++) {
            if (x % j != 0) {
                found = true;
                break;
            }
        }

        ok &= found;
    }

    if (ok) cout << "YES" << endl;
    else cout << "NO" << endl;
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

