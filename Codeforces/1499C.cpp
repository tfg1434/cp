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
        //not necessarily always set, need to use INF instead of INFF
        ll minOdd = INF, minEven = INF;
        ll ans = INFF, sum = 0, cOdd = 0, cEven = 0;

        for (int i = 1; i <= n; i++) {
            ll x; cin >> x;
            sum += x;

            if (i % 2) minOdd = min(minOdd, x), cOdd++;
            else minEven = min(minEven, x), cEven++;

            ans = min(ans, sum+minOdd*(n-cOdd)+minEven*(n - cEven));
        }

        cout << ans << '\n';


        // int n; cin >> n;
        // vector<ll> c(n);
        // for (auto& x : c) cin >> x;

        // ll ans = INFF;
        // for (int k = 2; k <= n; k++) {
            // ll sumOdd = 0, sumEven = 0;
            // ll minOdd = INFF, minEven = INFF, cOdd = 0ll, cEven = 0ll;
            // for (int j = 0; j < k; j++) {
                // if (j % 2) {
                    // sumOdd += c[j];
                    // cOdd++;
                    // minOdd = min(minOdd, c[j]);
                // } else {
                    // sumEven += c[j];
                    // cEven++;
                    // minEven = min(minEven, c[j]);
                // }
            // }

            // ans = min(ans, sumOdd + minOdd*(n - cOdd) + sumEven + minEven*(n - cEven));

        // }

        // cout << ans << '\n';
    }    
    
    return 0;
}

