#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int inf = 2e18;

const int mod = 1e9 + 7;

const int max_n = 201;

pair<int, int> dp[max_n][max_n + 1][2]; // max n1, from_which_i

void relax(pair<int, int>& a, pair<int, int> b) {
    a = max(a, b);
}

int32_t main() {
    // freopen("show.in", "r", stdin);
    // freopen("show.out", "w", stdout);
    for (int i = 0; i < max_n; i++) {
        for (int j = 0; j < max_n + 1; j++) {
            for (int k = 0; k < 2; k++) {
                dp[i][j][k] = {-inf, -2};
            }
        }
    }
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    vector<array<int, 3>> segs(n); // r, l, i
    for (int i = 0; i < n; i++) {
        int s, t;
        cin >> s >> t;
        segs[i] = {s + t, s, i};
    }
    segs.push_back({-1, -1, n});
    n++;
    sort(segs.begin(), segs.end());
    dp[0][0][0] = {0, -1};
    for (int i = 0; i < n - 1; i++) {
        for (int n0 = 0; n0 <= n; n0++) {
            for (int col = 0; col < 2; col++) {
                int cnt = 0;
                for (int j = i + 1; j < n; j++) {
                    if (segs[j][1] >= segs[i][0]) {
                        cnt++;
                    }
                    relax(dp[j][n0 + (col == 0 ? 0 : cnt)][1 - col],
                          {dp[i][n0][col].first + (col == 0 ? cnt : 0), i});
                }
            }
        }
    }
    array<int, 3> ans = {-inf, -1, -1}; // min(n0, n1), n0, col
    for (int n0 = 0; n0 <= n; n0++) {
        for (int col = 0; col < 2; col++) {
            ans = max(ans, array<int, 3>{min(n0, dp[n - 1][n0][col].first), n0, col});
        }
    }
    vector<int> coloring(n, -1);
    int i = n - 1;
    int n0 = ans[1];
    int col = ans[2];
    while (i > 0) {
        int prev_i = dp[i][n0][col].second;
        int cnt = 0;
        for (int j = prev_i + 1; j <= i; j++) {
            if (segs[j][1] >= segs[prev_i][0]) {
                cnt++;
                coloring[segs[j][2]] = col;
            }
        }
        i = prev_i;
        n0 -= (col == 0 ? cnt : 0);
        col = 1 - col;
    }
    for (int i = 0; i < n - 1; i++) {
        cout << coloring[i] + 1 << ' ';
    }
}

