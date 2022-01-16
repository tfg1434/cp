/*
ID: toronto4
TASK: pprime
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

int main() {
//    freopen("pprime.in", "r", stdin);
//    freopen("pprime.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int A, B;
    cin >> A >> B;
    int* isPrime = new int[B];

    for (int i = 2; i*i < B; ++i) {
        if (!isPrime[i]) continue;
        for (int j = i*i; j < B; j += i)
            isPrime[j] = false;
                    
    }

    for (int i = A; i < B; ++i) {
        if (!isPrime[i]) continue;
        
        int digit;
        int rev = 0;
        int n = i;
        
        do {
            digit = n % 10;
            rev = (rev * 10) + digit;
            n = n / 10;
        } while (n != 0);
        
        if (i == rev) cout << i << '\n';
    }
    
    delete[] isPrime;
    return 0;
}

