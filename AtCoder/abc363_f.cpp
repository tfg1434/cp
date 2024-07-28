#include <bits/stdc++.h>
using namespace std;
#define int int64_t

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

string rev(int n) {
    string s;
    while (n > 0) {
        s += char(n%10 + '0');
        n /= 10;
    }
    return s;
}
bool is_nonzero_pal(int n) {
    string s = to_string(n);
    return !count(all(s), '0') && s == rev(n);
}

unordered_map<int, string> mem;

string f(int n) {
    if (mem.count(n)) return mem[n];
    if (is_nonzero_pal(n)) {
        return mem[n] = to_string(n);
    }
    for (int d = 2; d*d <= n; d++) {
        string ds = to_string(d);
        if (count(all(ds), '0'))continue;

        if (n%d == 0 && n/d%stoll(rev(d)) == 0) {
            string lhs = to_string(d), rhs = rev(d);
            string res = f(n/d/stoll(rev(d)));
            if (res.size()) {
                return mem[n] = lhs+"*"+res+"*"+rhs;
            }
        }
    }
    return mem[n] = "";
}

void solve() {
    int n; cin >> n;
    string ans = f(n);
    cout << (ans.size() ? ans : "-1") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
