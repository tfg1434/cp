#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


struct op {
    int i, j, x, y;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        auto mn = min_element(all(a));
        int idx = mn - a.begin();
        int val = *mn;

        cout << n-1 << '\n';
        for (int i = 0; i < n; i++) {
            if (i == idx) continue;
            cout << idx+1 << ' ' << i+1 << ' ' << val << ' ' << val + abs(idx-i) << ' ' << '\n';
        }
    }    
    
    return 0;
}

