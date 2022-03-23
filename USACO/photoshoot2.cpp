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
    for (auto& x : a) cin >> x;
    for (auto& x : b) cin >> x;

    //instead of looping each time, let;s store the index
    vector<int> posB(n+1);
    for (int i = 1; i <= n; i++) posB[b[i-1]] = i;
    for (int i = 0; i < n; i++) a[i] = posB[a[i]];
    //B = 1..N
    
    int ans = 0, mx = 0;
    for (auto x : a) {
        if (x > mx) {
            mx = x;
        } else {
            ans++;
        }
    }
    // for (int i = 0; i < n; i++) {
        // bool needMove = false;
        // for (int j = 0; j < i; j++) {
            // if (a[j] > a[i]) 
                // needMove = true;
        // }

        // if (needMove) ans++;
    // }

    cout << ans << endl;
    
    return 0;
}
