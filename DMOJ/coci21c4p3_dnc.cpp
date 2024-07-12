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

const int N = 2e5;
bool vis[N];
int fre[N], fre_bal[2*N+2];
int n, ans;
vi a;

void dnc(int l, int r) {
    if (l == r-1) return void(ans++);
    int m = (l+r)/2;
    dnc(l, m);
    dnc(m, r);

    vi dom;
    for (int i = m-1; i >= l; i--) {
        if (2*(++fre[a[i]]) > m-i && !vis[a[i]]) {
            vis[a[i]] = true;
            dom.pb(a[i]);
        }
    }
    for (int i = m-1; i >= l; i--) fre[a[i]]--;

    for (int i = m; i < r; i++) {
        if (2*(++fre[a[i]]) > i-(m-1) && !vis[a[i]]) {
            vis[a[i]] = true;
            dom.pb(a[i]);
        }
    }
    for (int i = m; i < r; i++) fre[a[i]]--;
    for (int i = l; i < r; i++) vis[a[i]] = false;

    for (int val : dom) {
        int s = 0 + n;
        for (int i = m-1; i >= l; i--) {
            s += a[i] == val ? 1 : -1;
            fre_bal[s]++;
        }

        for (int i = m-l-1 + n; i >= -(m-l) + n; i--) {
            fre_bal[i] += fre_bal[i+1];
        }
        s = 0;
        for (int i = m; i < r; i++) {
            s += a[i] == val ? 1 : -1;
            ans += fre_bal[-s+1 + n];
        }

        for (int i = -(m-l)+n; i <= m-l+n; i++) fre_bal[i] = 0;
    }
}

void solve() {
    cin >> n;    
    a.resize(n);
    vi values;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        values.pb(a[i]);
    }
    sort(all(values));
    values.erase(unique(all(values)), values.end());
    for (int& x : a) x = lwb(values, x);
    int mx = values.size();

    dnc(0, n);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
