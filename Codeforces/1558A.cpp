#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int a, b; cin >> a >> b;

        vector<int> ans;
        int d = abs(a-b) / 2;
        if ((a + b) % 2 == 0) {
            for (int i = d; i <= a + b - d; i += 2) {
                ans.push_back(i);
            }
        } else {
            for (int i = d; i <= a + b - d; i++) {
                ans.push_back(i);
            }
        }

        cout << ans.size() << '\n';
        for (auto i : ans) cout << i << ' ';
        cout << '\n';
    }    
    
    return 0;
}

