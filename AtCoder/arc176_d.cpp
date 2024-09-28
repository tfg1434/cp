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
 
struct Comb {
    int n;
    std::vector<Z> _fac;
    std::vector<Z> _invfac;
    std::vector<Z> _inv;
    
    Comb() : n{0}, _fac{1}, _invfac{1}, _inv{0} {}
    Comb(int n) : Comb() {
        init(n);
    }
    
    void init(int m) {
        m = std::min<i64>(m, Z::getMod() - 1);
        if (m <= n) return;
        _fac.resize(m + 1);
        _invfac.resize(m + 1);
        _inv.resize(m + 1);
        
        for (int i = n + 1; i <= m; i++) {
            _fac[i] = _fac[i - 1] * i;
        }
        _invfac[m] = _fac[m].inv();
        for (int i = m; i > n; i--) {
            _invfac[i - 1] = _invfac[i] * i;
            _inv[i] = _invfac[i] * _fac[i - 1];
        }
        n = m;
    }
    
    Z fac(int m) {
        if (m > n) init(2 * m);
        return _fac[m];
    }
    Z invfac(int m) {
        if (m > n) init(2 * m);
        return _invfac[m];
    }
    Z inv(int m) {
        if (m > n) init(2 * m);
        return _inv[m];
    }
    Z binom(int n, int m) {
        if (n < m || m < 0) return 0;
        return fac(n) * invfac(m) * invfac(n - m);
    }
} comb;

template<class T>
vector<vector<T>> multi(vector<vector<T>> &a,vector<vector<T>> &b){
  vector<vector<T>> c(a.size(),vector<T>(b[0].size()));
  for(int i=0;i<int(a.size());i++){
    for(int j=0;j<int(b.size());j++){
      for(int k=0;k<int(b[0].size());k++){
        c[i][k]+=a[i][j]*b[j][k];
      }
    }
  }
  return c;
}
template<class T>
vector<vector<T>> mul_exp(vector<vector<T>> adj, int k){
  if (k == 1) return adj;
  vector<vector<T>> res(int(adj.size()),vector<T>(int(adj[0].size())));
  for(int i=0;i<int(adj.size());i++){
    res[i][i]=1;
  }
  while(k>0){
    if(k&1) res=multi(adj,res);
    adj=multi(adj,adj);
    k/=2;
  }
  return res;
}

void solve() {
    int n, m; cin >> n >> m;
    vi p(n);
    for (int& i : p) cin >> i, i--;

    V<array<Z, 3>> res(n-1);
    for (int k = 0; k < n-1; k++) {
        int x = k+1;
        int y = n-x;
        V<V<Z>> mat = {{
            {comb.binom(n-2,2)+2*(x-2)+1, x-1, 0},
            {2*y, comb.binom(n-2, 2)+(x-1)+(y-1)+1, 2*x},
            {0, y-1, comb.binom(n-2, 2)+2*(y-2)+1}
        }};
        mat = mul_exp(mat, m);
        for (int i = 0; i < 3; i++) {
            res[k][i] = mat[1][i];
        }
    }

    // cnt[typ][k] = for this k, how many adj pairs are of such type
    vector cnt(3, vi(n));
    for (int i = 0; i+1 < n; i++) {
        int lo = min(p[i], p[i+1]);
        int hi = max(p[i], p[i+1]);
        // cnt[0][hi,n-1]++;
        cnt[0][hi]++;
        // cnt[1][lo,hi]++;
        cnt[1][lo]++;
        cnt[1][hi]--;
        // cnt[2][0,lo]++;
        cnt[2][0]++;
        cnt[2][lo]--;
    }
    for (int typ = 0; typ < 3; typ++) {
        for (int k = 0; k < n-2; k++) {
            cnt[typ][k+1] += cnt[typ][k];
        }
    }

    Z ans = 0;
    for (int k = 0; k < n-1; k++) {
        for (int typ = 0; typ < 3; typ++) {
            ans += cnt[typ][k]*res[k][typ];
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
