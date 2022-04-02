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
    
    int n, k; cin >> n >> k;
    vector<pii> a, b;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        a.push_back({ x, i+1 });
    }

    int s=0, m=0, c=0;
    while (true) {
        sort(all(a));
        c = a[n-1].first - a[0].first;
        if (c == 0 || m == k) break;
        a[n-1].first--, a[0].first++;
        b.push_back({ a[n-1].second, a[0].second });
        m++;
    }

    cout << c << ' ' << m << '\n';
    for (auto [x, y] : b) cout << x << ' ' << y << '\n';
    
    return 0;
}

