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


void build(int l, int r, const vector<int>& a, vector<int>& d, int depth=0) {
    if (r < l) return;
    if (l == r) {
        d[l] = depth;
        return;
    }

    int m = l;
    for (int i = l + 1; i <= r; ++i) {
        if (a[i] > a[m]) m = i;
    }
    d[m] = depth;

    build(l, m - 1, a, d, depth + 1);
    build(m + 1, r, a, d, depth + 1);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int T; cin >> T; while (T--) {
        int n; cin >> n;
        vector<int> a(n);
        for (auto& x : a) cin >> x;

        vector<int> d(n);
        build(0, n - 1, a, d, 0);

        for (auto x : d) cout << x << " ";
        cout << endl;
    }    
    
    return 0;
}

