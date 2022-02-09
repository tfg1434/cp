/*
ID: toronto4
TASK: sprime
LANG: C++14
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

const int primishes[] {1, 3, 7, 9}; //other numbers are divisible
const int primes[] {2, 3, 5, 7};

bool isPrime(int n) {
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    // This is checked so that we can skip
    // middle five numbers in below loop
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;

    return true;
}

void solve(int n, int count) {
    if (count == 0) cout << n << '\n';
    
    n *= 10;
    
    for (int primish : primishes) {
        if (isPrime(n + primish))
            solve(n + primish, count - 1);
    }
}

int main() {
    freopen("sprime.in", "r", stdin);
    freopen("sprime.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;
    
    for (int prime:primes) {
        solve(prime, N-1);
    }

    return 0;
}
