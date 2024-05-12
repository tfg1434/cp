// it passes the first sample on my computer but not CF
// but i won't spend more hours debugging

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
using vb = V<bool>;
using vs = V<string>;

#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x) 
#define pb push_back
#define lb lower_bound
#define ub upper_bound
template<class T> int lwb(V<T>& a, const T& b) { return lb(all(a),b)-bg(a); }
template<class T> int upb(V<T>& a, const T& b) { return ub(all(a),b)-bg(a); }

using pt = complex<int>;
#define x real()
#define y imag()
template<class T> istream& operator>>(istream& in, complex<T>& o) {
    T X, Y; in >> X >> Y; o.real(X); o.imag(Y); return in;
}
template<class T> bool operator<(const complex<T>& a, const complex<T>& b) {
    if (a.x == b.x) return a.y < b.y;
    return a.x < b.x;
}

pt center;
bool cmp(pt a, pt b) {
    bool ctg_a = a < center;
    bool ctg_b = b < center;
    if (ctg_a != ctg_b) return ctg_a < ctg_b;
    auto A = a-center, B = b-center;
    if ((conj(A)*B).y != 0) return (conj(A)*B).y > 0;
    return norm(A) < norm(B);
}

int n, q;
V<pt> inp;
V<pair<pt, int>> groups;
vi ans;

int calc_ans_p1() {
    V<pair<pt, int>> groups;

    auto cd = [&](int i, int j) -> array<int, 2> {
        auto _ = conj(groups[i].f - center)*(groups[j].f - center);
        int cross = _.y;
        int dot = _.x;
        return {cross, dot};
    };

    {
        sort(all(inp), cmp);
        groups.pb({ inp[0], 1 });
        for (int i = 1; i < n; i++) {
            if ((conj(groups.back().f-center)*(inp[i]-center)).y == 0) {
                groups.back().s++;
            } else {
                groups.pb({inp[i], 1});
            }
        }
        groups.insert(end(groups), all(groups));
    }

    int res = 0;
    int j = 0;
    for (int i = 0; i < groups.size()/2; i++) {
        auto check = [&]() {
            auto [cross, dot] = cd(i, j);
            return (cross >= 0 && dot > 0);
        };

        while (j < groups.size() && check()) j++;
        assert(j < groups.size());

        auto [cross, dot] = cd(i, j);
        if (cross > 0 && dot == 0) res += groups[i].s*groups[j].s;
    } 
    return res;
}

vi calc_ans_p2(const V<pt>& query_points) {
    vi res(query_points.size());
    V<pair<pt, int>> mixed; // point, -1=inp point >=0: query index 
    for (pt p : inp) mixed.pb({p, -1});
    for (int i = 0; i < query_points.size(); i++) mixed.pb({query_points[i], i});

    for (pt CENTER : inp) { center = CENTER;
        V<tuple<pt, int, vi>> groups; // point, # regular points, inds of queries
        auto MIXED = mixed; mixed.erase(find(all(mixed), pair<pt, int>{center, -1}));

        sort(all(mixed), [&](pair<pt, int> m1, pair<pt, int> m2) {return cmp(m1.f, m2.f);});
        if (mixed[0].s == -1) {
            tuple<pt, int, vi> cpp = {mixed[0].f, 1, {}};
            groups.pb(cpp);
        } else {
            tuple<pt, int, vi> cpp = {mixed[0].f, 0, {mixed[0].s}};
            groups.pb(cpp);
        }
        for (int i = 1; i < mixed.size(); i++) {
            if ((conj(mixed[i].f-center)*(get<0>(groups.back()) - center)).y == 0) {
                if (mixed[i].s == -1) get<1>(groups.back())++;
                else get<2>(groups.back()).pb(mixed[i].s);
            } else {
                if (mixed[i].s == -1) {
                    tuple<pt, int, vi> cpp = {mixed[i].f, 1, {}};
                    groups.pb(cpp);
                } else {
                    tuple<pt, int, vi> cpp = {mixed[i].f, 0, {mixed[i].s}};
                    groups.pb(cpp);
                }
            }
        }

        // groups.insert(end(groups), all(groups));
        // for (auto g : groups) {
            // cout << get<0>(g) << ' ' << get<1>(g)<< endl;
        // }
        mixed = MIXED;

        { // A CCW rotation from query point to the other leg
            auto cd = [&](int i, int j) -> array<int, 2> {
                auto _ = conj(get<0>(groups[i]) - center)*(get<0>(groups[j]) - center);
                int cross = _.y;
                int dot = _.x;
                return {cross, dot};
            };
            int j = 0;
            for (int i = 0; i < groups.size()/2; i++) {
                auto check = [&]() {
                    auto [cross, dot] = cd(i, j);
                    return (cross >= 0 && dot > 0);
                };

                while (check()) {
                    j++;
                    assert(j < groups.size());
                }

                auto [cross, dot] = cd(i, j);
                if (cross > 0 && dot == 0) {
                    for (auto query_ind : get<2>(groups[i])) {
                        res[query_ind] += get<1>(groups[j])*get<1>(groups[j]);
                    }
                }
            }
        }
        { // A CW rotation from query point to the other leg
            auto cd = [&](int i, int j) -> array<int, 2> {
                auto _ = conj(get<0>(groups[i]) - center)*(get<0>(groups[j]) - center);
                int cross = _.y;
                int dot = _.x;
                return {cross, dot};
            };
            int j = groups.size()-1;
            for (int i = groups.size()-1; i >= groups.size()/2; i--) {
                auto check = [&]() {
                    auto [cross, dot] = cd(j, i);
                    return (cross >= 0 && dot > 0);
                };

                while (check()) j--;

                auto [cross, dot] = cd(j, i);
                if (cross > 0 && dot == 0) {
                    for (auto query_ind : get<2>(groups[i])) {
                        res[query_ind] += get<1>(groups[j])*get<1>(groups[j]);
                    }
                }
            }
        }
    }

    return res;
}

void solve() {
    cin >> n >> q;
    inp.resize(n);
    for (int i = 0; i < n; i++) cin >> inp[i];
    V<pt> query_points;
    while (q--) {
        cin >> center;
        query_points.pb(center);
        ans.pb(calc_ans_p1());
    }

    auto ans2 = calc_ans_p2(query_points);
    for (int i = 0; i < ans.size(); i++) cerr << ans[i] << " \n"[i==ans.size()-1];
    for (int i = 0; i < ans.size(); i++) cerr << ans2[i] << " \n"[i==ans.size()-1];
    for (int i = 0; i < ans.size(); i++) ans[i] += ans2[i], cout << ans[i] << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
