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

const int max_n = 30;
int g[max_n][max_n];
int n;

vi best;
vi chosen;
bool is_chosen[max_n];
int covered_mask;
unordered_map<int, int> memo;

void rec(int i) {
    if (best.size() <= chosen.size()) return;
    if (memo.find(covered_mask) != end(memo) && memo[covered_mask] < chosen.size()) return;
    memo[covered_mask] = chosen.size();

    if (i == n) {
        best = chosen;
        return;
    }

    bool ok = true;
    for (int j = 0; j <= i; j++) {
        bool is_covered = false;
        for (int k = 0; k < i; k++) {
            if (is_chosen[k] && g[j][k]) {
                is_covered = true;
                break;
            }
        }
        if (is_covered) continue;
        bool can_be_covered = false;
        for (int k = i+1; k < n; k++) {
            if (g[j][k]) {
                can_be_covered = true;
                break;
            }
        }
        if (can_be_covered) continue;
        ok = false;
        break;
    }
    if (ok) rec(i+1);

    chosen.push_back(i);
    is_chosen[i] = true;
    auto COVERED_MASK = covered_mask;
    for (int j = 0; j < n; j++) if (g[i][j]) covered_mask |= (1 << j);
    rec(i+1);
    covered_mask = COVERED_MASK;
    is_chosen[i] = false;
    chosen.pop_back();
}

void solve() {
    int r;
    cin >> n >> r;
    vi xs(n), ys(n);
    for (int i = 0; i < n; i++) cin >> xs[i] >> ys[i];
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        g[i][j] = (xs[i]-xs[j])*(xs[i]-xs[j]) +
                  (ys[i]-ys[j])*(ys[i]-ys[j]) <= r*r;
    }
    best.resize(n); iota(all(best), 0);
    rec(0);
    cout << best.size() << '\n';
    for (int i = 0; i < best.size(); i++) cout << best[i]+1 << " \n"[i==best.size()-1];
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
