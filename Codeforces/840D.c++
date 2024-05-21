// dunno why RTE

#include <bits/stdc++.h>
using namespace std;
const int inf = 1e9;

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

const int max_n = 3e5, max_k = 5;
int n, q;
vi a, ans;
V<array<int, 3>> queries;
int f[max_n+1];

void dnc(int l, int r, vi query_inds) {
    if (l == r-1) {
        for (int ind : query_inds) {
            ans[ind] = a[l];
        }
        return;
    }

    V<unordered_set<int>> most_freq_l, most_freq_r;
    unordered_map<int, vi> where_l, where_r;
    int m = (l+r)/2;
    {
        unordered_set<int> s;
        for (int i = m+1; i <= r; i++) {
            where_r[a[i-1]].pb(i-1);
            f[a[i-1]]++;
            if (f[a[i-1]]*max_k > i-m) {
                s.insert(a[i-1]);
            }
            for (int x : s) if (f[x]*max_k <= i-m) {
                s.erase(x);
            }
            most_freq_r.pb(s);
        }
        for (int i = m+1; i <= r; i++) f[a[i-1]]--;
    }
    {
        unordered_set<int> s;
        for (int i = m-1; i >= l; i--) {
            where_l[a[i]].pb(-i);
            f[a[i]]++;
            if (f[a[i]]*max_k > m-i) {
                s.insert(a[i]);
            }
            for (int x : s) if (f[x]*max_k <= m-i) {
                s.erase(x);
            }
            most_freq_l.pb(s);
        }
        for (int i = m-1; i >= l; i--) {
            f[a[i]]--;
            sort(all(where_l[a[i]]));
        }
        reverse(all(most_freq_l));
    }

    vi todo[2];
    for (auto ind : query_inds) {
        auto [L, R, K] = queries[ind];
        if (R <= m) {
            todo[0].pb(ind);
            continue;
        }
        if (L >= m) {
            todo[1].pb(ind);
            continue;
        }
        vi cand;
        for (int c : most_freq_l[m-1-L]) cand.pb(c);
        for (int c : most_freq_r[R-(m+1)]) cand.pb(c);
        sort(all(cand));
        for (int c : cand) {
            int cnt_r = lwb(where_r[c], R);
            int cnt_l = upb(where_l[c], -L);
            if ((cnt_l+cnt_r)*K > R-L) {
                ans[ind] = c;
                break;
            }
        }
    }
    dnc(l, m, todo[0]);
    dnc(m, r, todo[1]);
}

void solve() {
    cin >> n >> q;
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < q; i++) {
        int l, r, k; cin >> l >> r >> k; l--;
        queries.pb({l, r, k});
    }
    ans.assign(q, -1);

    vi query_inds(q); iota(all(query_inds), 0);
    dnc(0, n, query_inds);
    for (int i = 0; i < q; i++) cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
