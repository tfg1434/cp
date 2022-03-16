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
        string s, t; cin >> s >> t;

        int i, j;
        for (i = s.size()-1, j = t.size()-1; i >= 0 && j >= 0; ) {
            if (s[i] == t[j]) {
                i--; j--;
                continue;
            }
            i -= 2;
        }

        if (j >= 0) cout << "NO\n";
        else cout << "YES\n";
    }    
    
    return 0;
}

