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
        int N; cin >> N;
        
        int ans = 0;
        for (int a = 3; a*a <= 2*N-1; a += 2) {
            ans++;
        }

        cout << ans << '\n';
        // ll a, b, c = 0ll;
        // ll m = 2; //..n+1
        // int ans = 0;
        // while (c < N) {
            // for (ll n = 1ll; n < m; n++) {
                // a = m * m - n*n;
                // b = 2ll * m * n;
                // c = m * m + n * n;

                // if (c > N) break;

                // if (a*a - 2ll*b == 1ll) ans++;
            // }
        // }

        // cout << ans << '\n';
    }    
    
    return 0;
}

