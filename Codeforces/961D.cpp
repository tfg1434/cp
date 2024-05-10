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

bool collinear(const vector<pt>& a) {
    if (a.size() < 3) return true;
    auto vec = make_vec(a[0], a[1]);
    for (int i = 2; i < a.size(); i++)
        if (cross(vec, make_vec(a[0], a[i]))) return false;
    return true;
}

int n;

void solve() {
    cin >> n;
    vector<pt> a(n);
    for (int i = 0; i < n; i++) cin >> a[i].x >> a[i].y;
    if (n < 3) {
        cout << "YES\n";
        return;
    }

    for (vector<int> inds : vector<vector<int>>{ {0, 1, 2}, {0, 1}, {1, 2}, {0, 2} }) {
        vector<pt> head;
        for (auto ind : inds) head.push_back(a[ind]);

        if (collinear(head)) {
            auto vec = make_vec(head[0], head[1]);
            vector<pt> rem;
            for (int i = 0; i < a.size(); i++) 
                if (cross(vec, make_vec(head[0], a[i])))
                    rem.push_back(a[i]);
            if (collinear(rem)) {
                cout << "YES\n";
                return;
            }
        } 
    }
    cout << "NO\n";
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();    
}
