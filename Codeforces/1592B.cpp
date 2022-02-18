#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


void solve() {
    int n, x; cin >> n >> x;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    vector<int> b = a;
    sort(all(b));

    // if (x <= n / 2 || a == b) {
        // cout << "YES\n";
        // continue;
    // }
    // if (x >= n) {
        // cout << "NO\n";
        // continue;
    // }

    int l = n-x, r = x-1;
    for (int i = l; i <= r; i++) {
        if (a[i] != b[i]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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

