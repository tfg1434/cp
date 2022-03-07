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
        int n, x; cin >> n >> x;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        //compute the sum of the greatest contiguous subarray
        //for each length
        vector<int> maxSum(n+1);
        for (int l = 1; l <= n; l++) {
            int res = INT_MIN, curr = 0;

            for (int j = 0; j < l; j++) curr += a[j];
            res = max(res, curr);
            for (int j = l; j < n; j++) {
                curr += a[j]; curr -= a[j-l];
                res = max(res, curr);
            }
            maxSum[l] = res;
        }

        for (int k = 0; k <= n; k++) {
            int ans = 0;
            for (int l = 0; l <= n; l++) {
                ans = max(ans, maxSum[l] + min(k, l) * x);
            }

            cout << ans << ' ';
        }

        cout << '\n';
    }    
    
    return 0;
}

