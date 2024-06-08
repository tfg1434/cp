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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

struct dif {
    int tot;
    set<array<int, 2>> s;
    dif() {
        tot = 0;
    }
    void ins(const array<int, 2>& x) { // i, a[i]
        auto nxt = s.lb(x);
        if (nxt != s.end()) tot += abs((*nxt)[1] - x[1]);
        if (nxt != s.begin()) tot += abs(x[1] - (*prev(nxt))[1]);
        if (nxt != s.end() && nxt != s.begin()) {
            tot -= abs((*nxt)[1] - (*prev(nxt))[1]);
        }
        s.insert(x);
    }
    void del(const array<int, 2>& x) {
        auto found = s.find(x);
        if (next(found) != s.end()) tot -= abs((*next(found))[1] - x[1]);
        if (found != s.begin()) tot -= abs(x[1] - (*prev(found))[1]);
        if (found != s.begin() && next(found) != s.end()) 
            tot += abs((*next(found))[1] - (*prev(found))[1]);
        s.erase(found);;
    }
};

void solve() {
    // dif test;
    // test.ins({0, 3});
    // test.ins({1, 4});
    // ps(test.tot);
    // test.del({0, 3});
    // ps(test.tot);
    // return;

    int n; cin >> n;
    V<array<int, 2>> a(n);    
    for (int i = 0; i < n; i++) cin >> a[i][1], a[i][0] = i;
    sort(all(a), [&](const array<int, 2>& x, const array<int, 2>& y) {
        return x[1] < y[1];
    });
    dif L, R;
    for (int i = 0; i < n; i++) R.ins(a[i]);

    int ans = R.tot;
    for (int i = 0; i < n; i++) {
        R.del(a[i]);
        L.ins(a[i]);
        // ps(L.s);
        // ps(R.s);
        ps(L.tot, R.tot);
        ckmin(ans, L.tot + R.tot);
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
