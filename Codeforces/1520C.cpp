#include <bits/stdc++.h>
using namespace std;
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
        int n; cin >> n;
        vector<int> a;

        if (n == 2) {
            cout << -1 << endl;
            continue;
        }

        for (int i = 2; i <= n * n; i += 2) {
            a.push_back(i);
        }
        for (int i = 1; i <= n * n; i += 2) {
            a.push_back(i);
        }

        for (int i = 0; i < n * n; i++) {
            cout << a[i] << ' ';
            if (i % n == n - 1) cout << '\n';
        }
    }    
    
    return 0;
}

