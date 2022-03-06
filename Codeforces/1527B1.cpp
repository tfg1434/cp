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
        string s; cin >> s;

        int c0 = 0, c1 = 0;
        for (char c : s) {
            if (c == '0') c0++;
            else c1++;
        }

        if (c0 % 2 == 0 || c0 == 1) cout << "BOB" << endl;
        else cout << "ALICE" << endl;
    }    
    
    return 0;
}

