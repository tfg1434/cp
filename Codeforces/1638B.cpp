#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> even, odd;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x % 2 == 0) even.push_back(x);
            else odd.push_back(x);
        }

        if (is_sorted(even.begin(), even.end()) && is_sorted(odd.begin(), odd.end())) 
            cout << "YES" << endl;
        else 
            cout << "NO" << endl;
    }
    
    return 0;
}

