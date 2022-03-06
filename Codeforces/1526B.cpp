#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


void solve() {
    int n; cin >> n;

    for (int i = 0; i <= 15; i++) {
        if (n % 11 == 0) {
            cout << "YES" << endl;
            return;
        }

        n -= 111;
        if (n < 0) break;
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

