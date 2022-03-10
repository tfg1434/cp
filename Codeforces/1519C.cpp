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
        vector<int> u(n), s(n);
        for (int i = 0; i < n; i++) {
            cin >> u[i];
            u[i]--;
        }
        for (auto& x : s) cin >> x;

        vector<vector<int>> v(n); 
        for (int i = 0; i < n; i++) v[u[i]].push_back(s[i]);
        for (int i = 0; i < n; i++) sort(rall(v[i]));
        vector<vector<ll>> prefix(n, vector<ll>(1, 0));
        for (int i = 0; i < n; i++) 
            for (auto x : v[i])
                prefix[i].push_back(prefix[i].back() + x);

        vector<ll> ans(n);
        for (int i = 0; i < n; i++) {
            for (int k = 1; k <= v[i].size(); k++)
                ans[k-1] += prefix[i][v[i].size() / k * k];
        }

        for (auto x : ans) cout << x << " ";
        cout << endl;
    }    
    
    return 0;
}

