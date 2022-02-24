#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()



int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    sort(all(a));
    auto greater = [&](int x) {
        int res = 0;
        for (auto i : b) if (i >= x) res++;

        return res;
    };

    ll ans = 1;
    for (int i = n-1; i >= 0; i--) 
        ans *= greater(a[i]) - (n-1 - i);

    cout << ans << endl;
    
    return 0;
}

