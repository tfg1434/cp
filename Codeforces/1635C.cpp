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
        for (auto& i : a) cin >> i;

        if (a[n-2] > a[n-1]) {
            cout << -1 << '\n';
        } else {
            if (a[n-1] < 0) {
                if (is_sorted(all(a))) {
                    cout << 0 << '\n';
                } else {
                    cout << -1 << '\n';
                }
            } else {
                cout << n-2 << '\n';
                for (int i = 0; i < n-2; i++) 
                    cout << i+1 << ' ' << n-1 << ' ' << n << '\n';
            }
        }
    }    
    
    return 0;
}

