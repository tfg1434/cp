#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18;

class Window {
public:
    int l, r;
    deque<pair<int, int>> deq;

    Window() {
        l = 0;
        r = 0;
    }

    void pop() {
        if (deq.front().second == l)
            deq.pop_front();
        l++;
    }

    void append(int x) {
        while (!deq.empty() && deq.back().first >= x)
            deq.pop_back();
        deq.push_back({x, r});
        r++;
    }

    int get_min() {
        return deq.empty() ? INF : deq.front().first;
    }
};

void solve() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    vector<int> pre(n + 1);
    partial_sum(a.begin(), a.end(), pre.begin());

    auto check = [&](int k) {
        vector<int> dp(n + 1, INF);
        dp[0] = 0;

        int j = 0;
        Window w;
        w.append(0);
        for (int i = 1; i <= n; ++i) {
            while (pre[i - 1] - pre[j] > k) {
                w.pop();
                j++;
            }

            dp[i] = a[i] + w.get_min();
            w.append(dp[i]);
        }

        int res = INF;
        int x = 0;
        for (int i = n; i >= 1; --i) {
            res = min(res, dp[i]);
            x += a[i];
            if (x > k)
                break;
        }

        return res <= k;
    };

    int lo = 1, hi = 1e14;
    while (lo < hi) {
        int m = lo + (hi - lo) / 2;
        if (check(m))
            hi = m;
        else
            lo = m + 1;
    }
    cout << lo << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

