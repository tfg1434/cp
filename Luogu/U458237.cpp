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
    int n, m; cin >> n >> m;    
    string a[2]; cin >> a[0] >> a[1];
    int m_a = count(all(a[0]), '#'), m_b = m-m_a;
    array<int, 2> pos = {-1, -1};
    int cur = 0;
    auto upd = [&](int i) {
        while (pos[i] < 0 || a[i][pos[i]] != '#') pos[i]++;
        a[i][pos[i]] = cur+'a';
        cur = (cur+1)%26;
        m_a -= !i;
        m_b -= i;
    };

    while (m_a > 0) {
        if (m_a > 0 && (!cur || m_b < 26-cur)) {
            upd(0);
        } else {
            upd(1);
        }
    }
    cout << a[0] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
