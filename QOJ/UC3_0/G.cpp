#include <bits/stdc++.h>
using namespace std;
using db = long double;
const db inf = 1e18;

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

int n, m, p;
db f(db x, db y) {
    if (x > y) swap(x, y);
    db res = 0.5*x;
    if (p+x <= y) res += 0.5*(x+p*0.5);
    else res += 0.5*(y*p - 0.5*(y-x)*(y-x))/p; 
    return res;
}

const int max_n = 1e3;
db e[max_n][max_n];

void solve() {
    cin >> n >> m >> p;
    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (i == n-1 && j == m-1) continue;
            db x = i == n-1 ? inf : e[i+1][j];
            db y = j == m-1 ? inf : e[i][j+1];
            e[i][j] = f(x, y);
        }
    }

    cout << fixed << setprecision(6) << e[0][0] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
