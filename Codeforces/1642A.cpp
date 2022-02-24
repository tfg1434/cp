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
        vector<int> x(3), y(3);
        for (int i = 0; i < 3; i++) cin >> x[i] >> y[i];

        int ans = 0;
        if (y[0] == y[1] && y[2] < y[1]) ans = abs(x[0] - x[1]);
        else if (y[1] == y[2] && y[0] < y[2]) ans = abs(x[1] - x[2]);
        else if (y[0] == y[2] && y[1] < y[0]) ans = abs(x[0] - x[2]);
        
        cout << ans << '\n';
    }    
    
    return 0;
}

