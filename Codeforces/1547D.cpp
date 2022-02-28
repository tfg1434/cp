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
        int n, x; cin >> n >> x;
        cout << 0 << ' ';
        while (--n) {
            int y; cin >> y;
            cout << ((y | x) ^ y) << ' ';
            x |= y;
        }

        cout << endl;
    }    
    
    return 0;
}

