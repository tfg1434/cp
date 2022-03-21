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
        int n; cin >> n;

        if (n % 2 == 1) {
            for (int i = 0; i < n; i++)
                for (int j = i+1; j < n; j++)
                    if (j - i <= n/2) cout << 1 << ' ';
                    else cout << -1 << ' ';
        } else {
            for (int i = 0; i < n; i++)
                for (int j = i+1; j < n; j++)
                    if (j - i < n/2) cout << 1 << ' ';
                    else if (j - i == n/2) cout << 0 << ' ';
                    else cout << -1 << ' ';
        }

        cout << endl;
    }    
    
    return 0;
}

