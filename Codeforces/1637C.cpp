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
        for (auto& i : a) cin >> i;

        if (*max_element(a.begin()+1, a.end()-1) == 1 || (n == 3 && a[1] % 2 == 1)) {
            cout << -1 << '\n';
            continue;
        } 
        
        ll ans = 0;
        //if odd, youll transfer once to even.
        for (int i = 1; i < n-1; i++) ans += (a[i] + 1) / 2;

        cout << ans << '\n';
    }    
    
    return 0;
}

