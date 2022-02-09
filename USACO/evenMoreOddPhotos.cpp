#include <bits/stdc++.h>
using namespace std;

#define ll long long

int N, O, E;

//NUMBER, NOT WAYS
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int a;
        cin >> a;

        if (a % 2 == 0) E++;
        else O++;    
    }

    while (O > E) {
        O -= 2;
        E++;
    }
    if (E > O+1) E = O+1;
    
    cout << E+O << endl;

    return 0;
}

