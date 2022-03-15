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
    
    int T; cin >> T; while (T--) {
        int n, k; cin >> n >> k;
        vector<ll> ans(n+1, INFF), idx(n+1, 0), a(k);

        for (int i = 0; i < k; i++) {
            cin >> a[i];
        }
        for (int i = 0; i < k; i++) {
            cin >> ans[a[i]]; //the temp
        }

        for (int i = 2; i <= n; i++)
            ans[i] = min(ans[i], ans[i-1]+1);
        for (int i = n-1; i > 0; i--)
            ans[i] = min(ans[i], ans[i+1]+1);

        for (int i = 1; i <= n; i++) cout << ans[i] << " ";
        cout << endl;
    }    
    
    return 0;
}

