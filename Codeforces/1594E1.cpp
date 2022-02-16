#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int k; cin >> k;
    ll ans = 1;
    for (int i = 0; i < k - 1; i++) {
        ans *= 4;
        ans %= 1000000007LL;
        ans *= ans;
        ans %= 1000000007LL;
    }
    ans *= 6;
    ans %= 1000000007LL;

    cout << ans << '\n';

    return 0;
}

