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
constexpr T pw(T a, i64 b) {
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
    
    const static i64 Mod = 998244353;
    constexpr static i64 getMod() {
        if (P > 0) {
            return P;
        } else {
            return Mod;
        }
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
        return pw(*this, getMod() - 2);
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
    friend constexpr istream &operator>>(istream &is, MInt &a) {
        i64 v {};
        is >> v;
        a = MInt(v);
        return is;
    }
    friend constexpr ostream &operator<<(ostream &os, const MInt &a) {
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
 
constexpr i64 mod = 1e9+7;
using Z = MInt<mod>;

// #pragma GCC target("bmi,bmi2,lzcnt,popcnt")
#define pct __builtin_popcount
constexpr int p2(int x) { return (int)1 << x; }
constexpr int msk2(int x) { return p2(x)-1; }
constexpr int bits(int x) { return x == 0 ? 0 : 31-__builtin_clz(x); } // floor(log2(x)) 

const int A = 1e6, L = 6;
const Z I2 = Z(2).inv();
Z dp1[A], dp2[A], dp[A];
int p10[6], freq[A];

void solve() {
    p10[0] = 1;
    for (int i = 1; i < L; i++) p10[i] = 10*p10[i-1];

    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        freq[x]++;
    }
    for (int a = 0; a < A; a++) {
        dp1[a] = a*freq[a];
        dp2[a] = a*dp1[a];
    }
    for (int i = 0; i < L; i++) {
        for (int a = A-1; a >= 0; a--) {
            if (a/p10[i]%10 < 9) {
                freq[a] += freq[a+p10[i]];
                dp1[a] += dp1[a+p10[i]];
                dp2[a] += dp2[a+p10[i]];
            } 
        }
    }

    for (int a = 0; a < A; a++) {
        dp[a] = (dp1[a]*dp1[a] + dp2[a])*pw(Z(2), freq[a])*I2*I2;  
    }
    // smarter way. without PIE
    // for (int i = 0; i < L; i++) {
        // for (int a = 0; a < A; a++) {
            // if (a/p10[i]%10 < 9) {
                // dp[a] -= dp[a+p10[i]];
            // }
        // }
    // }
    for (int a = 0; a < A; a++) {
        int bit[L], k = 0;
        for (int i = 0; i < L; i++) if (a/p10[i]%10 < 9)
            bit[k++] = i;

        for (int b = 1; b < p2(k); b++) {
            int A = a;
            for (int i = 0; i < k; i++) if (b & p2(i)) {
                A += p10[bit[i]];
            }
            int coef = pct(b)%2 ? -1 : 1;
            dp[a] += coef*dp[A];
        }
    }

    i64 ans = 0;
    for (i64 a = 0; a < A; a++) ans ^= a*(dp[a].val());
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
