#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;

int setBitNumber(int n) {
    return (int)(log2(n));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        vector<int> p(n-1);
        for (int i = 1; i < n; ++i) {
            p[i-1] = i;
        }
        sort(p.begin(), p.end());
        int x = pow(2, setBitNumber(n - 1));
        for (int i = 1; i < x; ++i) {
            cout << i << ' ';
        }
        //use 0 to seperate first value with big bit set from biggest value w/o big bit set
        cout << "0 " << endl;
        for (int i = x; i < n; ++i) {
            cout << i << ' ';
        }
    }

    return 0;
}
