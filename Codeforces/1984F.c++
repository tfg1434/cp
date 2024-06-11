// ecnerwala O(n lg n) solution
// Idea -- updates only affect a single sum, we need to somehow propagate
// the new sum update to the rest of the tree quickly
// Tools -- segment tree of matrices, sweeping line

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
 
constexpr i64 mod = 998244353;
using Z = MInt<mod>;

template<typename T = Z>
struct Matrix {
    vector<vector<T>> mat;
    int rows, cols;
    Matrix() {}
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        mat = vector<vector<T>>(rows, vector<T>(cols));
    }
    Matrix(vector<vector<T>> mat) : mat(mat) {
        rows = mat.size();
        cols = (rows > 0) ? mat[0].size() : 0;
    }
    Matrix(const Matrix<T>& m) : Matrix(m.mat) {}
    Matrix operator += (const Matrix<T>& m) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] += m.mat[i][j];
            }
        }
        return *this;
    }
    Matrix<T> operator *= (const Matrix<T>& m) {
        assert(cols == m.rows);
        cols = m.cols;
        vector<vector<T>> nmat(rows, vector<T>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                for (int k = 0; k < m.rows; ++k) {
                    nmat[i][j] += mat[i][k]*m.mat[k][j];
                }
            }
        }
        mat = nmat;
        return *this;
    }
    Matrix<T> operator + (const Matrix<T>& m) {
        Matrix<T> mtx(*this); mtx += m;
        return mtx;
    }
    Matrix<T> operator * (const Matrix<T>& m) {
        Matrix<T> mtx(*this); mtx *= m;
        return mtx;
    }
    T operator () (int row, int col) {
        return mat[row][col];
    }
    friend ostream& operator << (ostream& out, const Matrix<T>& m) {
        for (int i = 0; i < m.rows; ++i) {
            for (int j = 0; j < m.cols; ++j) out << m.mat[i][j] << " ";
            if (i != m.rows-1) out << "\n";
        }
        return out;
    }
};

int n, m;

V<Matrix<>> t;
void build(int v, int l, int r, const vi& b, const string& s) {
    if (l == r-1) {
        bool transition = abs(b[l]-b[l-1])<=m;
        t[v] = Matrix<>({
                { transition && (s[l] == 'P' || s[l] == '?'), 0 },
                { 0, transition && (s[l] == 'S' || s[l] == '?') }
                });
        return;
    }
    int m = (l+r)/2;
    build(2*v+1, l, m, b, s);
    build(2*v+2, m, r, b, s);
    t[v] = t[2*v+1]*t[2*v+2];
}
void init_tree(const vi& b, const string& s) {
    int size = 1; 
    while (size < 2*n) size *= 2;
    t.resize(size);
    build(0, 1, n, b, s);
}
void point_set(int v, int l, int r, int i, int row, int col, bool transition) {
    if (l == r-1) {
        t[v].mat[row][col] = transition;
        return;
    }
    int m = (l+r)/2;
    if (i < m) point_set(2*v+1, l, m, i, row, col, transition);
    else point_set(2*v+2, m, r, i, row, col, transition);
    t[v] = t[2*v+2]*t[2*v+1];
}
void point_set(int i, int row, int col, bool transition) { point_set(0, 1, n, i, row, col, transition); }

void solve() {
    cin >> n >> m; n += 2;
    string s; cin >> s; s = "P"+s+"S";
    vi b(n); b[0] = b[n-1] = 0;
    for (int i = 1; i < n-1; i++) cin >> b[i];
    init_tree(b, s);

    map<int, V<pair<bool, array<int, 3>>>> events;
    for (int i = 1; i < n; i++) {
        if ((s[i-1] == 'P' || s[i-1] == '?') && (s[i] == 'S' || s[i] == '?')) {
            events[b[i-1]+b[i]].pb({1, {i, 1, 0}});
            events[b[i-1]+b[i]+1].pb({0, {i, 1, 0}});
        }
        if ((s[i-1] == 'S' || s[i-1] == '?') && (s[i] == 'P' || s[i] == '?')) {
            events[b[i-1]+b[i]-2*m].pb({1, {i, 0, 1}});
            events[b[i-1]+b[i]+2*m+1].pb({0, {i, 0, 1}});
        }
    }

    auto base = Matrix<>(2, 1);
    base.mat[0][0] = 1;
    base.mat[1][0] = 0;
    Z ans = 0;
    for (auto [sum, changes] : events) {
        for (auto [transition, info] : changes) {
            point_set(info[0], info[1], info[2], transition);
        }
        ans += (t[0]*base)(1, 0);
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int tc; cin >> tc; while (tc--) solve();
    return 0;
}
