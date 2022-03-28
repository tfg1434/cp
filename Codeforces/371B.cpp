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


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int a, b; cin >> a >> b;
    int a2 = 0, a3 = 0, a5 = 0;
    while (a % 2 == 0) {
        a /= 2;
        ++a2;
    }
    while (a % 3 == 0) {
        a /= 3;
        ++a3;
    }
    while (a % 5 == 0) {
        a /= 5;
        ++a5;
    }
    int b2 = 0, b3 = 0, b5 = 0;
    while (b % 2 == 0) {
        b /= 2;
        ++b2;
    }
    while (b % 3 == 0) {
        b /= 3;
        ++b3;
    }
    while (b % 5 == 0) {
        b /= 5;
        ++b5;
    }

    if (a != b) {
        cout << -1 << endl;
    } else {
        cout << abs(a2 - b2) + abs(a3 - b3) + abs(a5 - b5) << endl;
    }
    
    return 0;
}

