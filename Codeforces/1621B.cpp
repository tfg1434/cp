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

        int mn_l = INT_MAX, cost_l = INT_MAX;
        int mx_r = INT_MIN, cost_r = INT_MAX;
        int mx_len = INT_MIN, cost_len = INT_MAX;
        for (int s = 1; s <= n; s++) {
            int l, r, c; cin >> l >> r >> c;

            if (l < mn_l) 
                mn_l = l, cost_l = c;
            if (l == mn_l)
                cost_l = min(cost_l, c);

            if (r > mx_r) 
                mx_r = r, cost_r = c;
            if (r == mx_r)
                cost_r = min(cost_r, c);

            if (mx_len < r - l + 1)
                mx_len = r - l + 1, cost_len = c;
            if (mx_len == r - l + 1)
                cost_len = min(cost_len, c);
            
            int ans = cost_l + cost_r;
            if (mx_len == mx_r - mn_l + 1)
                ans = min(ans, cost_len);

            cout << ans << '\n';
        }
    }    
    
    return 0;
}

