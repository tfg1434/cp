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

void solve() {
    int n; cin >> n;
    vi a(n), b(n);
    for (int& i : a) cin >> i;
    for (int& i : b) cin >> i;
    map<int, int> m;
    for (int i = 0; i < n; i++) {
        if (m.count(a[i]) && m[a[i]] != b[i]) {
            cout << "No\n";
            return;
        }
        m[a[i]] = b[i];
    }
    n = m.size();
    a.clear(); b.clear();
    for (auto [u, v] : m) {
        a.pb(u);
        b.pb(v);
    }

    if (n == 1) {
        cout << "Yes\n";
        cout << (int)1e9+b[0]-a[0] << ' ' << (int)1e9 << '\n';
        return;
    }

    vi r(n-1);
    iota(all(r), 1);
    r.insert(r.begin(), n);
    int K = *max_element(all(b))+1;

    // vi B(n);
    // for (int i = 0; i < n; i++) B[i] = b[i]+K*r[i];
    vi x(n);
    for (int i = n-2; i >= 0; i--) {
        x[i] = b[(n-i)%n]-b[n-1-i]+K;
    }

    cout << "Yes\n";
    int rshift = x[0]-a[1];
    cout << rshift << ' ' << a[n-1]+rshift << '\n';
    for (int i = 1; i < n; i++) {
        rshift += x[i];
        cout << x[i] << ' ' << a[n-1-i]+rshift << '\n';
    }
    ps(x);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
