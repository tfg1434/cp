#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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

void solve() {
    int n, m; cin >> n >> m;
    vi t(n);
    V<array<int, 2>> events;
    for (int i = 0; i < n; i++) {
        cin >> t[i];
        events.pb({t[i], 1});
        events.pb({t[i]+m, -1});
    }
    sort(all(t));
    for (int x : t) {
        events.pb({x, -1});
        events.pb({x, 1});
        events.pb({x+m, -1});
        events.pb({x+m, 1});
    }
    sort(all(events));

    vi cnt(2);
    int ans = -inf, tot_one = 0;
    int l = 0, r = 0, cur_left = 0, cur_right = 0;
    for (int x : t) {
        while (events[l][0] < x || (events[l][0] == x && events[l][1] == -1)) {
            if (l) {
                int len = events[l][0]-events[l-1][0];
                if (cur_left == 1) cnt[0] -= len;
                if (cur_left == 2) cnt[1] -= len;
            }
            cur_left += events[l][1];
            l++;
        }
        while (r < events.size() && (events[r][0] < x+m || (events[r][0] == x+m && events[r][1] == -1))) {
            if (r) {
                int len = events[r][0]-events[r-1][0];
                if (cur_right == 1) {
                    cnt[0] += len;
                    tot_one += len;
                }
                if (cur_right == 2) {
                    cnt[1] += len;
                }
            }
            cur_right += events[r][1];
            r++;
        }

        ckmax(ans, cnt[1]-cnt[0]);
    }

    cout << ans+m+tot_one << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
