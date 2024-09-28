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

void solve() {
    int n, q; cin >> n >> q;
    vi inp(n);
    vi side(n);
    for (int i = 0; i < n; i++) {
        cin >> inp[i]; inp[i]--;
        side[inp[i]] = i >= n/2;
    }
    
    V<array<int, 2>> swaps;

    auto do_swaps = [&]() {
        for (auto[i ,j] : swaps) {
            if (side[i] != side[j]) swap(side[i], side[j]);
        }
        swaps.clear();
    };

    bool is_sort = false;
    while (q--) {
        char c; cin >> c;
        if (c == 'R') {
            do_swaps();
            is_sort = true;
        } else {
            int i, j; cin >> i >> j; i--; j--;
            swaps.pb({i, j});
        }
    }

    vi a;
    if (!is_sort) {
        a = inp; 
    } else {
        for (int i = 0; i < n; i++) if (!side[i]) a.pb(i);
        for (int i = 0; i < n; i++) if (side[i]) a.pb(i);
        sort(a.begin(), a.begin()+(n/2), greater<int>());
        sort(a.begin()+(n/2), a.end());
    }

    vi pos(n);
    for (int i = 0; i < n; i++) pos[a[i]] = i;
    for (auto[i, j] : swaps) {
        swap(a[pos[i]], a[pos[j]]);
        swap(pos[i], pos[j]);
    }
    for (int i = 0; i < n; i++) cout << a[i]+1 << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
