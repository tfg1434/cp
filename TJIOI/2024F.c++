// oops you don't need 2d segtree. i made an oopsie, thought largest rectangle is the max w x max h... this is wrong
// at least i learned how to write 2d segtree.

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)

#define int int64_t
const int inf = 2e18;

int n, m, q;
vector<string> inp; 
vector<vector<int>> pre;

void calc_pre() {
    pre = vector<vector<int>>(n+1, vector<int>(m+1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            pre[i+1][j+1] = pre[i+1][j] + (inp[i][j] - '0');
        }
        for (int j = 0; j < m; j++) {
            pre[i+1][j+1] += pre[i][j+1];
        }
    }
}

int sum(int r0, int c0, int r1, int c1) {
    assert(r0 <= r1 && c0 <= c1);
    return pre[r1][c1] - pre[r0][c1] - pre[r1][c0] + pre[r0][c0];
}

vector<int> calc_tot(int h) {
    vector<int> tot(m+1);

    for (int i = 0; i <= n-h; i++) {
        vector<int> s;
        for (int j = 0; j < m; j++) {
            if (sum(i, j, i+h, j+1) > 0) {
                while (s.size()) {
                    int w = j - s.back(); s.pop_back();
                    tot[w]++;
                }
            } else {
                s.push_back(j);
            }
        }
        while (s.size()) {
            int w = m - s.back(); s.pop_back();
            tot[w]++;
        }
    }
    for (int i = m; i > 1; i--) tot[i-1] += tot[i];
    return tot;
}

void solve() {
    cin >> n >> m >> q;
    inp.resize(n); for (auto& s : inp) cin >> s;
    calc_pre();

    vector<int> ans(q);
    vector<vector<array<int, 2>>> queries(n+1);
    for (int i = 0; i < q; i++) {
        int h, w; cin >> h >> w;
        if (h <= n) {
            queries[h].push_back({w, i});
        } else {
            ans[i] = 0;
        }
    }
    for (int h = n; h >= 1; h--) {
        auto tot = calc_tot(h);
        for (auto [w, ind] : queries[h]) {
            ans[ind] = tot[w];
        }
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();    
}



