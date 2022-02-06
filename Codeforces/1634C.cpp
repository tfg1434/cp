#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        int n, k; //n = height, k = width
        cin >> n >> k;
        
        if (n % 2 == 1 && k > 1) {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j < k; j++) {
                cout << i + j * n << ' ';
            }
            cout << endl;
        }
    }

    return 0;
}
