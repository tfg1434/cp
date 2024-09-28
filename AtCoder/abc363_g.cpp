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

// S0[i] = pre[i]
// supports operations:
//
//
//
// S1[i] = max unused job at i
// supports operations:
//
// S2[i] = min used job at i

void solve() {
    int score = 0;

    auto _add(int pos, int val) {
        S0.range_add(pos+1, n+1, 1);

        used[pos].insert(val);
        S2.point_set(pos, val);

        cur_val[pos] = val;

        score += val;
    };

    auto _del(int pos, int val) {
        used[]
    };

    // add a new job
    auto add = [&](int pos, int val) {
        _add(pos, val);

        int first_neg = S0.find_first_neg;
        if (first_neg != -1) {
            int ind = S2.range_min_ind(0, first_neg);
            score -= *begin(used[pos]); used[pos].erase(begin(used[pos]));
            S0.range_add(ind+1, n+1, 1);
        }
    };

    // delete existing job. either used or unused.
    auto del = [&](int pos, int val) {
        unused[pos].erase(unused[pos].find(val));
        S1.point_set(pos, unused[pos].size() ? *rbegin(unused[pos]) : 0);

        if (cur_val[pos] == val) {
            // may be wrong
            S0.range_add(pos+1, n+1, -1);
            int last_zero = S0.find_last_zero;
            int ind = S1.range_max_ind(last_zero, n);
            if (ind != -1) {
                score += *rbegin(unused[ind]);
                unused[ind].erase(prev(end(unused[ind])));
            }
        }
    };

    
    vi d(n), p(n);
    for (auto& i : d) cin >> i;
    for (auto& i : p) cin >> i;
    for (int i = 0; i < n; i++) {
        add(d[i], p[i]);
    }

    while (q--) {
        int c, x, y; cin >> c >> x >> y; c--;
        del(d[c], p[c]);
        d[c] = x; p[c] = y;
        add(d[c], p[c]);
        cout << score << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
