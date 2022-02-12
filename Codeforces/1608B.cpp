#include <bits/stdc++.h>
using namespace std;

int T;


#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n, a, b; cin >> n >> a >> b;

        if (a+b+2 > n || abs(a-b) > 1) {
            cout << -1 << endl;
            continue;
        }

        int l = 1, r = n;
        bool yesno = a > b;
        for (int i = 1; i <= n; i++) {
            if (yesno) cout << l++ << " ";
            else cout << r-- << " ";

            if (i <= a + b) yesno = !yesno;
        }

        cout << endl;

        // vector<int> v;
        // if (a + b + 2 > n || abs(a-b) > 1) {
            // cout << -1 << endl;
            // continue;
        // }

        // if (a > b) {
            // for (int i = 1; i < ( a+b ) / 2 + 2; i++) {
                // v.push_back(i);
                // v.push_back(n - i + 1);
            // }
            // for (int i = n - a; n > a; i--) 
                // v.push_back(i);

        // } else if (a < b) {
            // for (int i = 1; i < (a+b) / 2 + 2; i++) {
                // v.push_back(n - i + 1);
                // v.push_back(i);
            // }
            
            // for (int i = b + 1; i < n-b+1; i++) 
                // v.push_back(i);
            
        // } else if (a == b) {
            // for (int i = 1; i < (a+b) / 2 + 1; i++) {
                // v.push_back(n - i + 1);
                // v.push_back(i);
            // }

            // for (int i = n-a; n > a; i--) {
                // if (v.size() < n) {
                    // v.push_back(i);
                // } else {
                    // break;
                // }
            // }
        // }
        
        // for (auto i : v) cout << i << " ";
        // cout << endl;
    }    
    
    return 0;
}

