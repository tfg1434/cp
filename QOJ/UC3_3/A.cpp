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

void solve() {
    string s; cin >> s;
    int n = s.size();
    if (n == 1) {
        cout << "YES\n";
        cout << s << '\n';
        return;
    }

    map<char, int> freq;
    for (char c : s) freq[c]++;
    if (freq.size() == 1) {
        cout << "NO\n";
        return;
    }
    if (freq.size() == 2) {
        auto [x0, y0] = *freq.begin();
        auto [x1, y1] = *next(freq.begin());
        // if (y0 > y1) swap(x0, x1), swap(y0, y1);
        if (y0 == 1 || y1 == 1) {
            cout << "YES\n";
            char c = y0 == 1 ? x0 : x1;
            char d = y0 == 1 ? x1 : x0;
            cout << c << string(n-1, d) << '\n';
        } else {
            cout << "NO\n";
        }
        return;
    }

    V<pair<int, char>> a;
    for (auto[x, y] : freq) a.pb({y, x});
    sort(all(a));
    cout << "YES\n";
    while (a.size()) {
        V<pair<int, char>> A;
        for (int i = 0; i < a.size(); i++) {
            cout << a[i].s; 
            if (--a[i].f) A.pb(a[i]);
        }
        a = A;
    }

    cout << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
