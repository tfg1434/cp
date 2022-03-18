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
        int n, W; cin >> n >> W;
        vector<int> a(n);
        for (auto& x : a) cin >> x;
        sort(all(a));
        priority_queue<int> q;
        q.push(W);

        for (int i = n-1; i >= 0; i--) {
            if (q.top() < a[i]) q.push(W-a[i]);
            else {
                q.push(q.top()-a[i]);
                q.pop();
            }
        }

        cout << q.size() << '\n';
    }    
    
    return 0;
}

