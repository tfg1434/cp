// #pragma GCC optimize("Ofast,unroll-loops")
// #pragma GCC target("avx,avx2")
#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int mod = 1e9+7;

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

template<typename T = int>
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
    
    Matrix<T> expo(int p) {
        assert(rows == cols);

        Matrix<T> a(*this);
        Matrix<T> ans(rows, cols);
        for (int i = 0; i < rows; ++i) {
            ans.mat[i][i] = 1;
        }

        while (p) {
            if (p & 1) ans *= a;
            p >>= 1;
            a *= a;
        }

        return ans;
    }

    Matrix operator += (const Matrix<T>& m) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                mat[i][j] = (mat[i][j] + m.mat[i][j]) % mod;
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
                    T t = mat[i][k] * m.mat[k][j] % mod;
                    nmat[i][j] += t;
                    if (nmat[i][j] >= mod) nmat[i][j] -= mod;
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

const int max_n = 100, max_m = 4950;
int n, m, k, t, e[max_m][2], deg[max_n];
int pw(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b%2) res = res*a%mod;
        b /= 2;
        a = a*a%mod;
    }
    return res;
}
int inv(int a) { return pw(a, mod-2); }

void solve() {
    cin >> n >> m >> k >> t;
    Matrix<int> adj(n, n);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v; u--; v--;
        deg[u]++; deg[v]++;
        e[i][0] = u; e[i][1] = v;
    }
    for (int i = 0; i < m; i++) {
        auto [u, v] = e[i];
        adj.mat[u][v] = inv(deg[v]);
        adj.mat[v][u] = inv(deg[u]);
    }
    Matrix<int> cnt(n, 1);
    for (int i = 0; i < k; i++) {
        int p; cin >> p; p--; cnt.mat[p][0]++;
    }

    cnt = adj.expo(t)*cnt;
    for (int i = 0; i < n; i++) cout << cnt(i, 0) << " \n"[i==n-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
