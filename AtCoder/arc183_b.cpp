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
    int n, k; cin >> n >> k;    
    vi a(n), b(n);
    V<bool> A(n);
    for (int& i : a) {
        cin >> i; i--;
        A[i] = true;
    }
    for (int& i : b) cin >> i, i--;

    if (a == b) {
        cout << "Yes\n";
        return;
    }

    if (k == 1) {
        b.erase(unique(all(b)), b.end());
        int j = 0;
        bool subseq = true;
        for (int i = 0; i < b.size(); i++) {
            while (j < a.size() && a[j] != b[i]) j++;
            if (j == a.size()) subseq = false;
            j++;
        }
        cout << (subseq ? "Yes" : "No") << '\n';
        return;
    }

    vi last(n, -1);
    bool possible = true;
    int closest_dist = n;
    for (int i = 0; i < n; i++) {
        possible &= A[b[i]];
        if (last[b[i]] != -1) {
            ckmin(closest_dist, i - last[b[i]]);
        }
        last[b[i]] = i;
    }
    possible &= closest_dist <= k;

    cout << (possible ? "Yes" : "No") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
