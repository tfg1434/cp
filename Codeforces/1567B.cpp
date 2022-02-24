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
        int a, b; cin >> a >> b;
        
        //https://www.geeksforgeeks.org/calculate-xor-1-n/
        int ans, xr;
        if (a % 4 == 1) xr = a-1;
        else if (a % 4 == 2) xr = 1;
        else if (a % 4 == 3) xr = a;
        else xr = 0;

        if (xr == b) ans = a;
        //add x xor b to the array
        else if ((xr ^ b) != a) ans = a + 1;
        //x xor b == a. have to add x xor b xor 1
        else ans = a + 2;

        cout << ans << '\n';
    }    
    
    return 0;
}

