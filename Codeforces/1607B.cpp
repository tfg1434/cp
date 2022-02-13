#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;
array<function<ll(ll)>, 4> a {  
    [](ll n) { return 0; },
    [](ll n) { return n; },
    [](ll n) { return -1; },
    [](ll n) { return -n - 1; },
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        ll x, n; cin >> x >> n;
        if (n == 0 || n % 4 == 0) {
            cout << x << endl;
            continue;
        }
        
        ll d = a[n % 4](n);

        cout << ( x % 2 == 0 ? x - d : x + d ) << endl;
    }    
    
    return 0;
}

