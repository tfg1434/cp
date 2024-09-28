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
#define len(x) (int)((x).size())
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-begin(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-begin(a); }
template<class T> bool ckmin(T& a, const T& b) { return a > b ? a=b, true : false; }
template<class T> bool ckmax(T& a, const T& b) { return a < b ? a=b, true : false; }
#define pct __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
constexpr int p2(int x) { return (int)1 << x; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-clz(x); } // floor(log2(x)) 

struct Line {
    int a, b, c;
    bool operator<(const Line& o) {
        if (a*o.b!=b*o.a) return a*o.b>b*o.a;
        return c*o.a>a*o.c;
    }
};

const int MAX = 1e9

void solve() {
    int n; cin >> n;
    V<Line> lines(n);
    for (int& [a, b, c] : lines) cin >> a >> b >> c;
    sort(all(lines));

    int x_lim = MAX;
    V<array<int, 2>> ch;
    for (auto& line : lines) {
        auto [a, b, c] = line;

        if(len(ch)){
            auto[A,B,C]=ch[-1].bk;
            if(a*B==b*A)continue;
        }
        while(len(ch)>1){

        }
            auto [A, B, C] = ch.bk.s;
            int coord = ch.bk.f;
            if (less(line, ch.bk.s, coord)) {
                ch.pop_back();
            } else {
                break;
            }
        }

        int inter = min(f_inter(ch.bk.s, line), max_coord);
        if (inter >= 0) ch.pb({inter, line});
    }

    int 
    for (auto& line : lines) {

    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
