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
    int n; cin >> n;
    string s; cin >> s;
    if (n == 1) {
        cout << "0\n";
        return;
    }

    int cnt = count(all(s), '1');
    bool has_00 = false;
    for (int i = 0; i+1 < n; i++) if (s.substr(i, 2) == "00") has_00 = true;

    int min_group = n;
    for (int i = 0; i < n; i++) if (s[i] == '1') {
        int j = i;
        while (j < n && s[j] == '1') j++;
        ckmin(min_group, j-i);
        i = j;
    }

    if (s[0] == '0' || s[n-1] == '0' || has_00) {
        cout << cnt << '\n';
    } else {
        cout << cnt+min_group << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

