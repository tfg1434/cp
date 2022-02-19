#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


void solve() {
    int n; cin >> n;
    vector<int> a(n); vector<int> b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;

    sort(all(a)); sort(all(b));
    for (int i = 0; i < n; i++) {
        if (b[i] < a[i] || b[i] - a[i] > 1) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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

