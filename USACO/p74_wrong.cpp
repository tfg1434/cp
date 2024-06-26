// i assumed that the probability of each mask is equal after you fix the number of HIs and LOs. 
// It is not

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
const Z HALF = Z(2).inv();

const int N = 500;
Z ways[N+1][N+1], e[N+1][N+1][2], p[N+1][N+1][2];

Z f[N+1], C[N+1][N+1];

void solve() {
    f[0] = 1;
    for (int i = 1; i <= N; i++) f[i] = f[i-1]*i;
    C[0][0] = 1;
    for (int i = 1; i <= N; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i-1][j-1]+C[i-1][j];
        }
    }

    int n, x; cin >> n >> x;
    if (x == 0 || x == n) {
        cout << "0\n";
        return;
    }

    // ways[i][j] = hm length-i permutations with j prefix maximums
    ways[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            ways[i][j] = ways[i-1][j-1] + (i-1)*ways[i-1][j];
        }
    }

    // p[i][zeros][last] = P(my stepping process is in this state)
    p[1][1][0] = p[1][0][1] = HALF;
    for (int i = 2; i <= n; i++) for (int zeros = 0; zeros <= i; zeros++) {
        if (zeros > 0) p[i][zeros][0] = HALF*(p[i-1][zeros-1][0] + p[i-1][zeros-1][1]);
        if (zeros < i) p[i][zeros][1] = HALF*(p[i-1][zeros][0] + p[i-1][zeros][1]);
    }

    // e[i][zeros][last] = E(number of 10s if my stepping process is in this state)
    // since HI is 1 and LO is 0, it corresponds to HILOs
    for (int i = 2; i <= n; i++) for (int zeros = 0; zeros <= i; zeros++) {
        if (zeros > 0) {
            auto P = p[i-1][zeros-1][0] + p[i-1][zeros-1][1];
            e[i][zeros][0] = p[i-1][zeros-1][0]/P*e[i-1][zeros-1][0] + p[i-1][zeros-1][1]/P*(e[i-1][zeros-1][1]+1);
        }
        if (zeros < i) {
            auto P = p[i-1][zeros][0] + p[i-1][zeros][1];
            e[i][zeros][1] = p[i-1][zeros][0]/P*e[i-1][zeros][0] + p[i-1][zeros][1]/P*e[i-1][zeros][1];
        }
    }

    Z ans = 0;
    for (int l = 1; l <= x; l++) {
        for (int h = 1; h <= n-x; h++) {
            auto cnt = ways[x][l]*ways[n-x][h]*C[n][x];
            auto P = p[l+h][l][0] + p[l+h][l][1];
            auto p0 = p[l+h][l][0]/P;
            auto p1 = p[l+h][l][1]/P;
            ps(cnt, e[l+h][l][0]*p0 + e[l+h][l][1]*p1);
            ans += cnt * (e[l+h][l][0]*p0 + e[l+h][l][1]*p1);
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
