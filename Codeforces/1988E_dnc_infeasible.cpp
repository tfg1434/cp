// my initial idea -- do dnc on the min elem
// claim: there are O(n) calls to solve(l, r)
// proof: draw bonds between each element, when you call solve you break 
// a segment into two smaller segments, and the total bonds is reduced by 1
//
// r-l = 1 then 1 call
// r-l = 2 then 1+1=2 calls
// suppose r-l = k takes O(k) calls
// r-l = k+1 will always make 2 calls + at most O(k) more. so O(k)
//
// i don't know how to merge [0, i) and (i, n].


#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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

using Query = array<int, 3>:
const int N = 5e5;
int a[N], ans[2*N];

void dnc(int l, int r, const V<Query>& queries) {
    if (l == r-1) {
        for (auto [L, R, I] : queries) ans[I] += a[l];
        return;
    }

    auto mn = min_element(a.begin()+l, a.begin()+r);
    int m = mn-a.begin();

    V<Query> todo[2];
    for (const auto& query : queries) {
        auto [L, R, I] = query;
        if (L <= m && m < R) {
            ans[I] += (R-L+1)*(*mn);
        }
        todo[R <= m].pb(query);
    }
    if (l < m) dnc(l, m, todo[0]);
    if (m+1 < r) dnc(m+1, r, todo[1]);
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    V<Query> queries;
    for (int i = 0; i < n; i++) {
        queries[i] = {0, i, i};
        queries[i+n] = {i+1, n, i+n};
    }
    dnc(0, n, queries);

    vi sol(n);
    for (int i = 0; i < n; i++) sol[]
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}


