#include <bits/stdc++.h>
using namespace std;

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

const int MAX = 1e7;
int minp[MAX+1], sg[MAX+1];

void pc() {
    int prime_ind = 1;
    for (int i = 2; i <= MAX; i++) if (!minp[i]) {
        for (int j = i; j <= MAX; j += i) if (!minp[j]) {
            minp[j] = i;
            sg[i] = prime_ind;
        }
        prime_ind++;
    }

    sg[0] = 0;
    sg[1] = 1;
    sg[2] = 0;
    for (int i = 3; i <= MAX; i++) if (minp[i] < i) {
        if (i%2 == 0) sg[i] = 0;
        else sg[i] = sg[minp[i]];
    }

    // for (int i = 0; i <= 20; i++) {
        // ps(i, minp[i], sg[i]);
    // }
}

void solve() {
    int n; cin >> n;
    int XOR = 0;
    vi a(n);
    for (int& i : a) {
        cin >> i;
        XOR ^= sg[i];
    }

    cout << (XOR ? "Alice" : "Bob") << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    pc();
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
