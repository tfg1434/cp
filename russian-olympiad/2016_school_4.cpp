// gets TLE... shouldn't be slower than the AC code
// devil TL

#pragma GCC optimize("Ofast,unroll-loops") 
#pragma GCC target("avx,avx2")

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
 
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

#define pct __builtin_popcount
constexpr int p2(int x) { return 1 << x; }

struct Batch {
    int b;
    i64 n;
    int m;
    bool operator<(const Batch& rhs) const {
        return m < rhs.m;
    }
    friend ostream& operator<<(ostream& out, const Batch& rhs) {
        out << rhs.b << ' ' << rhs.n << ' ' << rhs.m;
        return out;
    }
};

void solve() {
    int w, h, s, q; cin >> w >> h >> s >> q;
    V<array<int, 2>> base(s);
    for (int i = 0; i < s; i++) {
        int x, y; cin >> x >> y; x--; y--;
        base[i] = {x, y};
    }

    i64 N = 0;
    int t; cin >> t;
    V<Batch> batches(t);
    for (int i = 0; i < t; i++) {
        int b;
        i64 n;
        int m;
        cin >> b >> n >> m; b--;
        N += n;
        batches[i] = {b, n, m};
    }

    int k;
    i64 z;
    V<V<Batch>> batches_at_base;
    auto init_batches = [&](i64 robots) {
        batches_at_base.assign(s, V<Batch>());
        k = z = 0;
        while (robots > 0) {
            auto batch = batches[k];
            auto& [b, n, m] = batch;
            if (ckmin(n, robots)) {
                z = robots;
            } else {
                k++;
            }
            robots -= n;
            batches_at_base[b].pb(batch);
        }
    };

    pair<int, i64> ans;
    i64 lo = 0, hi = N + 1;
    while (hi-lo > 1) {
        i64 mi = (lo+hi)/2;
        init_batches(mi);

        V<V<i64>> num_robots(s);
        vi num_groups(4);
        for (int b = 0; b < s; b++) {
            sort(all(batches_at_base[b]));
            num_groups[b] = batches_at_base[b].size();
            num_robots[b].resize(batches_at_base[b].size()+1);
            for (int i = 0; i < batches_at_base[b].size(); i++) {
                num_robots[b][i+1] = num_robots[b][i] + batches_at_base[b][i].n;
            }
        }

        bool bad = false;
        for (int i0 = 0; i0 <= num_groups[0]; i0++) 
        for (int i1 = 0; i1 <= num_groups[1]; i1++) 
        for (int i2 = 0; i2 <= num_groups[2]; i2++) 
        for (int i3 = 0; i3 <= num_groups[3]; i3++) {
            vi ss = {i0, i1, i2, i3};

            auto intersect_area = [&](int msk, const vi& radii) -> i64 {
                int left = 0, right = w, bot = 0, top = h;
                for (int b = 0; b < s; b++) if (msk & p2(b)) {
                    int idx = ss[b]-1;
                    if (idx < 0) return 0;
                    ckmax(left, base[b][0]-radii[b]); 
                    ckmin(right, base[b][0]+radii[b]+1);
                    ckmax(bot, base[b][1]-radii[b]);
                    ckmin(top, base[b][1]+radii[b]+1);
                }
                if (left < right && bot < top) return (i64)(right-left)*(top-bot);
                else return 0;
            };

            vi radii(s);
            for (int b = 0; b < s; b++) {
                radii[b] = ss[b] ? batches_at_base[b][ss[b]-1].m : -1;
            }
            i64 ng = 0;
            for (int msk = 1; msk < p2(s); msk++) {
                int sign = (pct(msk) & 1) ? 1 : -1;
                ng += sign*intersect_area(msk, radii);
            }
            ng *= q;

            i64 robots = 0;
            for (int b = 0; b < s; b++) robots += num_robots[b][ss[b]];

            if (ng < robots) {
                bad = true;
                break;
            } 
        }

        if (bad) {
            hi = mi;
        } else {
            lo = mi;
            ans = {k, z};
        }
    }

    cout << ans.f << ' ' << ans.s << '\n';
}

void setIn(string s)  { freopen(s.c_str(),"r",stdin); }
void setOut(string s) { freopen(s.c_str(),"w",stdout); }
void setIO(string s = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (s.size() && fopen((s+".in").c_str(), "r")) setIn(s+".in"), setOut(s+".out");
}
 
signed main() {
    setIO("mining");
    solve();
    return 0;
}

