// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18; // 1e9
const int P = 1e9+7; // 998244353;
const double PI = acos(-1.0);

using pi = pair<int,int>;

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;
using vpi = V<pi>;

#define sz(x) ((int)(x).size())
#define bg(x) begin(x)
#define all(x) bg(x), end(x)
#define rall(x) x.rbegin(), x.rend() 
#define pb push_back
#define eb emplace_back
#define ft front()
#define bk back()

const int max_money = 1e5;

void solve() {
    int n; cin >> n; 
    V<array<int, 3>> events; // x, type, ind
    vi c(n), l(n), r(n);
    for (int i = 0; i < n; i++) { 
        cin >> c[i] >> l[i] >> r[i]; 
        events.pb({r[i], 1, i});
    }
    int m; cin >> m;
    vi L(m), money(m);
    for (int i = 0; i < m; i++) { 
        cin >> L[i] >> money[i];
        int len; cin >> len;
        events.pb({L[i]+len+1, 0, i});
    }

    vi dp(max_money+1, INF);
    dp[0] = -INF;
    vb ans(m);
    sort(all(events)); reverse(all(events));
    for (auto [x, type, ind] : events) {
        if (type == 0) {
            ans[ind] = dp[money[ind]] <= L[ind];
        } else {
            for (int i = max_money-c[ind]; i >= 0; i--) {
                dp[i+c[ind]] = min(dp[i+c[ind]], max(l[ind], dp[i]));
            }
        }
    }

    for (int i = 0; i < m; i++) cout << (ans[i] ? "YES" : "NO") << '\n';
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}
