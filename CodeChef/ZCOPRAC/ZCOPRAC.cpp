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

using db = long double;
const db max_r = 1.0, eps = 1e-12;
int n, p;

db f(const array<int, 3>& line, db x) { return line[0]*x+line[1]; }

void solve() {
    cin >> n >> p;    
    V<array<int, 3>> lines;
    for (int i = 0; i < n; i++) {
        int s0, s1; cin >> s0 >> s1;
        lines.pb({s0-s1, s1, i});
    }
    sort(all(lines));
    V<pair<db, int>> ch;
    for (int i = 0; i < n; i++) {
        while (ch.size() && f(lines[ch.back().s], ch.back().f)+eps < f(lines[i], ch.back().f)) {
            ch.pop_back();
        }
        if (!ch.size()) {
            ch.pb({0.0, i});
        } else {
            if (lines[i][0] == lines[ch.back().s][0]) {
                ch.pb({ch.back().f, i});
                continue;
            }
            db inter = 1.0*(lines[i][1]-lines[ch.back().s][1])/(lines[ch.back().s][0]-lines[i][0]);
            if (inter > max_r+eps) continue;
            ch.pb({inter, i});
        }
    }

    vi sol;
    for (int i = 0; i < ch.size(); i++) sol.pb(lines[ch[i].s][2]+1);
    sort(all(sol));
    cout << sol.size() << '\n';
    for (int i = 0; i < sol.size(); i++) cout << sol[i] << " \n"[i==sol.size()-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
