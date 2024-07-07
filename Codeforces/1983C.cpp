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

int flip(int x) {
    if (x == 1) return 2;
    return 1;
}

void solve() {
    int n; cin >> n;
    V<vi> a(3, vi(n));
    V<vi> pre(3, vi(n+1));
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            pre[i][j+1] = pre[i][j]+a[i][j];
        }
    }
    int thres = (pre[0][n]+2)/3;

    int orient = 0, person, sl, sr;
    for (int i = 0; i < 3; i++) {
        for (int j = 1; j < n-1; j++) {
            for (int ori = 1; ori <= 2; ori++) {
                int min_r = lwb(pre[i], pre[i][j]+thres);
                if (min_r >= n) break;
                int L = pre[(i+ori)%3][j];
                int R = pre[(i+flip(ori))%3][n]-pre[(i+flip(ori))%3][min_r];
                if (L >= thres && R >= thres) {
                    orient = ori;
                    person = i;
                    sl = j, sr = min_r;
                }
            }
        }
    }

    if (orient) {
        vi ans(6);
        ans[2*person] = sl+1;
        ans[2*person+1] = sr;
        ans[2*((person+orient)%3)] = 1;
        ans[2*((person+orient)%3)+1] = sl;
        ans[2*((person+flip(orient))%3)] = sr+1;
        ans[2*((person+flip(orient))%3)+1] = n;
        for (int i = 0; i < 6; i++) cout << ans[i] << " \n"[i==5];
    } else {
        cout << -1 << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}

