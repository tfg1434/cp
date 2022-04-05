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
int a, b, k; 


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        cin >> a >> b >> k;
        vector<int> as(a), bs(b);
        vector<pii> graph(k);
        for (auto& [x, y] : graph) cin >> x;
        for (auto& [x, y] : graph) cin >> y;
        for (auto& [x, y] : graph) {
            x--, y--;
            as[x]++, bs[y]++;
        }

        ll ans = 0;
        for (auto [x, y] : graph) {
            ans += k - as[x] - bs[y] + 1;
        }

        cout << ans / 2 << '\n';
    }    
    
    return 0;
}

