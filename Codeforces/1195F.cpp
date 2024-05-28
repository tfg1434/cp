// Naive approach with Mo's Algorithm. 2e8 operations but bad constant factor, so TLE

#include <bits/stdc++.h>
using namespace std;

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

using pt = complex<int>;
#define x real()
#define y imag()
template<class T> istream& operator>>(istream& in, complex<T>& o) {
    T X, Y; in >> X >> Y; o.real(X); o.imag(Y); return in;
}
template<class T> bool operator<(const complex<T>& a, const complex<T>& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}
const int K = 1000;
struct query {
    int l, r, i;
    bool operator<(const query& o) const {
        if (l/K != o.l/K) return l/K < o.l/K;
        return r < o.r;
    }
};
const int max_n = 1e5;
int n, q; 
V<pt> pts[max_n], sides;
struct chash {
    size_t operator()(array<int, 2> a) const {
        return hash<int64_t>()(a[0]^((int64_t)a[1] << 32));
    }
};

void solve() {
    cin >> n;    
    V<pt> a;
    vi pre_sizes(n+1);
    for (int i = 0; i < n; i++) {
        int k; cin >> k; pts[i].resize(k); 
        for (int j = 0; j < k; j++) cin >> pts[i][j];
        pre_sizes[i+1] = pre_sizes[i]+k;

        pts[i].pb(pts[i][0]);
        for (int j = 0; j < k; j++) {
            pt vec = pts[i][j+1]-pts[i][j];
            int g = gcd(vec.x, vec.y);
            vec /= g;
            a.pb(vec);
        }
    }

    V<query> queries;
    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; 
        queries.pb({pre_sizes[l-1], pre_sizes[r], i});
    }
    sort(all(queries));
    unordered_map<array<int, 2>, int, chash> f;
    V<bool> vis(pre_sizes[n]);
    int cur = 0;
    auto check = [&](int i) {
        array<int, 2> val = {a[i].x, a[i].y};
        if (vis[i]) {
            f[val]--;
            cur -= !f[val];
        } else {
            cur += !f[val];
            f[val]++;
        }
        vis[i] = !vis[i];
    };
    vi ans(q);
    int l = 0, r = 0;
    for (auto [L, R, I] : queries) {
        while (l < L) check(l++);
        while (l > L) check(--l);
        while (r < R) check(r++);
        while (r > R) check(--r);
        ans[I] = cur;
    }

    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
