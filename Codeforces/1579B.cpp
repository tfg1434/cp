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
        int n; cin >> n;
        vector<int> a(n);
        for (auto& i : a) cin >> i;

        int k = 0;
        vector<pair<int, int>> ans;

        for (int i = 0; i < n; i++) {
            int idx = max_element(a.begin(), a.end()) - a.begin();
            if (idx != n - 1 - i)
                ans.push_back({idx + 1, n-i});
            
            //shift to the left and delete is the same thing
            a.erase(a.begin() + idx);
        }

        cout << ans.size() << '\n';
        for (const auto [a, b] : ans) {
            cout << a << ' ' << b << ' ' << 1 << '\n';
        }
    }    
    
    return 0;
}

