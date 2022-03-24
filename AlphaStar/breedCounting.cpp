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
    
    int n, q; cin >> n >> q;
    vector<int> pre1(n+1), pre2(n+1), pre3(n+1);
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (i == 1) {
            pre1[i] = x == 1;
            pre2[i] = x == 2;
            pre3[i] = x == 3;
        } else {
            pre1[i] = pre1[i - 1] + (x == 1);
            pre2[i] = pre2[i - 1] + (x == 2);
            pre3[i] = pre3[i - 1] + (x == 3);
        }
    }
    // cout << "pre1" << endl;
    // for (auto x : pre1) cout << x << " "; cout << endl;
    // cout << "pre2" << endl;
    // for (auto x : pre2) cout << x << " "; cout << endl;
    // cout << "pre3" << endl;
    // for (auto x : pre3) cout << x << " "; cout << endl;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r;
        // l--; r--;
        cout << pre1[r] - pre1[l-1] << " " << pre2[r] - pre2[l-1] << " " << pre3[r] - pre3[l-1] << endl;
    }
    
    return 0;
}

