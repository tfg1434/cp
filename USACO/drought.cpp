#include <bits/stdc++.h>
using namespace std;

int T;


#define ll long long

int cost(vector<int> h, int target) {
    int ans = 0;
    for (int i = 0; i < h.size() - 1; i++) {
        if (h[i] <= target) continue;

        int diff = min(h[i], h[i+1]) - target;
        h[i] -= diff; h[i+1] -= diff;
        ans += diff * 2;
    }

    for (int i = 0; i < h.size(); i++) {
        if (h[i] != target) return INT_MAX; 
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> h(n);
        for (auto& i : h) cin >> i;
        
        int ans = INT_MAX;

        for (int i = *min_element(h.begin(), h.end()); i >= 0; i--) {
            ans = min(ans, cost(h, i));
        }

        if (ans == INT_MAX) ans = -1;
        cout << ans << endl;
    }    
    
    return 0;
}

