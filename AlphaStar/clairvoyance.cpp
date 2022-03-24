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
    set<int> a;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.insert(x);
    }
    
    priority_queue<int> pq;
    for (int i = 2*n; i >= 1; i--) {
        if (a.count(i)) continue;
        pq.push(i);
    }
    int ans = 0;
    while (!a.empty() && !pq.empty()) {
        int x = *a.rbegin();
        int y = pq.top();
        if (y > x) {
            ans++;
            a.erase(x);
            pq.pop();
        } else {
            a.erase(x);
        }
    }
    cout << ans << endl;

    // set<int> b;
    // for (auto& x : b) b.insert(x);
    // set<int> h;
    // for (int i = 1; i <= 2*n; i++) 
        // if (!b.count(i)) h.insert(i);

    // int ans = 0;
    // for (auto x : b) {
        // for (int i = x+1; i <= 2*n; i++) {
            // if (h.count(i)) {
                // h.erase(i);
                // ans++;
                // break;
            // }
        // }
    // }

    // cout << ans << endl;
    
    return 0;
}

