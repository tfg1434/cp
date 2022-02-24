#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


void solve() {
    //there always exists a hamiltonian cycle in a tournament graph
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) cin >> a[i];

    //0 = i->n+1, 1 = n+1->i
    if (a[1] == 1) {
        cout << n+1 << ' ';
        for (int i = 1; i <= n; i++) cout << i << ' ';
        cout << '\n';
        return;
    }
    if (a[n] == 0) {
        for (int i = 1; i <= n+1; i++) cout << i << ' ';
        cout << '\n';
        return;
    }

    for (int i = 1; i <= n; i++) {
        if (a[i] == 0 && a[i+1] == 1) {
            for (int j = 1; j <= i; j++) cout << j << ' ';
            cout << n+1 << ' ';
            for (int j = i+1; j <= n; j++) cout << j << ' ';
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

