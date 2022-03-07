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
        vector<int> a(n+1);

        int ans = 0;
        for (int i = 1; i <= n; i++)
            cin >> a[i];
        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j++) {
                for (int k = i; k <= j; k++)
                    if (!a[k])
                        ans++;
                ans += j - i + 1;
            }
        }
        cout << ans << '\n';
    }    
    
    return 0;
}

