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

const int K = 1e6;
int sp[K+1];

void solve() {
    for (int i = 2; i <= K; i++) {
        for (int j = i; j <= K; j += i) {
            if (!sp[j]) sp[j] = i;
        }
    }

    int n, k; cin >> n >> k; 
    map<int, int> pf_L, pf_k;
    vi c(n);
    for (int& i : c) {
        cin >> i;
        map<int, int> pf;
        while (i > 1) {
            int d = sp[i];
            pf[d]++;
            i /= d; 
        }
        for (auto [u, v] : pf) ckmax(pf_L[u], v);
    }
    
    while (k > 1) {
        int d = sp[k];
        pf_k[d]++;
        k /= d; 
    }

    for (auto [u, v] : pf_k) if (v > pf_L[u]) {
        cout << "No\n";
        return;
    }
    cout << "Yes\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
