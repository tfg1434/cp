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
constexpr int MAX_SIEVE = 1e7+5;
vector<bool> isPrime(MAX_SIEVE, true);


pii goldbach(int g) {
    int i = 2;
    for (int j = g - i; j > 2; j--) {
        if (isPrime[i] && isPrime[j]) {
            return {i, j};
        }
        i++;
    }
    assert(false);
    return {-1, -1};
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (ll i = 2; i*i <= MAX_SIEVE; i++) {
        if (isPrime[i])         
            for (ll j = i*i; j <= MAX_SIEVE; j += i)
                isPrime[j] = false;
    }

    int n;
    while (cin >> n) {
        // if (n % 2 == 0) n -= 2+2;
        // else n -= 2 + 3;
        // if (n <= 2) {
            // cout << "Impossible.\n";
            // continue;
        // }
        int sub = (n%2==0) ? 2+2 : 2+3;
        if (n - sub <= 2) {
            cout << "Impossible.\n";
            continue;
        }

        if (n % 2 == 0) {
            pii ans = goldbach(n - sub);
            cout << 2 << " " << 2 << " " << ans.first << " " << ans.second << "\n";
        } else {
            pii ans = goldbach(n - sub);
            cout << 3 << " " << 2 << " " << ans.first << " " << ans.second << "\n";
        }
    }
    
    return 0;
}

