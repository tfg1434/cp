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
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

struct fountain {
    int x, y, i;
    bool operator<(const fountain& o) const {
        if (x == o.x) return y>o.y;
        return x < o.x;
    }
};
int n, m, k;
V<fountain> a;

void solve() {
    cin >> n >> m >> k;
    a.resize(k);
    for (int i = 0; i < k; i++) {
        cin >> a[i].y >> a[i].x;
        a[i].i = i;
    }

    sort(all(a));
    vi ladder;
    for (int i = 0; i < k; i++) {
        if (!ladder.size() || a[ladder.back()].y < a[i].y) {
            ladder.pb(i);
        }
    }

    int tot = 0;
    int fi = 0;
    vi ans(ladder.size());
    // for (int i = 0; i < ladder.size(); i++) ps(a[ladder[i]].i);
    for (int i = 0; i < ladder.size(); i++) {
        int l = a[ladder[i]].x, r = i+1==ladder.size() ? m+1 : a[ladder[i+1]].x;
        vi sub_ladder;
        for (; fi < a.size() && a[fi].x < r; fi++) {
            if (fi == ladder[i]) continue;
            if ((!sub_ladder.size() || a[sub_ladder.back()].y < a[fi].y) && a[fi].y > (!i ? 0 : a[ladder[i-1]].y))
                sub_ladder.pb(fi);
        }
        int bot = !i ? (r-1)*n : (r-l)*n;
        // ps(i, bot);
        // ps(i, a[ladder[i+1]].x, r, n, bot);
        int old_top = (r-l)*a[ladder[i]].y;
        tot += bot-old_top;
        int new_top = 0;
        if (i > 0) {
            new_top += !sub_ladder.size() ? (r-l)*a[ladder[i-1]].y : (a[sub_ladder[0]].x-l)*a[ladder[i-1]].y;
            // ps("expect 4", a[sub_ladder[0]].i, a[sub_ladder[0]].x-l, a[ladder[i-1]].y);
        }
        for (int j = 0; j < sub_ladder.size(); j++) {
            // ps("a", a[sub_ladder[j]].i+1);
            int w; 
            if (j+1 < sub_ladder.size())
                w = a[sub_ladder[j+1]].x-a[sub_ladder[j]].x;
            else
                w = r-a[sub_ladder[j]].x;
            new_top += w*a[sub_ladder[j]].y;
        }
        // ps(i, new_top);
        // assert(old_area > 0);
        assert(old_top >= new_top);
        // ps(bot, old_top, new_top);
        ans[i] = (bot-new_top) - (bot-old_top);
    }

    vi where(k, -1);
    for (int i = 0; i < ladder.size(); i++) where[a[ladder[i]].i] = i;

    cout << tot << '\n';
    for (int i = 0; i < k; i++) {
        if (where[i] == -1) cout << "0 ";
        else cout << ans[where[i]] << ' ';
    }
    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
