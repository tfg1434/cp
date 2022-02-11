#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;
array<int, 4> A, B, C;

bool wins(array<int, 4> a, array<int, 4> b) {
    int wins = 0, loss = 0;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (a[i] > b[j]) wins++;
            else if (a[i] < b[j]) loss++;
        }
    }

    return wins > loss;
}

bool solve() {
    cin >> A[0] >> A[1] >> A[2] >> A[3];
    cin >> B[0] >> B[1] >> B[2] >> B[3];

    for (int i = 1; i <= 10; i++) {
        for (int j = 1; j <= 10; j++) {
            for (int k = 1; k <= 10; k++) {
                for (int l = 1; l <= 10; l++) {
                    C[0] = i; C[1] = j; C[2] = k; C[3] = l;

                    if (wins(A, B) && wins(B, C) && wins(C, A)) return true;
                    if (wins(B, A) && wins(C, B) && wins(A, C)) return true;
                }
            }
        }
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T;
    while (T--) {
        if ( solve() ) cout << "yes" << endl;
        else cout << "no" << endl;
    }
    
    return 0;
}
