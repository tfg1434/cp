#include <bits/stdc++.h>
using namespace std;
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
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        vector<int> pre(n); pre[0] = a[0];
        for (int i = 1; i < n; ++i) pre[i] = pre[i - 1] ^ a[i];

        bool ans = false;
        if (pre[n-1] == 0) ans = true;

        int curr = 0;
        for (int i = n-1; i >= 0; i--) {
            curr ^= a[i];

            for (int j = 0; j < i; j++) {
                if (j == 0) continue;

                int mid = pre[j-1] ^ pre[i-1];
                int l = pre[j-1];
                int r = curr; //curr counts from right
                if (l == mid && mid == r) {
                    ans = true;
                    break;
                }
            }
        }

        if (ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }    
    
    return 0;
}

