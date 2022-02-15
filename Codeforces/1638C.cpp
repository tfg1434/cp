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
        int n; cin >> n;
        int c = 0, mx = 0;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            mx = max(mx, x);
            if (mx == i+1) c++;
        }

        cout << c << endl;
    }    
    
    return 0;
}

