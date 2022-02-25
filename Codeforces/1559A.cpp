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

        sort(all(a));
        int ans = a[0];
        for (auto i : a) ans &= i;
        cout << ans << '\n';
    }    
    
    return 0;
}

