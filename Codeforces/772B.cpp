#include <bits/stdc++.h>

using namespace std;

#define int int64_t

const int inf = 2e18;
const double eps = 1e-12;
const double PI = acos(-1.0);

template<class T>
struct pt {
    T x, y;
    pt() { x = 0, y = 0; }
    pt(T x, T y): x(x), y(y) {}
    pt& operator+=(const pt &t) {
        x += t.x;
        y += t.y;
        return *this;
    }
    pt& operator-=(const pt &t) {
        x -= t.x;
        y -= t.y;
        return *this;
    }
    pt& operator*=(T t) {
        x *= t;
        y *= t;
        return *this;
    }
    pt& operator/=(T t) {
        x /= t;
        y /= t;
        return *this;
    }
    pt operator+(const pt &t) const {
        return pt(*this) += t;
    }
    pt operator-(const pt &t) const {
        return pt(*this) -= t;
    }
    pt operator*(T t) const {
        return pt(*this) *= t;
    }
    pt operator/(T t) const {
        return pt(*this) /= t;
    }
    bool operator ==(const pt<T>& o) const {
        return x == o.x && y == o.y;
    }
    template<class U = T> typename enable_if<is_same<U, double>::value, bool>::type operator ==(const pt<T>&o) {
        return abs(x-o.x) < eps && abs(y-o.y) < eps;
    }
};
template<class T> pt<T> operator*(T a, pt<T> b) {
    return b*a;
} 
template<class T> istream& operator >>(istream& in, pt<T>& o) {
    in >> o.x >> o.y;
    return in;
}
template<class T> pt<T> make_vec(pt<T> a, pt<T> b) {
    return {b.x - a.x, b.y - a.y};
}
template<class T>
T square_dist(pt<T> a, pt<T> b) {
    return abs(b.x-a.x)*abs(b.x-a.x) + abs(b.y-a.y)*abs(b.y-a.y);
}

template<class T> T dot(const pt<T>& a, const pt<T>& b) {
    return a.x*b.x + a.y*b.y;
}
template<class T> T norm(const pt<T>& a) {
    return a.x*a.x + a.y*a.y;
}
template<class T> double abs(const pt<T>& a) {
    return sqrt(norm(a));
}
template<class T> T proj(const pt<T>& a, const pt<T>& b) {
    return dot(a, b) / abs(b);
}
template<class T> T proj_h(const pt<T>& a, const pt<T>& b) {
    return abs(a - b/abs(b)*proj(a, b));
}

int n;

void solve() {
    cin >> n;
    vector<pt<double>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    reverse(begin(a), end(a));
    a.push_back(a[0]);
    a.push_back(a[1]);
    // cerr << proj_h(make_vec(a[0], a[1]), make_vec(a[0], a[2])) << endl;

    double D = 2e18;
    for (int i = 0; i < n; i++) {
        auto vec = make_vec(a[i], a[i+1]);
        auto skip_vec = make_vec(a[i], a[i+2]);
        D = min(D, proj_h(vec, skip_vec)/2);
    }

    cout << fixed << setprecision(6) << D << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();    
}
