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
    string s; cin >> s;
    s = "0" + s;
    int ans = 0;
    while (true) {
        vector<pii> pre(n+1, { 0, 0 }); //wrong, right
        for (int i = 1; i <= n; i++) {
            if (s[i] == 'H') {
                pre[i] = pre[i-1];
                continue;
            }

            pre[i].first = pre[i-1].first + (i % 2 == 1);
            pre[i].second = pre[i-1].second + (i % 2 == 0);
        }
        // for (auto x : pre) cout << x.first << " " << x.second << endl;
        auto mx = max_element(all(pre), [](const pii& a, const pii& b) {
            return a.first - a.second < b.first - b.second;
        });
        // cout << mx->first << " " << mx->second << ' ' << mx - pre.begin() << endl;
        if (mx->first - mx->second <= 0) break;
        int idx = (mx-pre.begin() + 1) / 2 * 2;
        reverse(s.begin(), s.begin() + idx);
        ans++;
    }
    cout << ans << endl;
    
    return 0;
}

