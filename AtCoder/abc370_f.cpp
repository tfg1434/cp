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

int w, cut_lines;

void solve() {
    int n, k; cin >> n >> k;
    vi a(n);
    int A = 0;
    for (int &i : a) cin >> i, A += i;
    a.insert(end(a), all(a));

    int lo = 0, hi = A/k+1;
    while (hi-lo > 1) {
        int w = (lo+hi)/2;
        // cnt[power][i] = how many items it takes to make 2^power groups, -1 if impossible
        array<vi, LOGN> cnt;
        for (int i = 0; i < LOGN; i++) cnt[i].resize(2*n, -1);
        int cur = 0, j = 0;
        for (int i = 0; i < 2*n; i++) {
            while (cur < w && j < 2*n) {
                cur += a[j];
                j++;
            }
            if (cur >= w) {
                cnt[0][i] = j-i;
            } 
            cur -= a[i];
        }

        for (int power = 1; power < LOGN; power++) {
            for (int i = 0; i < n; i++) {
                int tmp = cnt[power-1][i];
                if (tmp == -1 || i+tmp >= 2*n || cnt[power-1][i+tmp] == -1) {
                    continue;
                }
                cnt[power][i] = tmp+cnt[power-1][i+tmp];
            }
        }

        bool possible = false;
        int cut_lines = 0;
        for (int i = 0; i < n; i++) {
            int j = i, groups = 0;
            for (int power = LOGN-1; power >= 0; power--) {
                if (k-groups >= p2(power)) {
                    if (cnt[power][j] == -1 || j+cnt[power][j] > i+n) {
                        break;
                    }
                    groups += p2(power);
                    j += cnt[power][j];
                }
            }
            if (groups >= k) {
                possible = true;
                cut_lines++;
            }
        }

        if (possible) {
            if (ckmax(::w, w)) {
                ::cut_lines = cut_lines;
            }
            lo = w;
        } else {
            hi = w;
        }
    }

    cout << w << ' ' << n-cut_lines << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
