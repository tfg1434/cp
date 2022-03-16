#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

constexpr ll MOD = 998244353;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        int mx = *max_element(all(a));
        int cnt = count(all(a), mx);
        int k = count(all(a), mx - 1);
        int ans = 1, sub = 1;
        for (ll i = 1; i <= n; i++) {
            ans = ans * i % MOD;
            if (i != k+1) sub = sub * i % MOD;
        }
        if (cnt == 1) ans = (ans - sub + MOD) % MOD;

        cout << ans << '\n';
    }    
    
    return 0;
}

