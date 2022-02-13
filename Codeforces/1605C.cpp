#include <bits/stdc++.h>
using namespace std;
#define ll long long

int T;
string arr[7] { "aa", "aba", "aca", "abca", "acba", "abbacca", "accabba", };

void solve() {
    int n; cin >> n;
    string s; cin >> s;

    for (auto substr : arr) {
        if (s.find(substr) != string::npos) {
            cout << substr.length() << '\n';
            return;
        }
    }

    cout << -1 << '\n';
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

