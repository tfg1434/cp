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
    int w, h, s; cin >> w >> h >> s;
    if (w > h) swap(w, h);

    // handle s=2
    if ((w+h)%s == 0) {
        cout << 2*(w+h)/s << '\n';
        return;
    }

    auto answer = [&]() {
        if (h < s) {
            if (s == 2*w || s == 2*h) return 3;
            return 4;
        }
        if (h == s) {
            if (w == h) return 4;
            if (w < h) {
                if (2*w == s) return 3;
                return 4;
            }
        }
        // now s < h
        if (w > s)
        if (w == s) {
            return 2+(2*h+s-1)/s;
        }
        // now w < s

        if (s >= w)

    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
