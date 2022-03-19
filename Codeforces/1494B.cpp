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
    
    int T; cin >> T; while (T--) {
        int n, U, R, D, L; cin >> n >> U >> R >> D >> L;

        bool ans = false;
        for (int mask = 0; mask < 16; mask++) {
            int rU = U, rR = R, rD = D, rL = L;

            if (mask & (1 << 0)) rL--, rU--;
            if (mask & (1 << 1)) rU--, rR--;
            if (mask & (1 << 2)) rR--, rD--;
            if (mask & (1 << 3)) rD--, rL--;

            if (min({ rU, rR, rD, rL }) >= 0 && max({ rU, rR, rD, rL }) <= n-2) ans = true;
        }

        cout << (ans ? "YES" : "NO") << '\n';
    }    
    
    return 0;
}

