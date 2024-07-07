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
    string s, t;
    cin >> s >> t;
    s += "..";
    t += "..";
    n += 2;
    map<string, int> dist;
    queue<string> q;
    q.push(s);
    int cur_dist = 0;
    while (q.size()) {
        int siz = q.size();
        while (siz--) {
            string u = q.front(); q.pop();
            if (dist.count(u)) continue;
            dist[u] = cur_dist;

            int pos_empty;
            for (pos_empty = 0; u[pos_empty] != '.'; pos_empty++) {}
            for (int i = 0; i+1 < n; i++) if (i+1 < pos_empty || i > pos_empty+1) {
                swap(u[i], u[pos_empty]);
                swap(u[i+1], u[pos_empty+1]);
                q.push(u);
                swap(u[i], u[pos_empty]);
                swap(u[i+1], u[pos_empty+1]);
            }
        }
        cur_dist++;
    }

    cout << (dist.count(t) ? dist[t] : -1) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
