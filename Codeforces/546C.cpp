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

    queue<int> q1, q2;
    int n, k1, k2, i = 0;
    cin >> n;
    cin >> k1;
    while (k1--) {
        int x;
        cin >> x;
        q1.push(x);
    }
    cin >> k2;
    while (k2--) {
        int x;
        cin >> x;
        q2.push(x);
    }
    for (i = 1; i <= 10000000 && !q1.empty() && !q2.empty(); i++) {
        int x1 = q1.front();
        int x2 = q2.front();
        if (x1 > x2) {
            q1.push(x2);
            q2.pop();
            q1.push(x1);
            q1.pop();
        } else {
            q2.push(x1);
            q1.pop();
            q2.push(x2);
            q2.pop();
        }
    }
    int flag = -1;
    if (!q1.empty())
        flag = 1;
    else
        flag = 2;
    if (i < 10000000)
        printf("%d %d", i - 1, flag);
    else
        printf("-1");
    // int n; cin >> n;
    // queue<int> a, b;
    // int k1, k2; cin >> k1 >> k2;
    // for (int i = 0; i < k1; i++) {
    // int x; cin >> x;
    // a.push(x);
    // }
    // for (int i = 0; i < k2; i++) {
        // int x; cin >> x;
        // b.push(x);
    // }

    // ll mx = 2;
    // for (int i = 1; i <= n+1; i++) mx *= i;
    // int i;
    // for (i = 1; i <= mx && !a.empty() && !b.empty(); i++) {
        // int xa = a.front(); int xb = b.front(); 
        // if (xa > xb) {
            // a.push(xb); b.pop();
            // a.push(xa); a.pop();
        // } else {
            // b.push(xa); a.pop();
            // b.push(xb); b.pop();
        // }
    // }

    // int flag = -1;
    // if (!a.empty()) flag = 1;
    // else flag = 2;
    // if (i < mx) cout << i-1 << ' ' << flag << endl;
    // else cout << -1 << endl;
    
    return 0;
}

