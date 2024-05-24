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
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int n, m;
vi a;

int sq(int x) { return x*x; }
int f(int x, int k) { return (x%(k+1))*sq((x+k)/(k+1)) + (k+1-x%(k+1))*sq(x/(k+1)); }

array<int, 2> calc(int t) { // t \in [0, inf)
    int cost = 0, cnt = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == 1) {
            cost += 1;
            continue;
        }
        auto kth_delta = [&](int k) { return f(a[i],k-1)-f(a[i], k); };
        int lo = 1, hi = a[i]-1; // lo <= hi
        if (kth_delta(lo) < t) {
            cost += f(a[i], lo-1); continue;
        }
        if (kth_delta(hi) >= t) {
            cost += f(a[i], hi); cnt += hi; continue;
        }
        while (hi-lo > 1) {
            int k = (lo+hi)/2;
            kth_delta(k) >= t ? lo = k : hi = k;
        }
        cost += f(a[i], lo);
        cnt += lo;
    }
    return {cost, cnt};
}

void solve() {
    cin >> n;    
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = n-1; i > 0; i--) a[i] -= a[i-1];
    cin >> m;

    int lo = 1, hi = 1e18;
    if (calc(hi)[0] <= m) {
        cout << "0\n";
        return;
    }
    while (hi-lo > 1) {
        int t = (lo+hi)/2;
        auto [cost, min_pts] = calc(t);
        cost > m ? hi = t : lo = t;
    }
    {
        auto [cost, min_pts] = calc(lo);
        assert(cost <= m);
    }
    {
        auto [cost, min_pts] = calc(hi);
        assert(cost > m);
    }

    auto [cost, min_pts] = calc(hi);
    assert(cost > m);
    int ans = min_pts + (cost-m + lo-1)/lo;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
