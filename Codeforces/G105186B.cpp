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
template<class T> ostream& operator<<(ostream& out, V<T>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i];
        if (i+1 < a.size()) cout << ' ';
    }
    return out;
}

int n;

void solve() {
    cin >> n;
    if (n == 1) {
        cout << "! 0" << endl;
        return;
    }

    vi p;
    {
        cout << "? 0 1" << endl;
        int s; cin >> s;
        p = s ? vi{1, 0} : vi{0, 1};
    }
    for (int i = 2; i < n; i++) {
        ps(p);
        vi query;
        query.pb(i);
        for (int j = 0; j < i-1; j++) {
            query.pb(p[j]);
            query.pb(p[i-1]);
            query.pb(i);
        }
        query.insert(end(query), 1+all(query));
        query.pb(p[i-1]);
        cout << "? " << query.size() << ' ' << query << endl;
        int s; cin >> s;
        if (s == 2*i) {
            p.insert(p.begin(), i);
        } else if (s == 2*i+1) {
            p.pb(i);
        } else {
            assert(s%4 == 0);
            int cnt_gt = s/4;
            ps("cnt gt", cnt_gt);
            p.insert(p.begin()+cnt_gt, i);
        }
    }

    vi ans(n);
    for (int i = 0; i < n; i++) ans[p[i]] = i;
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
