#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int h;

V<array<int, 2>> t;
void init_tree() {
    int siz = 1;
    while (siz < 2*h) siz *= 2;
    t.resize(siz, {0, -1});
}
array<int, 2> range_max(int L, int R, int u=0, int l=0, int r=h) {
    if (r <= L || R <= l) return {0, -1};
    if (L <= l && r <= R) return t[u];
    int m = (l+r)/2;
    return max(range_max(L, R, 2*u+1, l, m), range_max(L, R, 2*u+2, m, r));
}
void point_ckmax(int pos, array<int, 2> val, int u=0, int l=0, int r=h) {
    if (l == r-1) {
        ckmax(t[u], val);
        return;
    }
    int m = (l+r)/2;
    if (pos < m) point_ckmax(pos, val, 2*u+1, l, m);
    else point_ckmax(pos, val, 2*u+2, m, r);
    t[u] = max(t[2*u+1], t[2*u+2]);
}

void solve() {
    int w, n; cin >> h >> w >> n;
    init_tree();
    V<array<int, 2>> coins(n);
    for (auto& [r, c] : coins) {
        cin >> r >> c; r--; c--;
    }
    sort(all(coins), [&](array<int, 2> a, array<int, 2> b) {
        if (a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    });
    V<array<int, 2>> dp(n);
    for (int i = 0; i < n; i++) {
        auto [r, c] = coins[i];
        dp[i] = range_max(0, r+1); // (score, ind)
        dp[i][0]++;
        point_ckmax(r, { dp[i][0], i });
    }

    auto mx = max_element(all(dp));
    int cur_ind = mx-dp.begin();
    auto [score, prv_ind] = *mx;
    cout << score << '\n';
    V<string> rev_path;
    {
        string tmp;
        auto [x, y] = coins[cur_ind];
        int X = h-1, Y = w-1;
        for (int i = 0; i < X-x; i++) tmp += "D";
        for (int i = 0; i < Y-y; i++) tmp += "R";
        rev_path.pb(tmp);
    }
    while (prv_ind != -1) {
        auto [X, Y] = coins[cur_ind];
        auto [x, y] = coins[prv_ind];
        string tmp;
        for (int i = 0; i < X-x; i++) tmp += "D";
        for (int i = 0; i < Y-y; i++) tmp += "R";
        rev_path.pb(tmp);

        cur_ind = prv_ind;
        prv_ind = dp[cur_ind][1];
    }
    {
        string tmp;
        int x = 0, y = 0;
        auto [X, Y] = coins[cur_ind];
        for (int i = 0; i < X-x; i++) tmp += "D";
        for (int i = 0; i < Y-y; i++) tmp += "R";
        rev_path.pb(tmp);
    }

    reverse(all(rev_path));
    for (string s : rev_path) {
        cout << s;
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
