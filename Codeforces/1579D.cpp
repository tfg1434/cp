#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

int T;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> T;
    while (T--) {
        int n; cin >> n;
        priority_queue<pair<int, int>> pq;
        int idx = 1;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            if (x != 0) pq.push({x, idx});
            idx++;
        }

        vector<pair<int, int>> ans;
        while (pq.size() >= 2) {
            auto [a, b] = pq.top();
            pq.pop();
            auto [c, d] = pq.top();
            pq.pop();

            if (a - 1 != 0) pq.push({ a - 1 , b});
            if (c - 1 != 0) pq.push({ c - 1 , d});

            ans.push_back({b, d});
        }

        cout << ans.size() << '\n';
        for (auto [a, b] : ans) cout << a << ' ' << b << '\n';
    }    
    
    return 0;
}

