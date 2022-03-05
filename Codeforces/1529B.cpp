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
        vector<int> a(n);
        int ans = 0;
        for (auto& x : a) {
            cin >> x;
            ans += x <= 0;
        }

        sort(all(a));
        int mn = INT_MAX;
        for (int x : a)
            if (x > 0) mn = min(mn, x);

        bool ok = mn != INT_MAX;
        for (int i = 1; i < n; i++) {
            if (a[i] > 0) continue;
            
            if (a[i] - a[i-1] < mn) ok = false;
        }
        
        if (ok) ans++;
        cout << ans << '\n';
    }    
    
    return 0;
}

