// #pragma GCC optimize("Ofast,no-stack-protector")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 1e18; // 1e9
const int P = 1e9+7; // 998244353;
const double PI = acos(-1.0);

using pi = pair<int,int>;

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;
using vpi = V<pi>;
#define all(x) begin(x), end(x)

int n, q;
vi a;
vpi queries;

vpi t;
void build(int v, int l, int r) {
    if (l == r-1) {
        t[v] = { a[l], l };
        return;
    }
    int m = (l+r)/2;
    build(2*v+1, l, m);
    build(2*v+2, m, r);
    t[v] = max(t[2*v+1], t[2*v+2]);
}
pi find_max(int v, int l, int r, int L, int R) {
    if (r <= L || R <= l) return {-1, -1};
    if (L <= l && r <= R) return t[v];
    int m = (l+r)/2;
    return max(find_max(2*v+1, l, m, L, R), find_max(2*v+2, m, r, L, R));
}
void init_tree() {
    int size = 1;
    while (size < 2*n) size *= 2;
    t.clear();
    t.resize(size);
    build(0, 0, n);
}

vi work() {
    vi res(q);
    init_tree();
    auto find_maximums = [&](int l, int r) -> pi{
        assert(r-l > 1);
        int m = find_max(0, 0, n, l, r).s;
        if (m == l) return {m, find_max(0, 0, n, l+1, r).s};
        if (m == r-1) return {m, find_max(0, 0, n, l, r-1).s};
        int m1 = find_max(0, 0, n, l, m).s;
        int m2 = find_max(0, 0, n, m+1, r).s;
        if (a[m1] > a[m2]) return {m, m1};
        return {m, m2};
    };

    for (int i = 0; i < q; i++) {
        auto [p, k] = queries[i];
        if (k == 1) continue;
        if (p+k > n) continue;
        
        auto [m1, m2] = find_maximums(p, p+k);
        res[i] += (p+k == n || a[p+k] > a[p]) && m2 == p;

        if (p+k == n || a[p+k] > a[m1]) {
            res[i] += p+k - m1 - 1;
        }
    }
    return res;
}

void solve() {
    cin >> n >> q;
    a.resize(n); for (auto&x : a) cin >> x, x--;
    queries.resize(q); for (auto& query : queries) cin >> query.f >> query.s, query.f--;

    auto res1 = work();
    reverse(all(a));
    for (auto& [p, k] : queries) p = n-1-p;
    auto res2 = work();
    for (int i = 0; i < q; i++) {
        if (queries[i].s == 1) { 
            cout << 1 << '\n';
        } else {
            cout << res1[i]+res2[i] << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();

    return 0;
}
