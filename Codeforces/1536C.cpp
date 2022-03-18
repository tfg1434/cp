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
        string s; cin >> s;

        auto ratio = [](int a, int b) {
            int g = gcd(a, b);
            a /= g; b /= g;

            return make_pair(a, b);
        };

        int d = 0, k = 0;
        map<pii, int> m;
        for (char c : s) {
            if (c == 'D') d++;
            else k++;

            cout << ++m[ratio(d, k)] << ' ';
        }
        cout << '\n';
    }    
    
    return 0;
}

