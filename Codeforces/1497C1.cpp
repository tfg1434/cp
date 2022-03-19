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
        int n, k; cin >> n >> k;

        if (n % 2 == 1) {
            cout << n/2 << ' ' << n/2 << ' ' << 1 << '\n';
        } else {
            if (n % 4 == 0) {
                cout << n/2 << ' ' << n/4 << ' ' << n/4 << '\n';
            } else {
                cout << 2 << ' ' << n/2-1 << ' ' << n/2-1 << '\n';
            }
        }
    }    
    
    return 0;
}

