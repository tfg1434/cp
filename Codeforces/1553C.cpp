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
        string s; cin >> s;
        int n = s.size();

        int ans = 9;
        int c0 = 0, c1 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) c0 += s[i] != '0';
            else c1 += s[i] == '1';

            //number of games left if you win half of them
            //(10-i) / 2
            if (c0 > c1 + (10-i) / 2) ans = min(ans, i);
            if (c1 > c0 + (9-i) / 2) ans = min(ans, i);
        }

        c0 = 0, c1 = 0;
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) c0 += s[i] != '1';
            else c1 += s[i] == '0';

            if (c0 > c1 + (10-i) / 2) ans = min(ans, i);
            if (c1 > c0 + (9-i) / 2) ans = min(ans, i);
        }

        cout << ans+1 << '\n';
    }    
    
    return 0;
}

