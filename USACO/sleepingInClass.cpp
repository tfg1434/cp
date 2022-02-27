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
        for (auto& x : a) cin >> x;

        vector<int> pre(n);
        pre[0] = a[0];
        for (int i = 1; i < n; i++) 
            pre[i] = pre[i-1] + a[i];

        int ans = INT_MIN;
        for (auto x : pre) {
            int i = 0, sum = 0, m = 0;

            while (i < n) {
                sum += a[i];
                i++;

                if (sum == x) {
                    m++;
                    sum = 0;
                } else if (sum > x) {
                    m = -1;
                    break;
                }
            }

            if (m > ans) ans = m;
        }

        cout << n - ans << "\n";
    }    
    
    return 0;
}

