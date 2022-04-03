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
    
    string s;
    while (getline(cin , s)) {
        stringstream ss(s);
        vector<int> cs;
        int c; while (ss >> c) cs.push_back(c);
        getline(cin, s);
        stringstream xss(s);
        vector<int> ans;

        int x; while (xss >> x) {
            int y = cs[0];
            for (int i = 1; i < cs.size(); i++) 
                y = y*x + cs[i];
            ans.push_back(y);
        }

        for (int i = 0; i < ans.size(); i++) {
            if (i) cout << " ";
            cout << ans[i];
        }
        cout << '\n';
    }
    
    return 0;
}

