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
    map<int, int> freq;
    for (int i = 0; i < n; i++) {
        int d; cin >> d;
        freq[d]++;
    }
    int carcass_nodes = n-freq[1];
    int max_deg = rbegin(freq)->f;
    
    if (max_deg <= 2) {
        cout << "No\n";
        return;
    }
    if (carcass_nodes <= 2) {
        cout << "No\n";
        return;
    }
    if (carcass_nodes == 3 && freq[max_deg] == 3) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
