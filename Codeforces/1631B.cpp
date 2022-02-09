#include <bits/stdc++.h>
using namespace std;

#define ll long long

int T;

void apply(vector<int> &v, int l, int r) {
    int k = (r - l + 1) / 2;
    for (int i = 0; i < k; i++) v[l+k+i] = v[l+i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> T; 
    while (T--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int& i : a) cin >> i;
        vector<int> b = a;
        std::reverse(b.begin(), b.end());
        
        int ans = 0;
        int x = 0;
        while (x < n) {
            if (b[x] == b[0]) {
                x++;
                continue;
            }
            
            ans++;
            x *= 2;
        }
        
        cout << ans << endl;
    }

    return 0;
}
