#include <bits/stdc++.h>
using namespace std;

int T;


#define ll long long

void solve() {
    int n; cin >> n;

    vector<int> l, r, a(n);
    for (auto& i : a) cin >> i;
    for (auto i : a) {
        char c; cin >> c;
        if (c == 'B') l.push_back(i);
        else r.push_back(i);
    }

    sort(l.begin(), l.end());
    sort(r.begin(), r.end(), greater<int>());

    for (int i = 0; i < l.size(); i++) {
        int p = i+1;
        if (l[i] < p) {
            cout << "NO" << endl;
            return;
        }
    }
    for (int i = 0; i < r.size(); i++) {
        int p = n - i;
        if (r[i] > p) {
            cout << "NO" << endl;
            return;
        }
    }

    cout << "YES" << endl;
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

