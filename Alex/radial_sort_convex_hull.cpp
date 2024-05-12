#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "algo/debug.h"
#endif

#define f first
#define s second
template<class T> using V = vector<T>; 
using vi = V<int>;
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

struct pt {
    int x, y;
    pt() { x = 0, y = 0; }
    pt(int x, int y): x(x), y(y) {}
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
    pt& operator*=(int t) {
        x *= t;
        y *= t;
        return *this;
    }
    pt& operator/=(int t) {
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
    pt operator*(int t) const {
        return pt(*this) *= t;
    }
    pt operator/(int t) const {
        return pt(*this) /= t;
    }
    bool operator <(const pt& o) const {
        if (x == o.x) return y < o.y;
        return x < o.x && y == o.y;
    }
    bool operator ==(const pt& o) const {
        return x == o.x && y == o.y;
    }
    friend ostream& operator <<(ostream& out, const pt& o) {
        return out << o.x << ' ' << o.y; 
    }
};
pt make_vec(const pt& a, const pt& b) {
    return b-a;
}
int cross(const pt& a, const pt& b) {
    return a.x*b.y - a.y*b.x;
}
int norm(const pt& a) {
    return a.x*a.x+a.y*a.y;
}

pt radial_source;
bool cmp(const pt& a, const pt& b) {
    bool ctg_a = a < radial_source;
    bool ctg_b = b < radial_source;
    if (ctg_a != ctg_b) return ctg_a < ctg_b;

    auto A = make_vec(radial_source, a);
    auto B = make_vec(radial_source, b);
    if (cross(A, B) == 0) return norm(A) < norm(B);
    return cross(A, B) > 0;
}

void convex_hull(vector<pt> a, vector<pt>& ch) {
    int n = a.size();
    radial_source = *min_element(all(a));
    sort(all(a), cmp);
    ps(a);
    ch.clear();
    for (int i = 0; i < n; i++) {
        while (ch.size() > 1 && cross(make_vec(ch[ch.size()-2], ch.back()), make_vec(ch.back(), a[i])) < 0) {
            ch.pop_back();
        }
        ch.push_back(a[i]);
    }
}

void solve() {
    V<pt> points {{0, 0}, {2, 2}, {0, 2}, {2, 0}, {1, 1}};
    vector<pt> ch;
    convex_hull(points, ch);
    ps(ch);
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
