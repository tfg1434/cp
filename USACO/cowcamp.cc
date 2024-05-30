#include <bits/stdc++.h>
using namespace std;
using db = long double;

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

template<typename T = db>
struct Matrix {
    V<V<T>> mat;
    int rows, cols;
    Matrix() {}
    Matrix(int rows, int cols) : rows(rows), cols(cols) {
        mat = V<V<T>>(rows, V<T>(cols));
    }
    Matrix(V<V<T>> mat) : mat(mat) {
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
                mat[i][j] = mat[i][j] + m.mat[i][j];
            }
        }
        return *this;
    }
    Matrix<T> operator *= (const Matrix<T>& m) {
        assert(cols == m.rows);
        cols = m.cols;
        V<V<T>> nmat(rows, V<T>(cols, 0));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                for (int k = 0; k < m.rows; ++k) {
                    T t = mat[i][k] * m.mat[k][j];
                    nmat[i][j] = nmat[i][j] + t;
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

const int max_t = 1000;
db C[max_t][max_t];
db p2[max_t];
void init() {
    p2[0] = 1;
    for (int i = 1; i < max_t; i++) p2[i] = p2[i-1]*2;
    C[0][0] = 1;
    for (int i = 1; i < max_t; i++) {
        C[i][0] = C[i][i] = 1;
        for (int j = 1; j < i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }
    for (int i = 1; i < max_t; i++) {
        for (int j = 0; j < i; j++) {
            C[i][j+1] += C[i][j];
        }
    }
}
int t, k;

void solve() {
    init();
    cin >> t >> k; t--; 

    Matrix<db> p(2, 2), q(2, 1);
    q.mat[1][0] = 1;
    while (k > 0) {
        auto last = q(0, 0);
        auto A = C[t][(int)min((db)t, last)];
        auto B = 0.0;
        if (last < (db)t) {
            B = C[t-1][t-1]-((int)last > 0 ? C[t-1][(int)last-1] : 0);
        }
        p = Matrix<db>(
                {{ A/p2[t], B/p2[t]*t },
                {0, 1}});

        int lo = 0, hi = k;
        while (hi-lo > 1) {
            int m = (lo+hi)/2;
            auto Q = p.expo(m)*q;
            floor(Q(0, 0)) == floor(q(0, 0)) ? lo = m : hi = m;
        }
        q = p.expo(hi)*q;
        k -= hi;
    }

    cout << fixed << setprecision(6) << q(0, 0)+1 << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
