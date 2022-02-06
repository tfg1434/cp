#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        int n, k;
        string s;
        cin >> n >> k;
        cin >> s;
        string r = s;
        std::reverse(r.begin(), r.end());
        if (k == 0 || s == r) {
            cout << 1 << endl;
            continue;
        }
        
        cout << 2 << endl;
    }

    return 0;
}
