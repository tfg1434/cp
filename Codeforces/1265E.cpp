#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int P = 998244353;

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

int pw(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b%2) res = res*a%P;
        b /= 2;
        a = a*a%P;
    }
    return res;
}
int inv(int a) {
    return pw(a, P-2);
}
const int max_n = 2e5;
int n;
vi p;

void solve() {
    cin >> n;    
    p.resize(n);
    for (int i = 0; i < n; i++) cin >> p[i];

    int e0 = 0, cur = 1;
    for (int i = n-1; i >= 0; i--) {
        int pp = inv(p[i]*inv(100)%P);
        cur = cur*pp%P;
        e0 = (e0+cur)%P;
    }

    cout << e0 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
