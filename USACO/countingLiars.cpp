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
    priority_queue<int> g;
    priority_queue<int, vector<int>, greater<int>> l;
    auto copyL = l;
    for (int i = 0; i < n; i++) {
        char c; cin >> c;
        int x; cin >> x;
        if (c == 'G') g.push(x);
        else l.push(x);
    }

    int ans = INF;
    for (int i = 0; i < g.size(); i++) {
        for (int j = 0; j < l.size(); j++) {
            if (l.top() <= g.top()) ans = min(ans, i + j);

            l.pop();
        }
        g.pop(); l = copyL;
    }

    cout << ans << endl;
    
    return 0;
}

