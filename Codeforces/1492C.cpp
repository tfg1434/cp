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
    
    int n, m; cin >> n >> m;
    string s, t; cin >> s >> t;
    vector<int> a(n), b(n);

    for (int i = 0, j = 0; j < m; i++) {
        if (s[i] == t[j]) a[j++] = i;
    }
    for (int i = n-1, j = m-1; j >= 0; i--) {
        if (s[i] == t[j]) b[j--] = i;
    }
    int ans = 0;
    for (int i = 0; i < m-1; i++) ans = max(ans, b[i+1]-a[i]);

    cout << ans << endl;

    // vector<pii> a(m);
    // for (int i = 0; i < m; i++) {
        // a[i].first = s.find_first_of(t[i]);
        // a[i].second = s.find_last_of(t[i]);
    // }
    // int ans = 0;
    // for (int i = 1; i < m; i++) {
        // ans = max(ans, abs(a[i].second - a[i-1].first));
        // ans = max(ans, abs(a[i].first - a[i-1].second));
    // }
    // cout << ans << endl;
    
    return 0;
}

