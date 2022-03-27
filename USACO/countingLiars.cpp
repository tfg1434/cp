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
    
    int n; cin >> n;
    vector<int> l, g;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        int x; cin >> x;
        if (c == 'G') g.push_back(x);
        else l.push_back(x);
    }
    // l.push_back(INF); g.push_back(-1);
    sort(all(l)); sort(rall(g));

    int ans = INF;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < l.size(); j++) {
            int gx = g[i], lx = l[j];
            if (lx >= gx) {
                ans = min(ans, i + j);
            }
        }
    }
    
    if (l.size() == 1 || g.size() == 1) ans = min(ans, 1);

    cout << ans << endl;
    
    return 0;
}

