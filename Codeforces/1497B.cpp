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
        int n, m; cin >> n >> m;
        map<int, int> mp;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            mp[x%m]++;
        }

        int ans = 0;
        // if (mp[0] != 0) ans++;
        // for (int i = 1; i <= m/2; i++) {
            // int j = m - i;
            // int mx = max(mp[i], mp[j]);
            // ans++;
            // mp[i] -= mx; mp[j] -= mx;
        // }
        for (auto [k, v]: mp) {
            if (k == 0) ans++;
            else if (k+k == m) ans++;
            else if (2*k < m || mp.find(m-k) == mp.end()) {
                int i = v, j = mp[m-k];
                //1+ b/c the diff between # of each is 1
                ans += 1 + max(0, abs(i-j)-1);
            }
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

