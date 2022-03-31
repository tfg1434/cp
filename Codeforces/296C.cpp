#include <bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
#define ll long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define IN(A, B, C) assert(B <= A && A <= C)

struct Op {
    ll l, r, d;
};
struct Query {
    ll x, y;
};

constexpr int MOD = 1e9 + 7;
constexpr int INF = 1e9;
constexpr ll INFF = 1e18;
constexpr int MAX_N = 1e5+5;
ll a[MAX_N], b[MAX_N], q[MAX_N], op[MAX_N][4];
ll n, m, k;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= m; i++) for (int j = 1; j <= 3; j++) cin >> op[i][j];
    for (int i = 1; i <= k; i++) {
        int x, y; cin >> x >> y;
        q[x]++;
        q[y+1]--;
    }

    for (int i = 1; i <= m; i++) q[i] += q[i-1];
    for (int i = 1; i <= m; i++) op[i][3] *= q[i];
    for (int i = 1; i <= m; i++) {
        b[op[i][1]] += op[i][3];
        b[op[i][2]+1] -= op[i][3];
    }
    for (int i = 1; i <= n; i++) b[i] += b[i-1];
    for (int i = 1; i <= n; i++) cout << a[i] + b[i] << ' ';
    cout << '\n';
    
    return 0;
}

