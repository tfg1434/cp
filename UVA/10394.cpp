#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr ll MAX_S = 1e5 + 5;
constexpr ll MAX_P = 2*1e7 + 5;
vector<bool> isPrime(MAX_P, true);
vector<int> tPrime(MAX_P);


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 4; i <= MAX_P; i += 2) {
        isPrime[i] = false;
    }
    for (int i = 3; i*i <= MAX_P; i += 2) {
        if (isPrime[i]) {
            for (int j = i*i; j <= MAX_P; j += 2*i) {
                isPrime[j] = false;
            }
        }
    }

    int idx = 1;
    for (int i = 3; i <= MAX_P; i++) {
        if (isPrime[i] && isPrime[i+2])
            tPrime[idx++] = i;
    }
    
    int n;
    while (cin >> n) {
        cout << '(' << tPrime[n] << ", " << tPrime[n] + 2 << ')' << '\n';
    } 
    
    return 0;
}

