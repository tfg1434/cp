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
        string s; cin >> s;
        int i = s.find("11");
        int j = s.rfind("00");

        cout << (i != -1 && j != -1 && i < j ? "NO" : "YES") << endl;
        // string s; cin >> s;
        // int idx = -1;
        // for (int i = 0; i < s.size(); i++) {
            // if (s[i] == '1') {
                // idx = i;
                // break;
            // }
        // }

        // if (idx == -1) {
            // cout << "YES" << '\n';
            // continue;
        // }

        // bool ans = true;
        // for (int i = idx+1; i < s.size() - 1; i++) {
            // if (s[i] == '0' && s[i+1] == '0') {
                // ans = false;
                // break;
            // }
        // }

        // if (ans) cout << "YES" << '\n';
        // else cout << "NO" << '\n';
    }    
    
    return 0;
}

