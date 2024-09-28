#include <bits/stdc++.h>
using namespace std;
#define int int64_t
const int inf = 1e18;

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

const int N = 61;
constexpr int p2(int x) { return (int)1 << x; }

int ans = -inf;
V<array<int, 2>> segments;
vi cur_partition, price;
void rec(int i, int j) {
    if (!i) {        
        bool possible = true;
        int score = 0;
        int cnt[N];
        memset(cnt, 0, sizeof cnt);
        int appears = 0;

        int pos = 0;
        auto make_teams = [&](int l) {
            while (pos < cur_partition.size() && cur_partition[pos]-1 < l) {
                int x = cur_partition[pos++]-1;
                score += price[x];
                for (int i = 0; i <= x; i++) {
                    int tzs = __builtin_ctz(appears);
                    if (tzs <= x || !appears) {
                        possible = false;
                        return;
                    }
                    if (!(--cnt[tzs])) {
                        appears ^= p2(tzs);
                    }
                }
            }
        };
        for (auto [l, r] : segments) {
            make_teams(l);
            appears |= p2(r);
            cnt[r]++;
        }
        make_teams(inf);
        if (possible) {
            assert(pos == cur_partition.size());
            ckmax(ans, score);
        }

        return;
    }
    for (int k = j; k <= i; k++) {
        cur_partition.pb(k);
        rec(i-k, k);
        cur_partition.pop_back();
    }
}

void solve() {
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int l, r; cin >> l >> r; l--;
        segments.pb({l, r});
    }
    sort(all(segments));
    price.resize(n);
    for (int& i : price) cin >> i;
    rec(n, 1);

    if (ans == -inf) {
        cout << "impossible\n";
        return;
    }
    cout << ans << '\n';
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    solve();
    return 0;
}
