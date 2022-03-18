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
int p[2005];


void solve() {
    int n; cin >> n;
    for (int i = 0; i < 2*n; i++) cin >> p[i];

    int idx = -1, cyc = (n % 2 == 0) ? 4 : 2*n;
    for (int i = 0; i < cyc; i++) {
        if (is_sorted(p, p + 2*n)) {
            idx = i;
            break;
        }

        if (i % 2 == 1) for (int j = 0; j < n; j++) swap(p[j], p[j+n]);
        else for (int j = 0; j < 2*n; j += 2) swap(p[j], p[j+1]);
    }

    //-1 or took
    cout << min(idx, cyc-idx) << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

