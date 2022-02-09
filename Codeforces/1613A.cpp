#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        pair<int, int> a, b;
        cin >> a.first >> a.second >> b.first >> b.second;
        
        double x = a.second + log10(a.first);
        double y = b.second + log10(b.first);
        
        if (abs(x - y) < 1e-9) cout << '=' << endl;
        else if (x > y) cout << '>' << endl;
        else cout << '<' << endl;
    }

    return 0;
}
