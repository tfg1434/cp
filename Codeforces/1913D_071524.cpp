#include <bits/stdc++.h>
using namespace std;
const int inf = 2e9;

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

// int n;

// V<Z> t;
// vi buf;
// V<bool> touched;
// void push(int v, int len) {
    // touched[v] = true;
    // if (buf[v] != -1) {
        // t[v] = buf[v]*len;
        // if (len > 1) {
            // buf[2*v+1] = buf[v];
            // buf[2*v+2] = buf[v];
            // touched[2*v+1] = touched[2*v+2] = -1;
        // }
        // buf[v] = -1;
    // }
// }
// void pull(int v) {
    // t[v] = t[2*v+1]+t[2*v+2];
// }
// Z range_sum(int L, int R, int v=0, int l=0, int r=n) {
    // push(v, r-l);
    // if (r <= L || R <= l) return 0;
    // if (L <= l && r <= R) return t[v];
    // int m = (l+r)/2;
    // return range_sum(L, R, 2*v+1, l, m) + range_sum(L, R, 2*v+2, m, r);
// }
// void range_set(int L, int R, int x, int v=0, int l=0, int r=n) {
    // push(v, r-l);
    // if (r <= L || R <= l) return;
    // if (L <= l && r <= R) {
        // buf[v] = x;
        // push(v, r-l);
        // return;
    // }
    // int m = (l+r)/2;
    // range_set(L, R, x, 2*v+1, l, m);
    // range_set(L, R, x, 2*v+2, m, r);
    // pull(v);
// }
// void init_tree() {
    // int siz = 1;
    // while (siz < 2*n) siz *= 2;
    // t.resize(siz);
    // buf.assign(siz, -1);
    // touched.resize(siz);
// }
// void reset(int v) {
    // t[v] = 0;
    // buf[v] = -1;
    // touched[v] = false;
    // if (2*v+2 < t.size()) {
        // if (touched[2*v+1]) reset(2*v+1);
        // if (touched[2*v+2]) reset(2*v+2);
    // }
// }
// void print(int v, int l, int r) {
    // push(v, r-l);
    // if (2*v+2 < buf.size()) {
        // int m = (l+r)/2;
        // print(2*v+1, l, m);
        // print(2*v+2, m, r);
    // } else {
        // cout << t[v] << ' ';
    // }
    // if(!v) cout << '\n';
// }

void solve() {
    int n; cin >> n; 
    vi a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    V<Z> dp(n), pre_dp(n+1);
    Z ans = 0, sum_pts = 0;
    vi stk;
    for (int i = 0; i < n; i++) {
        while (stk.size() && a[stk.back()] > a[i]) {
            sum_pts -= dp[stk.back()];
            stk.pop_back();
        }

        // jump from i->j
        // Case 1. a[j] is the minimum
        dp[i] += pre_dp[i]-(stk.size() ? pre_dp[stk.back()+1] : 0);
        // Case 2 and 3, one is true
        // Case 2. a[i] is the minimum 
        if (stk.size()) dp[i] += sum_pts;
        // Case 3. i=-1
        if (!stk.size()) dp[i] += 1;

        stk.pb(i);
        sum_pts += dp[stk.back()];
        pre_dp[i+1] = pre_dp[i]+dp[i];
    }

    int cur_mn = inf;
    for (int i = n-1; i >= 0; i--) {
        if (a[i] < cur_mn) ans += dp[i];
        ckmin(cur_mn, a[i]);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
