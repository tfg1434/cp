#include <bits/stdc++.h>
using namespace std;
#define int int64_t

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define len(x) (int)((x).size())
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

int n;

vi operator+(vi l, vi r) {
    auto res = l;
    if (len(r) > len(l)) res.rsz(len(r));
    for (int i = 0; i < len(r); i++) res[i] += r[i];
    res.insert(begin(res), 0);
    int sum = accumulate(all(res), 0);
    while (true) {
        if (sum-res.bk < n) break;
        sum -= res.bk;
        res.pop_back();
    }
    return res;
}

struct DP {
    int init;
    vi dp;
    void advance(int x) {
        for (int i = 0; i < len(dp); i++) {
            int cnt = min(x, dp[i]);
            init += cnt*i;
            x -= cnt;
            dp[i] -= cnt; 
        }
        assert(x == 0);
    }
};

DP empty_dp() {
    vi res = {1, 0};
    int s = 0;
    for (int i = 2; s < n; i++) {
        res.pb(p2(i-2));
        s += res.bk;
    }
    return {0, res};
}

DP operator+(DP l, DP r) {
    return {l.init+r.init, l.dp+r.dp};
}

struct Node {
    array<int, 2> c;
    int cnt;
    DP dp;
};
V<Node> tr(2);
int cur_node = 1;

void fill(int u) {
    if (!tr[u].c[0] && !tr[u].c[1]) {
        tr[u].dp = empty_dp();
    } else {
        tr[u].dp = tr[tr[u].c[0]].dp+tr[tr[u].c[1]].dp;
    }
    tr[u].dp.advance(tr[u].cnt);
}

void solve() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s; cin >> s;
        int cur = 1;
        for (char c : s) {
            if (!tr[cur].c[c-'0']) {
                tr[cur].c[c-'0'] = ++cur_node;
                tr.emplace_back();
            }
            cur = tr[cur].c[c-'0'];
        }
        tr[cur].cnt++;
    }

    tr[0].dp = empty_dp();
    for (int i = cur_node; i >= 1; i--) {
        fill(i);
    }
    cout << tr[1].dp.init << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
