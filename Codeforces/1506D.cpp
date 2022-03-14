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
        priority_queue<pii> q;
        int n; cin >> n;
        map<int, int> m;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            m[x]++;
        }
        for (auto& [k, v] : m) {
            q.push({v, k});
        }

        int l = n;
        while (q.size() >= 2) {
            auto [c1, x1] = q.top(); q.pop();
            auto [c2, x2] = q.top(); q.pop();
            c1--; c2--;
            l -= 2;
            if (c1 > 0) q.push({c1, x1});
            if (c2 > 0) q.push({c2, x2});
        }

        cout << l << '\n';
    }    
    
    return 0;
}

