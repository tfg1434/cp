#include <bits/stdc++.h>

using namespace std;

#define int int64_t
#define pt pair<int, int>
#define x first
#define y second

const int inf = 2e18;
const double eps = 1e-12;
const double PI = acos(-1.0);

pt make_vec(const pt& a, const pt& b) {
    return {b.x - a.x, b.y - a.y};
}
int dot(const pt& a, const pt& b) {
    return a.x * b.x + a.y * b.y;
}
int cross(const pt& a, const pt& b) {
    return a.x * b.y - a.y * b.x;
}
int sq_length(const pt& a) {
    return a.x * a.x + a.y * a.y;
}
pt operator-(const pt& a) {
    return {-a.x, -a.y};
}
pt operator+(const pt& a, const pt& b) {
    return {a.x+b.x, a.y+b.y};
}
pt operator-(const pt& a, const pt& b) {
    return {a.x-b.x, a.y-b.y};
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    vector<pt> a(3);
    for (int i = 0; i < 3; i++) cin >> a[i].x >> a[i].y;
    if (cross(make_vec(a[0], a[1]), make_vec(a[1], a[2])) < 0)
        reverse(begin(a), end(a));
    vector<pt> s(5);
    for (int i = 0; i < 5; i++) s[i] = make_vec(a[i%3], a[(i+1)%3]);

    cout << 3 << '\n';
    for (int side_to_add = 0; side_to_add < 3; side_to_add++) {
        pt dest = a[side_to_add] - s[side_to_add+1];
        cout << dest.x << ' ' << dest.y << '\n';
    }
}
