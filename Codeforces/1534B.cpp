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
        ll ans = 0;
        int n; cin >> n;
        vector<int> a(n+2, 0);
        for (int i = 1; i <= n; i++) cin >> a[i];

        for (int i = 1; i <= n+1; i++) ans += abs(a[i] - a[i-1]);
        for (int i = 1; i <= n; i++) 
            if (a[i] > a[i+1] && a[i] > a[i-1]) 
                ans -= a[i] - max(a[i-1], a[i+1]);
        
        cout << ans << '\n';
    }    
    
    return 0;
}

