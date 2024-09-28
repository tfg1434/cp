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
using vb = V<bool>;
using vs = V<string>;

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

using pt = array<int, 2>;

void solve() {
    int n; cin >> n; 
    V<pt> a(n);
    for (pt& i : a) cin >> i[0] >> i[1];
    sort(all(a));
    V<array<int, 2>> black, red;
    for (int i = 0; i < n; i++) {
        if (!black.size() || a[i][1] < black.bk[1]) {
            black.pb(a[i]);
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (!red.size() || a[i][1] > red.bk[1]) {
            red.pb(a[i]);
        }
    }
    reverse(all(red));

    V<array<int, 3>> events;
    for (int i = 0; i+1 < len(black); i++) {
        auto [x0, y0] = black[i];
        auto [x1, y1] = black[i+1];
        events.pb({x1, 0, i});
    }
    for (int i = 0; i+1 < len(red); i++) {
        auto [x0, y0] = red[i];
        auto [x1, y1] = red[i+1];
        events.pb({x0+1, 1, y1});
    }
    events.pb({red.bk[0]+1, -1});
    sort(all(events));

    int ans = 0;
    int top = -1, bot = -1;
    int A = 0, B = 0, C = 0;
    int cur_event = 0;
    deque<array<int, 2>> qb;
    for (int i = 0; i < n; i++) {
        while (cur_event < len(events)) {
            auto [x, typ, info] = events[cur_event];
            if (x > i) break;
            if (typ == 0) {
                bot = info;
                qb.push_back({ x, info });
            }
            if (typ == 1) {
                top = info;
                while (len(qb) && qb.ft[1] >= top) {
                    auto [x0, y0] = qb.ft; qb.pop_front();
                    int cnt;
                    if (len(qb)) cnt = qb.ft[1]-x0;
                    else cnt = i-x0;
                    A -= cnt;
                    B -= y0*cnt;
                    C -= (y0*y0-y0)*cnt;
                }
            }
            cur_event++;
        }
        if (len(qb)) {
            ans += A*top*top + B*top + C;
        }
        A += 1;
        B += -2*bot+1;
        C += bot*bot-bot;
    }
        
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
