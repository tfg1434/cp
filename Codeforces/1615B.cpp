#include <bits/stdc++.h>
using namespace std;

#define ll long long

constexpr int max_lr = 200'000;
constexpr int max_b = 20;
int T, L, R;
//prefix sum array
int b[max_b][max_lr];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 0; i < 20; ++i) {
        for (int j = 1; j <= max_lr; ++j) {
            // + is there a bit at the right after shifting i times
            b[i][j] = b[i][j - 1] + (( j >> i ) & 1);
        }
    } 
    
    cin >> T;
    while (T--) {
        cin >> L >> R;

        int ans = 0;
        for (int i = 0; i < max_b; ++i) {
            ans = max(ans, b[i][R] - b[i][L - 1]);
        }
        
        cout << R - L + 1 - ans << '\n';
    }

    return 0;
}
