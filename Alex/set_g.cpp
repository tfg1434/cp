// Partial order, only answer a boolean
// We can maintain the ladder of points with std::set

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9+1;

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

int n;
map<array<int, 3>, vi> inds;
V<array<int, 3>> inp;
map<int, V<array<int, 2>>> m;
vi ans;

void solve() {
    cin >> n;
    inp.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; i++) cin >> inp[i][0];
    for (int i = 0; i < n; i++) cin >> inp[i][1];
    for (int i = 0; i < n; i++) cin >> inp[i][2];
    for (int i = 0; i < n; i++) {
        if (!inds[inp[i]].size())
            m[inp[i][0]].pb({inp[i][1], inp[i][2]});
        inds[inp[i]].pb(i);
    }
    set<pair<int, int>> ladder;
    auto is_dominated = [&](pair<int, int> p) {
        if (!ladder.size()) return false;
        auto gx = ladder.lb({p.f, inf});
        return gx != ladder.end() && gx->s > p.s;
    };
    auto is_partial_dominated = [&](pair<int, int> p) {
        if (!ladder.size()) return false;
        auto gx = ladder.lb({p.f, inf});
        if (gx != ladder.begin() && prev(gx)->f == p.f) gx = prev(gx);
        return gx != ladder.end() && gx->s >= p.s;
    };
    for (auto it = m.rbegin(); it != m.rend(); it++) {
        for (auto [x, y] : it->s) {
            array<int, 3> pt = {it->f, x, y};
            bool dom = is_dominated({x, y});
            for (auto ind : inds[pt]) {
                ans[ind] |= dom;
            }
        }

        for (auto [x, y] : it->s) {
            auto gx = ladder.lb({x, inf});
            auto yy = gx;
            while (yy != ladder.begin()) {
                if (prev(yy)->s <= y) yy = prev(yy);
                else break;
            }
            ladder.erase(yy, gx);
            if (!is_partial_dominated({x, y}))
                ladder.insert({x, y});
        }
    }

    {
        int sum = 0;
        for (int i = 0; i < n; i++) sum += ans[i];
        cout << sum << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
