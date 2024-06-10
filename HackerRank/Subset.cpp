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

// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define pct __builtin_popcount
constexpr int p2(int x) { return (int)1 << x; }
constexpr int msk2(int x) { return p2(x)-1; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 

int CNT_AM8, A[p2(16)], B[p2(16)], C[p2(16)], x, coef;

// pct(mask) <= 8
// A[mask] = #(mask)
// C[mask] = #(supermasks of mask)
// pc > 8
// B[mask] = #(submasks of mask)
void upd_c() {
    CNT_AM8 += coef;
    int X[8], k = 0;
    for (int i = 0; i < 16; i++) if (x & p2(i)) X[k++] = i;
    for (int i = 0; i < p2(k); i++) {
        int bit = 0;
        for (int j = 0; j < k; j++) if (i & p2(j)) {
            bit |= p2(X[j]);
        }
        C[bit] += coef;
    }
}
void upd_b() {
    int X[8], k = 0;
    for (int i = 0; i < 16; i++) if (!(x & p2(i))) X[k++] = i;
    for (int i = 0; i < p2(k); i++) {
        int bit = x;
        for (int j = 0; j < k; j++) if (i & p2(j)) {
            bit |= p2(X[j]);
        }
        B[bit] += coef;
    }
}

int count_for_am8() {
    int X[8], k = 0;
    for (int i = 0; i < 16; i++) if (x & p2(i)) X[k++] = i;
    int res = 0;
    for (int i = 0; i < p2(k); i++) {
        int bit = 0;
        for (int j = 0; j < k; j++) if (i & p2(j)) {
            bit |= p2(X[j]);
        }
        res += A[bit];
    }
    return res;
}
// count how many masks with at most 8 bits share >0 bits with ~x
int count_those_am8() {
    int X[8], k = 0;
    for (int i = 0; i < 16; i++) if (!(x & p2(i))) X[k++] = i;
    int res = CNT_AM8;
    for (int i = 1; i < p2(k); i++) {
        int bit = 0;
        for (int j = 0; j < k; j++) if (i & p2(j)) {
            bit |= p2(X[j]);
        }
        int pie = pct(bit)%2 ? 1 : -1;
        res -= pie*C[bit];
    }
    return res;
}

void solve() {
    int q; cin >> q;
    while (q--) {
        string tp; cin >> tp;
        cin >> x; int pc = pct(x);

        if (tp == "add" || tp == "del") {
            coef = tp == "add" ? 1 : -1;
            if (pc <= 8) {
                A[x] += coef;
                upd_c();
            } else {
                upd_b();
            }

        } else {
            if (pct(x) <= 8) {
                cout << count_for_am8() << '\n';
            } else {
                cout << B[x] + count_those_am8() << '\n';
            }
        }
    }
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
