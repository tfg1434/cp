#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T, N;

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> N;
        int b;

        for (int a = 2; true; ++a) {
            b = N - 1 - a;
            
            if (gcd(a, b) == 1) {
                cout << a << ' ' << b << ' ' << 1 << endl;
                break;
            }
        } 
    }

    return 0;
}
