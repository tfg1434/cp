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
        vector<int> xs, ys;
        for (int i = 0; i < n; i++) {
            int x, y; cin >> x >> y;
            xs.push_back(x);
            ys.push_back(y);
        }
        sort(all(xs));
        sort(all(ys));

        if (n % 2 == 1) cout << 1 << '\n';
        else {
            ll dx = xs[n/2] - xs[n/2 - 1] + 1;
            ll dy = ys[n/2] - ys[n/2 - 1] + 1;
            cout << dx*dy << '\n';
        }
    }    
    
    return 0;
}

