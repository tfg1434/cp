#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;
int A, B, C;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        cin >> A >> B >> C;

        int d, target;
        
        d = C - B;
        target = B - d;
        //>= A b/c d must be int
        if (target >= A && target % A == 0 && target != 0) {
            cout << "yEs" << endl;
            continue;
        }
        
        d = (C - A) / 2;
        target = A + d;
        if (target >= B && (C - A) % 2 == 0 && target % B == 0 && target != 0) {
            cout << "yEs" << endl;
            continue;
        }
        
        d = B - A;
        target = B + d;
        if (target >= C && target % C == 0 && target != 0) {
            cout << "yEs" << endl;
            continue;
        }
        
        cout << "nO" << endl;
    }
        
    return 0;
}
