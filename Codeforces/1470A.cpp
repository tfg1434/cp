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
int n, m;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> n >> m;
        vector<int> k(n), c(m);
        for (auto& x : k) cin >> x;
        for (auto& x : c) cin >> x;
        sort(rall(k));
        int last = 0;

        ll ans = 0;
        for (int i = 0; i < n; i++) {
            ans += c[min(i+1, k[i])-1];
        }

        cout << ans << '\n';
    }    
    
    return 0;
}

