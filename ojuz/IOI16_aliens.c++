#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 2e18;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

template<class T> T sqr(const T& a) { return a*a; }
int cdiv(int a, int b) {return a/b + ((a^b)>0&&a%b);}
bool cmp(const pair<int, int>& a, const pair<int, int>& b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second > b.second;
}

int n, m, k;
vi x, y;

void solve() {
    cin >> n >> m >> k;
    x.resize(n); y.resize(n);
    for (int i = 0; i < n; i++) cin >> x[i] >> y[i];
    vector<pair<int, int>> points;
    for (int i = 0; i < n; i++) {
        if (x[i] > y[i]) {
            swap(x[i], y[i]);
        }
        points.push_back({x[i], y[i]});
    }
    points.push_back({-1, -1});
    n++;
    sort(points.begin(), points.end(), cmp);
    vector<pair<int, int>> new_points;
    int max_y = -2;
    for (int i = 0; i < n; i++) {
        if (points[i].second <= max_y) {
            continue;
        }
        max_y = points[i].second;
        new_points.push_back(points[i]);
    }
    n = new_points.size();
    k = min(n - 1, k);
    vector<long long> l(n), r(n);
    for (int i = 0; i < n; i++) {
        l[i] = new_points[i].first;
        r[i] = new_points[i].second + 1;
    }
    vector<long long> dp(n, inf);
    dp[0] = 0;
    for (int p = 0; p < k; p++) {
        vector<long long> a(n - 1), b(n - 1);
        for (int i = 0; i < n - 1; i++) {
            a[i] = dp[i] + sqr(l[i + 1]) - sqr(max(0ll, r[i] - l[i + 1]));
            b[i] = 2 * l[i + 1];
        }
        vector<pair<long long, int>> ch(1, {0ll, p});
        vector<long long> new_dp(n, inf);
        int cur_entry = 0;
        for (int i = p + 1; i < n; i++) {
            while (cur_entry + 1 < ch.size() && ch[cur_entry + 1].first <= r[i]) {
                cur_entry++;
            }
            ps(ch);
            int j = ch[cur_entry].second;
            ps(j);
            new_dp[i] = sqr(r[i]) + a[j] - b[j] * r[i];
            if (i == n - 1 || p == 0) {
                continue;
            }
            while (!ch.empty()) {
                int j = ch.back().second;
                long long x = ch.back().first;
                if (a[i] - b[i] * x <= a[j] - b[j] * x) {
                    ch.pop_back();
                } else {
                    break;
                }
            }
            if (ch.empty()) {
                ch.push_back({0ll, i});
            } else {
                int j = ch.back().second;
                long long x = cdiv(a[i] - a[j], b[i] - b[j]);
                ch.push_back({x, i});
            }
            if (cur_entry >= ch.size()) {
                cur_entry = ch.size() - 1;
            }
        }
        dp = new_dp;
    }
    cout << dp.back() << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
