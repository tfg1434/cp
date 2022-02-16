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
        char c; cin >> c;
        string s; cin >> s;

        int a = 0, x = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == c) {
                x = i+1;
                a++;
            }
        }

        if (a == n) {
            cout << 0 << endl;
            continue;
        }
        if (x > n / 2) {
            cout << 1 << endl << x << endl;
            continue;
        }
        cout << 2 << endl << n << ' ' << n-1 << endl;
    }    
    
    return 0;
}

