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
template<class T>
istream& operator >>(istream& in, pt<T>& o) {
    in >> o.x >> o.y;
    return in;
}
template<class T>
pt<T> make_vec(pt<T> a, pt<T> b) {
    return {b.x - a.x, b.y - a.y};
}
template<class T>
T square_dist(pt<T> a, pt<T> b) {
    return abs(b.x-a.x)*abs(b.x-a.x) + abs(b.y-a.y)*abs(b.y-a.y);
}
template<class T>
bool cmp(const pt<T>&x, const pt<T>& y) {
    if (x.x == y.x) return x.y < y.y;
    return x.x < y.x;
}
struct chash {
    const static int mod = 1e9+9;
    const static int base = 9973;
    size_t operator()(const pt<int>& o) const {
        return (o.x*base+o.y)%mod;
    }
};

int n;

void solve() {
    cin >> n;
    vector<pt<int>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    unordered_map<pt<int>, int, chash> cnt;
    for (int i = 0; i < n; i++) for (int j = i+1; j < n; j++) {
        cnt[a[i]+a[j]]++;
    }
    int ans = 0;
    for (auto [center, cnt] : cnt) {
        ans += cnt*(cnt-1)/2;
    }

    cout << ans << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();    
}
