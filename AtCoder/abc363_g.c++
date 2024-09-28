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

// PRE[i] = pre[i]
// supports operations:
//
//
//
// MAX_UNUSED[i] = max unused job at i
// supports operations:
//
// MIN_USED[i] = min used job at i

struct Pre {

};


struct MAX_UNUSED {
};

template<class T>
struct MinSegTree {
    V<T> t;
    T get_inf();
    T range_min(int L, int R, int v=0, int l=0, int r=n) {
        if (r <= L || R <= l) return get_inf();
        if (L <= l && r <= R) return t[v];
        int m = (l+r)/2;
        return min(range_min(L, R, 2*v+1, l, m), range_min(L, R, 2*v+2, m, r));
    }
    void point_set(int i, T x, int v=0, int l=0, int r=n) {
        if (l == r-1) {
            t[i] = x;
            return;
        }
        int m = (l+r)/2;
        if (i < m)class T point_set(i, x, 2*v+1, l, m);
        else point_set(i, x, 2*v+2, m, r);
    }
    MinSegTree() : t(nn, get_inf()) {

    };
};
template<>
array<int, 2> MinSegTree<array<int, 2>>::get_inf() {
    return {inf, inf};
}

void solve() {
    int score = 0;

    auto del_used = [&](int pos) {
        PRE.range_add(pos+1, n+1, 1);
        MIN_USED.stop_using(pos);
        MAX_UNUSED.add(pos, cur_val[pos]);
        score += cur_val[pos];
        cur_val[pos] = -1;
    };

    auto add = [&](int pos, int val) {
        if (cur_val[pos] != -1) {
            del_used(pos)
        }

        cur_val[pos] = val;
        PRE.range_add(pos+1, n+1, -1);
        MIN_USED.start_using(pos, val);
        score += val;

        int first_neg = PRE.find_first_neg();
        if (first_neg != -1) {
            int pos = MIN_USED.pos_of_min(0, first_neg);
            del_used(pos);
        }
    };

    auto del_unused = [&](int pos, int val) {
        MAX_UNUSED.del(pos, val);
    };

    vi pos(n), val(n);
    for (auto& i : pos) cin >> i;
    for (auto& i : val) cin >> i;
    for (int i = 0; i < n; i++) add(pos[i], val[i]);

    while (q--) {
        int i; cin >> i; i--;
        if (cur_val[pos[i]] != -1) {
            del_used(pos[i]);
        } else {
            del_unused(pos[i], val[i]);
        }
        cin >> pos[i] >> val[i];
        add(pos[i], val[i]);
        cout << score << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
