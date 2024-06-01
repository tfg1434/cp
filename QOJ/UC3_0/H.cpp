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

const double SQRT2 = sqrt(2);
int q, w;
const int K = 450, max_n = 2e5;
int buf[max_n/K+1], cnt[max_n/K+1], a[max_n];

void solve() {
    cin >> q >> w; 
    set<array<int, 2>> active;
    while (q--) {
        int x, y; cin >> x >> y;
        int l = max(0, x-y), r = min(w, x+y);
        int L = l/K, R = r/K;
        if (active.count({x, y})) {
            if (L == R) {
                for (int i = l; i < r; i++) a[i]--, cnt[L] -= !a[i];
            } else {
                for (int i = l; i < (L+1)*K; i++) a[i]--, cnt[L] -= !a[i];
                for (int b = L+1; b < R; b++) buf[b]--;
                for (int i = R*K; i < r; i++) a[i]--, cnt[R] -= !a[i];
            }
            active.erase({x, y});
        } else {
            if (L == R) {
                for (int i = l; i < r; i++) cnt[L] += !a[i], a[i]++;
            } else {
                for (int i = l; i < (L+1)*K; i++) cnt[L] += !a[i], a[i]++;
                for (int b = L+1; b < R; b++) buf[b]++;
                for (int i = R*K; i < r; i++) cnt[R] += !a[i], a[i]++;
            }
            active.insert({x, y});
        }

        int ans = 0;
        l = 0, r = w;
        L = l/K, R = r/K;
        if (L == R) {
            for (int i = l; i < r; i++) ans += a[i] > 0;
        } else {
            for (int i = l; i < (L+1)*K; i++) ans += a[i] > 0;
            for (int b = L+1; b < R; b++) ans += buf[b] ? K : cnt[b];
            for (int i = R*K; i < r; i++) ans += a[i] > 0;
        }
        cout << fixed << setprecision(6) << SQRT2*ans << '\n';
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
