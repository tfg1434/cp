// top-down approach

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
V<pair<set<int>, int>> a;

void answer(int x, int y) {
    cout << "YES\n";
    cout << x+1 << ' ' << y+1 << '\n';
}

void solve() {
    cin >> n >> m;
    a.resize(n);
    for (int i = 0; i < n; i++) {
        int k; cin >> k; 
        while (k--) {int c; cin >> c; a[i].f.insert(c);}
        a[i].s = i;
    }
    sort(all(a), [](const pair<set<int>, int>&a, const pair<set<int>, int>&b) {return a.f.size() > b.f.size();});

    vi prv(m+1, -1), p(n, -1);
    V<map<int, int>> sc(n);
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int c : a[i].f) {
            if (prv[c] != -1) {
                p[i] = prv[c];
            }
            prv[c] = i;
        }
        if (p[i] == -1) continue;

        for (int c : a[i].f) {
            if (!a[p[i]].f.count(c)) {
                answer(a[i].s, a[p[i]].s);
                return;
            }
        }
        for (int c : a[i].f) {
            if (sc[p[i]].count(c)) {
                answer(a[i].s, a[sc[p[i]][c]].s);
                return;
            }
            sc[p[i]][c] = i;
        }
    }
    cout << "NO\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
