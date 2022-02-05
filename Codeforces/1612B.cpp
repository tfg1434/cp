#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    set<int> left, right, s;
    for (int i = 1; i <= n; ++i) {
        s.insert(i);
    }
    s.erase(a); s.erase(b);
    left.insert(a);
    right.insert(b);
    for (int i = a - 1; i >= 1; i--) {
        right.insert(i);
        s.erase(i);
    }
    for (int i = b + 1; i <= n; i++) {
        left.insert(i);
        s.erase(i);
    }

    for (const int item:s) {
        if (item < b && right.size() < n / 2) {
            if (right.count(item)) {
                cout << -1 << endl;
                return;
            }
            right.insert(item);
        } else if (item > a && left.size() < n / 2) {
            if (left.count(item)) {
                cout << -1 << endl;
                return;
            }
            left.insert(item);
        } else {
            cout << -1 << endl;
            return;
        }
//        if (item < b) {
//            if (right.count(item)) {
//                cout << -1 << endl;
//                return;
//            }
//            right.insert(item);
//        } else {
//            if (left.count(item)) {
//                cout << -1 << endl;
//                return;
//            }
//            left.insert(item);
//        }
    }

    for (const int item:left) {
        cout << item << " ";
    }
    for (const int item:right) {
        cout << item << " ";
    }
    cout << endl;
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
