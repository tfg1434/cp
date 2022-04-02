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
        int s, d; cin >> s >> d;
        if (s < d) {
            cout << "impossible" << endl;
            continue;
        }
        //0/2 != und
        // if (s == d) {
            // cout << s << ' ' << 0 << endl;
            // continue;
        // }
        int gap = s - d;
        int b = gap / 2, a = d + b;
        if (a < b) swap(a, b);
        if (a + b == s && a - b == d) {
            cout << a << ' ' << b << endl;
        } else {
            cout << "impossible" << endl;
        }
    }    
    
    return 0;
}

