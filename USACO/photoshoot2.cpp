#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    map<int, int> a, b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a[x] = i;
    }
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        b[x] = i;
    }

    int ans = 0;
    for (auto [num, idx] : a) {
        if (b[num] < idx) ans++;
    }

    cout << ans << '\n';
    
    return 0;
}

