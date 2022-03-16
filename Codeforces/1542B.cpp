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
        ll n, a, b; cin >> n >> a >> b;
        //n can be represented a^x + by
        //thus if you subtract a^k from n and you get a multiple of b
        //n is in S.
        bool ok = false;
        ll p = 1;
        while (p <= n) {
            if ((n-p) % b == 0) {
                ok = true;
                break;
            }

            p *= a;
            if (a == 1) break;
        }

        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }    
    
    return 0;
}

