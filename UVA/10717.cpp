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

inline int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }

inline int lcm(int a, int b) { return a / gcd(a, b) * b; }

void solve(int n, int t) {
    vector<int> cs(n);
    for (int i = 0; i < n; i++) {
        cin >> cs[i];
    }

    for (int i = 0; i < t; i++) {
        int h; cin >> h;
        int resA = 0, resB = INF;

        for (int j = 0; j < n; j++) {
            for (int k = j+1; k < n; k++) {
                for (int l = k+1; l < n; l++) {
                    for (int m = l+1; m < n; m++) {
                        int lc = lcm(cs[j], cs[k]);
                        lc = lcm(lc, cs[l]);
                        lc = lcm(lc, cs[m]);

                        int thisA = h / lc * lc;
                        int thisB = thisA;
                        if (thisB < h) thisB += lc;
                        resA = max(resA, thisA);
                        resB = min(resB, thisB);
                    }
                }
            }
        }

        cout << resA << " " << resB << endl;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, t;
    while (cin >> n >> t) {
        if (n == 0 && t == 0) break;
        solve(n, t);
    }
    
    return 0;
}

