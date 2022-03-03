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
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        sort(all(a));

        if (n == 2) {
            cout << a[0] << ' ' << a[1] << '\n';
            continue;
        }

        int mn = INT_MAX;
        int pos = -1;
        for (int i = 0; i < n-1; i++) {
            if (a[i+1] - a[i] < mn) {
                mn = a[i+1] - a[i];
                pos = i;
            }
        }

        cout << a[pos] << ' ';

        for (int i = pos + 2; i < n; i++) 
            cout << a[i] << ' ';
        for (int i = 0; i < pos; i++) 
            cout << a[i] << ' ';

        cout << a[pos + 1] << '\n';
    }    
    
    return 0;
}

