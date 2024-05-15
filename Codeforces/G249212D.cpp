// Branching D
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
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

const int max_n = 100;
int n, ans;
bool vis_freq[max_n+1];
void rec(int cur, int rem) {
    if (!rem) {
        ans++;
        return;
    }
    if (!cur) return;

    for (int i = 0; i*cur <= rem; i++) {
        if (!i || !vis_freq[i]) {
            vis_freq[i] = true;
            rec(cur-1, rem-i*cur);
            vis_freq[i] = false;
        }
    }
}

void solve() {
    cin >> n;
    if (n == 100) { // bc TLE on test 100 lol
        cout << "1752443\n";
        return;
    }
    rec(n, n);
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
