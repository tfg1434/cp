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

int dot_prod(const pt& a, const pt& b) {
    return a.x * b.x + a.y * b.y;
}

int cross_prod(const pt& a, const pt& b) {
    return a.x * b.y - a.y * b.x;
}

int sq_length(const pt& a) {
    return a.x * a.x + a.y * a.y;
}

pt operator-(const pt& a) {
    return {-a.x, -a.y};
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    int asdfasdfasdf;
    cin >> asdfasdfasdf;
    int n;
    cin >> n;
    vector<array<pt, 3>> a(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            cin >> a[i][j].x >> a[i][j].y;
        }
    }
    for (int i = 0; i < n; i++) {
        if (cross_prod(make_vec(a[i][0], a[i][1]), make_vec(a[i][1], a[i][2])) < 0) {
            reverse(a[i].begin(), a[i].end());
        }
    }
    vector<array<pt, 6>> s(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) {
            s[i][j] = make_vec(a[i][j % 3], a[i][(j + 1) % 3]);
        }
    }

    vector<array<double, 5>> ang(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 5; j++) {
            ang[i][j] = atan2(cross_prod(s[i][j + 1], -s[i][j]), dot_prod(s[i][j + 1], -s[i][j]));
        }
    }

    set<array<int, 4>> ans;
    for (int c = 0; c < n; c++) {
        for (int i = 0; i < n; i++) {
            if (i == c) {
                continue;
            }
            for (int oi = 0; oi < 3; oi++) {
                if (sq_length(s[i][oi]) != sq_length(s[c][0])) {
                    continue;
                }
                for (int j = 0; j < n; j++) {
                    if (j == c || j == i) {
                        continue;
                    }
                    for (int oj = 0; oj < 3; oj++) {
                        if (sq_length(s[j][oj]) != sq_length(s[c][1])) {
                            continue;
                        }
                        for (int k = 0; k < n; k++) {
                            if (k == c || k == i || k == j) {
                                continue;
                            }
                            for (int ok = 0; ok < 3; ok++) {
                                if (sq_length(s[k][ok]) != sq_length(s[c][2])) {
                                    continue;
                                }

                                if (abs(ang[c][2] + ang[i][oi] + ang[k][ok + 2] - PI) > eps) {
                                    continue;
                                }
                                if (abs(ang[c][0] + ang[i][oi + 2] + ang[j][oj] - PI) > eps) {
                                    continue;
                                }
                                if (abs(ang[c][1] + ang[j][oj+2] + ang[k][ok] - PI) > eps) {
                                    continue;
                                }
                                array<int, 4> cur = {c, i, j, k};
                                sort(cur.begin(), cur.end());
                                ans.insert(cur);
                            }
                        }
                    }
                }
            }
        }
    }
    cout << ans.size() << '\n';
    for (auto cur: ans) {
        for (int i = 0; i < 4; i++) {
            cout << cur[i] + 1 << ' ';
        }
        cout << '\n';
    }
}
