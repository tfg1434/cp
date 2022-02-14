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
        vector<int> a(n);
        for (auto& i : a) cin >> i;
        
        if (n % 2 == 0) {
            cout << "YES" << endl;
            continue;
        }

        bool ok = false;
        for (int i = 0; i < n - 1; i++) {
            if (a[i+1] <= a[i]) {
                ok = true;
                break;
            }
        } 

        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }    
    
    return 0;
}

