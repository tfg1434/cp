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

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }

int n, q;
struct node {
    int x, y, z, w, i;
    bool operator<(const node& o) const {return x > o.x;};
    friend ostream& operator<<(ostream& out, const node& o) {
        out << o.x << ' ' << o.y << ' ' << o.z << ' ' << o.w;
        return out;
    }
};
V<node> v;
V<bool> dominated;

// this is not the usual ladder template! this does not handle partial domination!
struct ladder {
    set<pair<int, int>> ladder;
    bool is_dominated(pair<int, int> p) {
        if (!ladder.size()) return false;
        auto gx = ladder.lb({p.f, inf});
        return gx != ladder.end() && gx->s > p.s;
    };
    void add_point(pair<int, int> p) {
        int x = p.f, y = p.s;
        auto gx = ladder.lb({x, inf});
        auto yy = gx;
        while (yy != ladder.begin()) {
            if (prev(yy)->s <= y) yy = prev(yy);
            else break;
        }
        ladder.erase(yy, gx);
        if (!is_dominated({x, y}))
            ladder.insert({x, y});
    }
};

void cdq(int l, int r) {
    if (l == r-1) return;
    int m = (l+r)/2;
    cdq(l, m); cdq(m, r);

    V<node> tmp;
    ladder lad;
    auto add_to_ladder = [&](int i) {
        int z = v[i].z, w = v[i].w;
        lad.add_point({z, w});
        tmp.pb(v[i]);
    };
    auto check_dominated = [&](int i) {
        int z = v[i].z, w = v[i].w, ind = v[i].i;
        if (lad.is_dominated({z, w})) {
            dominated[ind] = true;
        }
        tmp.pb(v[i]);
    };
    int a = l, b = m;
    while (a < m && b < r) {
        if (v[a].y > v[b].y) add_to_ladder(a++);
        else check_dominated(b++);
    }
    while (a < m) tmp.pb(v[a++]);
    while (b < r) check_dominated(b++);
    for (int i = l; i < r; i++) v[i] = tmp[i-l];
}

void solve() {
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].x >> v[i].y >> v[i].z >> v[i].w;
        // dumb statement
        v[i].x = n-v[i].x; v[i].y = n-v[i].y;
        v[i].z = n-v[i].z; v[i].w = n-v[i].w;
        v[i].i = i;
    }

    dominated.resize(n);
    sort(all(v));
    cdq(0, n);

    int ans = 0;
    for (int i = 0; i < n; i++) ans += !dominated[i];
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
