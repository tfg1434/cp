#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


bool isIt(string s, int i, char c) {
    if (i >= s.size()) return false;
    
    return s[i] == c;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<string> s(2); cin >> s[0] >> s[1];
        vector<int> dp(n+1, 0);
        vector<int> last(2, -1);

        auto MEX = [&](int i, bool is0, bool is1) {
            int mex = 0;
            if (is0) {
                if (is1) mex = 2;
                else mex = 1;
            }

            int idx = i;
            if (is0) idx = min(idx, last[0]);
            if (is1) idx = min(idx, last[1]);

            if (idx != -1) return mex + dp[idx-1];
            return INT_MIN;
        };

        for (int i = 1; i<=n; i++) {
            vector<int> v(2); 
            for (int j = 0; j < 2; j++) last[s[j][i-1]-'0'] = i;

            dp[i] = dp[i-1];
            dp[i] = max({dp[i], MEX(i, 1, 0), MEX(i, 0, 1), MEX(i, 1, 1) });
        }

        cout << dp[n] << '\n';
    }    
    
    return 0;
}

