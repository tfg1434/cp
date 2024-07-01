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
    string last;
    for (int i = 0; i < n-1; i++) if ((s[i]-'0')%2 == 0) {
        if (s[i]-'0' < s[n-1]-'0') {
            swap(s[i], s[n-1]);
            cout << s << '\n';
            return;
        } else {
            last = s;
            swap(last[i], last[n-1]);
        }
    }
    if (last.size()) {
        cout << last << '\n';
    } else {
        cout << -1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
