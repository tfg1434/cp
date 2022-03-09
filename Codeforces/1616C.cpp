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
        for (auto& x: a) cin >> x;

        //do we need to consider the base case?
        int ans = n-1;

        for (int i = 0; i < n; i++) {
            for (int j = i+1; j < n; j++) {
                int cnt = 0;
                for (int k = 0; k < n; k++) {
                    if ((a[j] - a[i]) * (k - i) != (a[k] - a[i]) * (j - i)) cnt++;
                }

                ans = min(ans, cnt);
            }
        }

        cout << ans << endl;
    }    
    
    return 0;
}

