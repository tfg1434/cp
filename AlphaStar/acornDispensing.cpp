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
map<pii, vector<pii>> mp;


int dfs(int x, int y, int cnt) {
    cout << x << " " << y << " " << cnt << endl;
    if (!mp.count({x, y})) return cnt + 1;

    for (auto [a, b] : mp[{x, y}]) {
        dfs(a, b, cnt);
    }

    return cnt + 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m; cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int x, y, a, b; cin >> x >> y >> a >> b;
        x--, y--, a--, b--;
        mp[{x, y}].push_back({a, b});
    }

    cout << dfs(0, 0, 0) << '\n';

    return 0;
}

