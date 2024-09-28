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
    int k; cin >> k;
    if (k%2) k++;
    int n = 2+k; // n is the number of colors in the mex coloring

    cout << 2*n << ' ' << n*(n-1) << ' ' << 2 << '\n';
    for (int i = 0; i < 2*n; i++) cout << i%2+1 << " \n"[i==2*n-1];
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            cout << 2*i+1 << ' ' << 2*j+2 << '\n';
            cout << 2*i+2 << ' ' << 2*j+1 << '\n';
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
