// bottom-up approach

#include <bits/stdc++.h>
using namespace std;

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
V<pair<vi, int>> a;

void solve() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k; a[i].f.resize(k);
        for (auto& c : a[i].f) cin >> c;
        a[i].s = i;
    }
    sort(all(a), [](const pair<vi, int>&a, const pair<vi, int>&b) {return a.f.size() < b.f.size();});

    vi prv(m+1, -1), cnt(n);
    for (int i = 0; i < n; i++) {
        vi sons;
        for (auto c : a[i].f) {
            if (prv[c] != -1) {
                if (!cnt[prv[c]]) sons.pb(prv[c]);
                cnt[prv[c]]++;
            }
            prv[c] = i;
        }
        for (int son : sons) {
            if (cnt[son] < a[son].f.size()) {
                cout << "YES\n";
                cout << a[i].s+1 << ' ' << a[son].s+1 << '\n';
                return;
            }
        }
        for (int son : sons) { cnt[son] = 0; }
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
