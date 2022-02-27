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
        string s, t; cin >> s >> t;

        bool ok = false;
        for (int i = 0; i < s.size(); i++) {
            string a = s.substr(0, i+1);
            string b = s.substr(0, i);
            reverse(all(b));
            a += b;

            if (a.find(t) != string::npos) {
                ok = true;
                break;
            }
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }    
    
    return 0;
}

