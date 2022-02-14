#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;


void solve() {
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    for (int i = 0; i < n-1; i++) {
        if (a[i] > a[i+1]) {
            if (( ( a[i] + a[i+1] ) % 2 ) == 1)
                swap(a[i], a[i+1]);
            else {
                cout << "NO" << endl;
                return;
            }
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

