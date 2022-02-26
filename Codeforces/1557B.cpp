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
        int n, k; cin >> n >> k;
        vector<pair<int, int>> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i].first;
            a[i].second = i;
        }
        sort(all(a));

        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (a[i-1].second != a[i].second - 1) ans++;
        }

        if (ans <= k) cout << "YES\n";
        else cout << "NO\n";
    }    
    
    return 0;
}

