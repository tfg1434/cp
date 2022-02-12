#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    string s; cin >> s;

    int ans = 0;
    for (int i = 0; i < (int) s.size(); i++) {
        int g = 0;
        int h = 0;

        for (int j = i; j < (int) s.size(); j++) {
            if (s[j] == 'G') g++;
            else h++;
            if (g + h >= 3 && ( g == 1 || h == 1 )) ans++;
            // else if (g + h > 3 && g != 1 && h != 1) break;
        }
    }

    cout << ans << endl;
    
    return 0;
}

