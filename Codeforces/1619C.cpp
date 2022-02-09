#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;
ll A, S;

void solve() {
    cin >> A >> S;

    vector<int> b;

    while (S) {
        int x = A % 10; // last digit of A
        int y = S % 10; // last digit of S

        if (x <= y) {
            b.push_back(y - x);
            
        } else {
            S /= 10;
            y += 10 * (S % 10);

            if (y >= 10 && y <= 19) {
                b.push_back(y - x);
            } else {
                cout << -1 << endl;
                return;
            }
        }
        
        A /= 10;
        S /= 10;
    }
    
    if (A) {
        cout << -1 << endl;
        return;
    }

    auto iter = b.rbegin();
    while (*iter == 0) advance(iter, 1);
    for ( ; iter != b.rend(); ++iter) {
        cout << *iter;
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
