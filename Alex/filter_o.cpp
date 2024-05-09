#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;
const int max_n = 1e5;
int dp[max_n+1];
vector<int> a, pre, nxt;
int n;
void precalc() {
    pre.resize(n+1);
    for (int i = 0; i < n; i++) pre[i+1] = pre[i]^a[i];
    nxt.assign(n, INF);
    unordered_map<int, vector<int>> s;
    for (int i = 0; i <= n; i++) {
        for (auto j : s[pre[i]]) nxt[j] = i-j;
        s[pre[i]].clear();
        s[pre[i]].push_back(i);
    }
}

void solve() {
    cin >> n;
    a.resize(n); for (auto& x : a) cin >> x; 
    precalc();

    fill(begin(dp), end(dp), INF);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        dp[i+1] = min(dp[i+1], dp[i]+1);
        if (nxt[i] != INF) dp[i+nxt[i]] = min(dp[i+nxt[i]], dp[i]+nxt[i]-1);
    }

    cout << dp[n] << '\n';
}

signed main() {
    cin.tie(0); ios::sync_with_stdio(0);
    int ttt; cin >> ttt; while (ttt--) solve();
}

