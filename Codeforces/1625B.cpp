#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;
map<int, int> M;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        M.clear();
        int ans = -1;

        for (int i = 1; i <= n; ++i) {
            int x;
            cin >> x;
            
            //loop through neighbouring same numbers (same bc need some common number):
            //found another before?
            //extend the array all the way to the left. right array is always rightmost
            if (M[x]) ans = max(ans, n - i + M[x]);
            
            M[x] = i;
        }
        
        cout << ans << endl;
    }

    return 0;
}
