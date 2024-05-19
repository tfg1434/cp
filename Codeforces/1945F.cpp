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
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }

template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, 1 : 0; };

int n;
const int max_n = 2e5;
int p[max_n];
V<array<int, 2>> a;

void solve() {
    cin >> n; 
    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i][0], a[i][1]=i; sort(all(a));
    vi where(n); for (int i = 0; i < n; i++) where[a[i][1]] = i;
    for (int i = 0; i < n; i++) cin >> p[i], p[i]--, p[i] = where[p[i]];

    int pointer = a.size()-1;
    multiset<array<int, 2>> st;
    vb bad(n);
    int ans = 0, num = 0;
    for (int i = 1; i <= n; i++) {
        st.insert(a[pointer--]);
        if (ckmax(ans, (*begin(st))[0]*i)) num = i;

        bad[p[i-1]] = true;
        if (st.count(a[p[i-1]])) {
            st.erase(a[p[i-1]]);
            while (pointer >= 0) {
                if (!bad[pointer]) {
                    st.insert(a[pointer--]);
                    break;
                }
                pointer--;
            }
        }
        while (pointer >= 0 && bad[pointer]) {
            pointer--;
        }
        if (pointer < 0) break;
    }

    cout << ans << ' ' << num << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int t; cin >> t; while (t--) solve();
    return 0;
}
