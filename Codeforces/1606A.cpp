#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        string s; cin >> s;
        if (s[0] == s[s.size() - 1]) {
            cout << s << endl;
            continue;
        }

        s[0] = s[s.size() - 1];
        cout << s << endl;
    }    
    
    return 0;
}

