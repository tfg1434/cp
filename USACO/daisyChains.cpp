#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;

    int ans = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        vector<bool> seen(1001);

        for (int j = i; j < n; j++) {
            sum += a[j];
            seen[a[j]] = true;

            if (sum % (j-i+1) == 0 && seen[sum / (j-i+1)]) {
                // cout << sum << ' ' << j << ' ' << i << '\n';
                // cout << i+1 << ' ' << j+1 << '\n';
                ans++;
            }
        }
    }

    cout << ans << endl;
    
    return 0;
}

