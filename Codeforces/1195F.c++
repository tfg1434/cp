// the proper way to solve. # diff on a segment = MST

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
const int max_n = 1e5;
int n, q; 
V<pt> pts[max_n], sides;
struct chash {
    size_t operator()(array<int, 2> a) const {
        return hash<int64_t>()(a[0]^((int64_t)a[1] << 32));
    }
};

V<vi> t;
void build(int v, int l, int r, const vi& a) {
    if (l == r-1) {
        t[v].pb(a[l]);
        return;
    }
    int m = (l+r)/2;
    build(2*v+1, l, m, a);
    build(2*v+2, m, r, a);
    merge(all(t[2*v+1]), all(t[2*v+2]), back_inserter(t[v]));
}
void init_tree(const vi& a) {
    int size = 1;
    while (size < 2*a.size()) size *= 2;
    t.resize(size);
    build(0, 0, a.size(), a);
}
int count_at_least(int v, int l, int r, int L, int R, int z) {
    if (r <= L || R <= l) return 0;
    if (L <= l && r <= R) return r-l-lwb(t[v], z);
    int m = (l+r)/2;
    return count_at_least(2*v+1, l, m, L, R, z) +
        count_at_least(2*v+2, m, r, L, R, z);
}

void solve() {
    cin >> n;    
    unordered_map<array<int, 2>, int, chash> m;
    vi pre_sizes(n+1);
    vi a;
    for (int i = 0; i < n; i++) {
        int k; cin >> k; pts[i].resize(k); 
        for (int j = 0; j < k; j++) cin >> pts[i][j];
        pre_sizes[i+1] = pre_sizes[i]+k;

        pts[i].pb(pts[i][0]);
        for (int j = 0; j < k; j++) {
            pt vec = pts[i][j+1]-pts[i][j];
            int g = gcd(vec.x, vec.y);
            vec /= g;
            array<int, 2> as_arr = {vec.x, vec.y};
            if (!m.count(as_arr)) {
                m[as_arr] = m.size();
            }
            a.pb(m[as_arr]);
        }
    }
    vi prv(m.size(), -1), nxt(a.size(), a.size());
    for (int i = 0; i < a.size(); i++) {
        if (prv[a[i]] != -1) nxt[prv[a[i]]] = i;
        prv[a[i]] = i;
    }
    init_tree(nxt);

    cin >> q;
    for (int i = 0; i < q; i++) {
        int l, r; cin >> l >> r; 
        l = pre_sizes[l-1];
        r = pre_sizes[r];
        cout << count_at_least(0, 0, pre_sizes[n], l, r, r) << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
