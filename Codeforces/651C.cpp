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

int factorial(int n) {
    int factorial = 1;
    for (int i = 2; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}
 
int nCr(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n; cin >> n;
    map<int, int> cx, cy;
    set<pii> st;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        cx[x]++; cy[y]++;
        st.insert({x, y});
    }

    int ans = 0;
    set<int> usedX;
    for (auto [k, v] : cx) {
        if (v == 1) continue;
        ans += nCr(v, 2);
        usedX.insert(k);
    }
    for (auto [k, v] : cy) {
        if (v == 1) continue;
        ans += nCr(v, 2);
        if (usedX.count(k)) ans--;
    }

    cout << ans << endl;
    
    return 0;
}

