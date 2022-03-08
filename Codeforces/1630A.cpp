#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


void solve() {
    int n, k; cin >> n >> k;
    //complement == i ^ (n-1)

    if (k == 0) {
        for (int i = 0; i < n / 2; i++) {
            cout << i << ' ' << (i ^ (n - 1)) << '\n';
        }
        return;
    }
    if (k == n-1 && n <= 4) {
        cout << -1 << '\n';
        return;
    }
    
    if (k == n-1) {
        cout << n-1 << ' ' << n-2 << '\n';
        cout << n-3 << ' ' << 1 << '\n';
        cout << 0 << ' ' << 2 << '\n';
        for (int i = 3; i < n/2; i++) {
            cout << i << ' ' << (i ^ (n - 1)) << '\n';
        }
        return;
    }

    cout << k << ' ' << n-1 << '\n';
    cout << 0 << ' ' << (k ^ (n - 1)) << '\n';
    for (int i = 1; i < n/2; i++) {
        if (i == k || i == ((n-1) ^ k)) continue;

        cout << i << ' ' << (i ^ (n - 1)) << '\n';
    }
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

