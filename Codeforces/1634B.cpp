#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        ll n, x, y;
        cin >> n >> x >> y;
        bool ans = x % 2 == 0; //false = odd, true = even. in terms of alice
        for (int i = 0; i < n; ++i) {
            int item; cin >> item;
            
//            if (item == 0) {
//                ans = item % 2 == 0;
//                continue;
//            }
            
            if ((item % 2 == 0) == ans) ans = true;
            else ans = false;
            
//            ans ^= item % 2;
        }
        
        if (ans == (y % 2 == 0)) cout << "Alice\n";
        else cout << "Bob\n";
    }

    return 0;
}
