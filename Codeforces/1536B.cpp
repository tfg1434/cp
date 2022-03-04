#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


void solve() {
    int n; cin >> n;
    string s; cin >> s;

    char a = 'a', z = 'z';
    for (char i = a; i <= z; i++)
        if (s.find(i) == string::npos) {
            cout << i << endl;
            return;
        }
    for (char i = a; i <= z; i++)
        for (char j = a; j <= z; j++) {
            string x = "";
            x.push_back(i);
            x.push_back(j);
            if (s.find(x) == string::npos) {
                cout << x << endl;
                return;
            }
        }
    for (char i = a; i <= z; i++)
        for (char j = a; j <= z; j++)
            for (char k = a; k <= z; k++) {
                string x = "";
                x.push_back(i);
                x.push_back(j);
                x.push_back(k);
                if (s.find(x) == string::npos) {
                    cout << x << endl;
                    return;
                }
            }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}

