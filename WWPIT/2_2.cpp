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

int n, x, m;
V<array<int, 3>> tests;
int pw(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b%2) res = res*a%m;
        b /= 2;
        a = a*a%m;
    }
    return res;
}
int inv(int a) { return pw(a, m-2); }

void solve1(int n, int x, int m) {
    n %= m; x %= m;
    ::n = n; ::x = x; ::m = m;
    int ans = 0;
    for (int i = 1; i <= n; i++) (ans += i*pw(x, i)%m) %= m;
    cout << ans << '\n';
}
void solve2(int n, int x, int m) {
    n %= m; x %= m;
    ::n = n; ::x = x; ::m = m;
    int ans = (n*pw(x, n+1)%m + m-(pw(x, n+1) + m - x)*inv(x+m-1)%m) % m * inv(x + m - 1) % m;
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; tests.resize(tc);
    int sum = 0;
    for (int i = 0; i < tc; i++) {
        cin >> tests[i][0] >> tests[i][1] >> tests[i][2]; 
        sum += tests[i][0];
    }
    if (sum <= 1e5) for (int i = 0; i < tc; i++) solve1(tests[i][0], tests[i][1], tests[i][2]);
    else for (int i = 0; i < tc; i++) solve2(tests[i][0], tests[i][1], tests[i][2]);

    return 0;
}
