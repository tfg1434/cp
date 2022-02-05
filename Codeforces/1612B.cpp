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
            right.insert(item);
        } else if (item > a && left.size() < n / 2) {
            left.insert(item);
        }
    }
    
    if (left.size() == n / 2 && right.size() == n / 2 && *min_element(left.begin(), left.end()) == a && *max_element(right.begin(), right.end()) == b) {
        for (const int item:left) {
            cout << item << " ";
        }
        for (const int item:right) {
            cout << item << " ";
        }    
    } else {
        cout << -1;
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
