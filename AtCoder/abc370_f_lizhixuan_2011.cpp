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

constexpr int p2(int x) { return (int)1 << x; }

const int N = 1e5, K = 1e4, LOGN = 18;
int n, k; 
vi a, pre;

int check(int x) {
    if (pre[n] < x) return 0;
    V<array<int, 2>> c(n), d(n);
    int l = -1, sum = 0;
    for (int r = 0; r < n; r++) {
        sum += a[r];
        while (l+1 <= r && sum-a[l+1] >= x) {
            l++;
            sum -= a[l];
        }
        if (sum >= x) {
            c[r][0] = l;
            c[r][1] = 1;
        } else {
            c[r][0] = r;
            c[r][1] = 0;
        }
    }
    for (int i = 0; i < n; i++) {
        if (c[i][0] == -1) continue;
        c[i][1] += c[c[i][0]][1];
        c[i][0] = c[c[i][0]][0];
    }
    l = n, sum = 0;
    for (int r = n-1; r >= 0; r--) {
        sum += a[r];
        while (l-1 >= r && sum-a[l-1] >= x) { 
            l--;
            sum -= a[l];
        }
        if (sum >= x) {
            d[r][0] = l;
            d[r][1] = 1;
        } else {
            d[r][0] = r;
            d[r][1] = 0;
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (d[i][0] >= n) continue;
        d[i][1] += d[d[i][0]][1];
        d[i][0] = d[d[i][0]][0];
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!i) {
            cnt += d[i][1] >= k;
        } else {
            int extra = 0;
            if (c[i-1][0] != -1) extra += pre[c[i-1][0]+1];
            if (d[i][0] <= n) extra += pre[n]-pre[d[i][0]];
            cnt += c[i-1][1]+d[i][1]+(extra >= x) >= k;
        }
    }
    return cnt;
}

void solve() {
    cin >> n >> k;
    a.resize(n);
    pre.resize(n+1);
    for (int &i : a) cin >> i;
    partial_sum(all(a), pre.begin()+1);

    int lo = 0, hi = pre[n]/k+1;
    while (hi-lo > 1) {
        int w = (lo+hi)/2;
        check(w) ? lo = w : hi = w;
    }

    cout << lo << ' ' << n-check(lo) << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}

