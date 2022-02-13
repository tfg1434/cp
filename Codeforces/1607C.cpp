#include <bits/stdc++.h>
using namespace std;

int T;


#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& i : a) cin >> i;
        sort(a.begin(), a.end());

        int ans = INT_MIN;
        for (int i = 0; i < n - 1; i++) {
            ans = max(ans, a[i + 1] - a[i]);
        }
        ans = max(a[0], ans);

        cout << ans << '\n';
    }    
    
    return 0;
}

