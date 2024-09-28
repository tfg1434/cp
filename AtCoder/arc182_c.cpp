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

using i64 = long long;
template<class T>
constexpr T power(T a, i64 b) {
    T res {1};
    for (; b; b /= 2, a *= a) {
        if (b % 2) {
            res *= a;
        }
    }
    return res;
}
constexpr i64 mul(i64 a, i64 b, i64 p) {
    i64 res = a * b - i64(1.L * a * b / p) * p;
    res %= p;
    if (res < 0) {
        res += p;
    }
    return res;
}

template<i64 P>
struct MInt {
    i64 x;
    constexpr MInt() : x {0} {}
    constexpr MInt(i64 x) : x {norm(x % getMod())} {}
    
    static inline i64 Mod;
    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
    }
    constexpr static void setMod(i64 Mod_) {
        Mod = Mod_;
    }
    constexpr i64 norm(i64 x) const {
        if (x < 0) {
            x += getMod();
        }
        if (x >= getMod()) {
            x -= getMod();
        }
        return x;
    }
    constexpr i64 val() const {
        return x;
    }
    constexpr MInt operator-() const {
        MInt res;
        res.x = norm(getMod() - x);
        return res;
    }
    constexpr MInt inv() const {
        return power(*this, getMod() - 2);
    }
    constexpr MInt &operator*=(MInt rhs) & {
        if (getMod() < (1ULL << 31)) {
            x = x * rhs.x % int(getMod());
        } else {
            x = mul(x, rhs.x, getMod());
        }
        return *this;
    }
    constexpr MInt &operator+=(MInt rhs) & {
        x = norm(x + rhs.x);
        return *this;
    }
    constexpr MInt &operator-=(MInt rhs) & {
        x = norm(x - rhs.x);
        return *this;
    }
    constexpr MInt &operator/=(MInt rhs) & {
        return *this *= rhs.inv();
    }
    friend constexpr MInt operator*(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res *= rhs;
        return res;
    }
    friend constexpr MInt operator+(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res += rhs;
        return res;
    }
    friend constexpr MInt operator-(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res -= rhs;
        return res;
    }
    friend constexpr MInt operator/(MInt lhs, MInt rhs) {
        MInt res = lhs;
        res /= rhs;
        return res;
    }
    friend constexpr std::istream &operator>>(std::istream &is, MInt &a) {
        i64 v = 69;
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr std::ostream &operator<<(std::ostream &os, const MInt &a) {
        return os << a.val();
    }
    friend constexpr bool operator==(MInt lhs, MInt rhs) {
        return lhs.val() == rhs.val();
    }
    friend constexpr bool operator!=(MInt lhs, MInt rhs) {
        return lhs.val() != rhs.val();
    }
    friend constexpr bool operator<(MInt lhs, MInt rhs) {
        return lhs.val() < rhs.val();
    }
};
 
template<>
i64 MInt<0>::Mod = 998244353;
using Z = MInt<0>;

void solve() {
    int n, m; cin >> n >> m;
    for (int a = 0; p2[a] <= m; a++)
    for (int b = 0; p3[b] <= m; b++) if (a/mm[2]+b/mm[3] <= n)
    for (int c = 0; p5[c] <= m; c++) if (a/mm[2]+b/mm[3]+c/mm[5] <= n)
    for (int d = 0; p7[d] <= m; d++) if (a/mm[2]+b/mm[3]+c/mm[5]+d/mm[7] <= n)
    for (int e = 0; p11[e] <= m; e++) if (a/mm[2]+b/mm[3]+c/mm[5]+d/mm[7]+e/mm[11] <= n)
    for (int f = 0; p13[f] <= m; f++) if (a/mm[2]+b/mm[3]+c/mm[5]+d/mm[7]+e/mm[11]+f/mm[13] <= n)
        sextuples.pb({a, b, c, d, e, f});
        if (p2[a])
    }

    

    for (int i = 0; i < n; i++) {
        for (auto [A, B, C, D, E, F] : sextuples) {
            for (auto [a, b, c, d, e, f] : one_elt) {
                dp[i+1][A+a][B+b][C+c][D+d][E+e][F+f] += dp[i][A][B][C][D][E][F];
            }
        }
    }

    for (auto [A, B, C, D, E, F] : sextuples) {
        for (int a = A; a <= 4; a++)
        for (int b = B; b <= 8; b++) 
        for (int c = C; c <= 16; c++) 
        for (int d = D; d <= 16; d++) 
        for (int e = E; e <= 16; e++) 
        for (int f = F; f <= 16; f++)
        if (4*a+2*b+c+d+e+f <= 16) {
            ans += sum_dp[a][b][c][d][e][f];
        }
    }

    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
