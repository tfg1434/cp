#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr ll MOD = 32768;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
ll n;
// vector<int> divs = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768 };


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll x; cin >> x;
        //corner case
        if (x == 0) {
            cout << "0\n";
            continue;
        }

        for (int j = 0; j <= 15; j++) {
            for (int k = 0; k <= j; k++) {
                if ((x+k) * (1<<(j-k)) % MOD == 0) {
                    cout << j << ' ';
                    goto HELL;
                }
            }

        }

        HELL:;

        //my cool ffs solution didnt work :'(
        // ll cost = 0;
        // if (x % 2 == 1) x++, cost++;
        // cost += 15 - __builtin_ffs(x) + 1;

        // cout << min(cost, 32768 - x) << ' ';
    }



    return 0;
}

